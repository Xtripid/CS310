package edu.duke.raft;
import java.util.*;

public class FollowerMode extends RaftMode {

    Random rand = new Random();
    Timer electionTimer = new Timer();

    boolean timeoutOverride = false;
    int electionID;

    public void resetTimer() {
        if (timeoutOverride) {
            electionTimer = scheduleTimer(mConfig.getTimeoutOverride(), electionID);
        } else {
            electionTimer = scheduleTimer(rand.nextInt(150) + 150, electionID);
        }
    }

    public void go() {
        synchronized(mLock) {
            int currentTerm = mConfig.getCurrentTerm();
            System.out.println("S" + mID + "." + currentTerm + ": switched to follower mode.");

            electionID = 17 * mID * currentTerm;
            electionTimer.cancel();

            if (mConfig.getTimeoutOverride() > 0) {
                timeoutOverride = true;
            }

            resetTimer();
        }
    }

    public int requestVote(int candidateTerm, int candidateID, int lastLogIndex, int lastLogTerm) {
         synchronized(mLock) {
            //  System.out.println("--- Follower " + mID +  " Request Vote ---");
             int currentTerm = mConfig.getCurrentTerm();
             if (candidateTerm < currentTerm) {
                //  System.out.println("Vote No 1 Server: " + mID);
                 return currentTerm;
             }

             if (candidateTerm > currentTerm) {
                 if (lastLogTerm >= mLog.getLastTerm()) {
                     electionTimer.cancel();
                     mConfig.setCurrentTerm(candidateTerm, candidateID);
                     resetTimer();

                     return 0;
                 } else {
                     electionTimer.cancel();
                     mConfig.setCurrentTerm(candidateTerm, 0);
                     resetTimer();

                     return currentTerm;
                 }
             }

             int votedFor = mConfig.getVotedFor();
            //  System.out.println("Server " + mID + " Voted For " + votedFor);
             if (votedFor == 0 || votedFor == candidateID) {
                 if (lastLogTerm > mLog.getLastTerm()) {
                     electionTimer.cancel();
                     mConfig.setCurrentTerm(candidateTerm, candidateID);
                     resetTimer();
                    //  System.out.println("Vote Yes Server: " + mID);

                     return 0;
                 } else if (lastLogTerm == mLog.getLastTerm()) {
                     if (lastLogIndex >= mLog.getLastIndex()) {
                         electionTimer.cancel();
                         mConfig.setCurrentTerm(candidateTerm, candidateID);
                         resetTimer();
                        //  System.out.println("Vote Yes Server: " + mID);

                         return 0;
                     } else {
                         electionTimer.cancel();
                         resetTimer();
                        //  System.out.println("Vote No 2 Server: " + mID);

                         return currentTerm;
                     }
                 } else {
                     electionTimer.cancel();
                     resetTimer();
                    //  System.out.println("Vote No 3 Server: " + mID);

                     return currentTerm;
                 }
             }
            //  System.out.println("Vote No 4 Server: " + mID);

             return currentTerm;
         }
    }

    public int appendEntries(int leaderTerm, int leaderID, int prevLogIndex, int prevLogTerm, Entry[] entries, int leaderCommit) {
        synchronized(mLock) {
            int currentTerm = mConfig.getCurrentTerm();

            if (leaderTerm < currentTerm) {
                return currentTerm;
            }

            mConfig.setCurrentTerm(leaderTerm, 0);
            mLog.insert(entries, -1, -1);

            if (leaderCommit > mCommitIndex) {
                if (leaderCommit > mLog.getLastIndex()) {
                    mCommitIndex = mLog.getLastIndex();
                } else {
                    mCommitIndex = leaderCommit;
                }
            }

            electionTimer.cancel();
            resetTimer();

            return 0;
        }
    }

    public void handleTimeout(int timerID) {
        synchronized(mLock) {
            electionTimer.cancel();
            RaftServerImpl.setMode(new CandidateMode());
        }
    }
}
