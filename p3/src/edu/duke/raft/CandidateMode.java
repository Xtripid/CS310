package edu.duke.raft;
import java.util.*;

public class CandidateMode extends RaftMode {

    Random rand = new Random();
    Timer pollVoteTimer = new Timer();
    Timer electionTimer = new Timer();

    int pollVoteID;
    int electionID;
    boolean timeoutOverride = false;

    public void resetElectionTimer() {
        if (timeoutOverride) {
            electionTimer = scheduleTimer(mConfig.getTimeoutOverride(), electionID);
        } else {
            electionTimer = scheduleTimer(rand.nextInt(150) + 150, electionID);
        }
    }

    public void resetPollVoteTimer() {
        pollVoteTimer = scheduleTimer(90, pollVoteID);
    }

    public void go() {
        synchronized(mLock) {

            mConfig.setCurrentTerm(mConfig.getCurrentTerm() + 1, mID);

            int currentTerm = mConfig.getCurrentTerm();
            System.out.println("S" + mID + "." + mConfig.getCurrentTerm() + ": switched to candidate mode.");


            // System.out.println("candidate " + mID + " current term: " + currentTerm);

            electionID = 13 * mID * currentTerm;
            pollVoteID = 11 * mID * currentTerm;

            if (mConfig.getTimeoutOverride() > 0) {
                timeoutOverride = true;
            }

            RaftResponses.setTerm(currentTerm);

            RaftResponses.clearVotes(currentTerm);

            for (int i = 1; i <= mConfig.getNumServers(); i++) {
                remoteRequestVote(i, currentTerm, mID, mLog.getLastIndex(), mLog.getLastTerm());
            }

            resetElectionTimer();
            resetPollVoteTimer();

        }
    }

    public int requestVote(int candidateTerm, int candidateID, int lastLogIndex, int lastLogTerm) {
        synchronized(mLock) {
            int currentTerm = mConfig.getCurrentTerm();

            if (candidateID == mID) {
                return 0;
            }

            if (candidateTerm < currentTerm) {
                return currentTerm;
            }

            if (candidateTerm > currentTerm) {
                if (lastLogTerm >= mLog.getLastTerm()) {
                    mConfig.setCurrentTerm(candidateTerm, candidateID);
                    electionTimer.cancel();
                    pollVoteTimer.cancel();
                    RaftServerImpl.setMode(new FollowerMode());

                    return currentTerm;
                } else {
                    mConfig.setCurrentTerm(candidateTerm, 0);
                    electionTimer.cancel();
                    pollVoteTimer.cancel();
                    RaftServerImpl.setMode(new FollowerMode());

                    return currentTerm;
                }
            } else {
                if (lastLogTerm >= mLog.getLastTerm()) {
                    electionTimer.cancel();
                    pollVoteTimer.cancel();
                    RaftServerImpl.setMode(new FollowerMode());

                    return currentTerm;
                } else {
                    electionTimer.cancel();
                    pollVoteTimer.cancel();
                    resetElectionTimer();
                    resetPollVoteTimer();
                    return currentTerm;
                }
            }
        }
    }

    public int appendEntries(int leaderTerm, int leaderID, int prevLogIndex, int prevLogTerm, Entry[] entries, int leaderCommit) {
        synchronized(mLock) {
            int currentTerm = mConfig.getCurrentTerm();
            if (leaderTerm < currentTerm) {
                return currentTerm;
            } else {
                mConfig.setCurrentTerm(leaderTerm, 0);
                electionTimer.cancel();
                pollVoteTimer.cancel();
                RaftServerImpl.setMode(new FollowerMode());

                return 0;
            }
        }
    }

    public void handleTimeout(int timerID) {
        synchronized(mLock) {
            if (timerID == 13 * mID * mConfig.getCurrentTerm()) {
                electionTimer.cancel();
                pollVoteTimer.cancel();
                RaftServerImpl.setMode(new CandidateMode());
                return;
            }
            if (timerID == 11 * mID * mConfig.getCurrentTerm()) {
                int currentTerm = mConfig.getCurrentTerm();
                int[] votes = RaftResponses.getVotes(currentTerm);

                int numVotes = 0;
                for (int i = 1; i < votes.length; i++) {
                    if (votes[i] == 0) {
                        numVotes++;
                    }
                }

                if (numVotes > mConfig.getNumServers() / 2) {
                    electionTimer.cancel();
                    pollVoteTimer.cancel();
                    RaftServerImpl.setMode(new LeaderMode());
                } else {
                    RaftResponses.clearVotes(currentTerm);

                    for (int i = 0; i <= mConfig.getNumServers(); i++) {
                        remoteRequestVote(i, currentTerm, mID, mLog.getLastIndex(), mLog.getLastTerm());
                    }

                    pollVoteTimer.cancel();
                    resetPollVoteTimer();
                }
            }
        }
    }
}
