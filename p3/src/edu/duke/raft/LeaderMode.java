package edu.duke.raft;
import java.util.*;

public class LeaderMode extends RaftMode {

    Timer heartbeatTimer = new Timer();

    int heartbeatID;

    public void go() {
        synchronized(mLock) {
            int currentTerm = mConfig.getCurrentTerm();
            System.out.println ("S" + mID + "." + currentTerm + ": switched to leader mode.");
            // System.out.println("leader " + mID + " current term: " + currentTerm);
            heartbeatID = 19 * mID * currentTerm;
            Entry[] entries = getEntries();
            heartbeatTimer.cancel();
            sendAppendCommand(entries);
            resetTimer();
        }
    }

    public int requestVote(int candidateTerm, int candidateID, int lastLogIndex, int lastLogTerm) {
        synchronized(mLock) {
            int currentTerm = mConfig.getCurrentTerm();

            if (candidateTerm < currentTerm) {
                return currentTerm;
            } else if (candidateTerm > currentTerm) {
                if (lastLogTerm >= mLog.getLastTerm()) {
                    mConfig.setCurrentTerm(candidateTerm, candidateID);
                    heartbeatTimer.cancel();
                    RaftServerImpl.setMode(new FollowerMode());

                    return 0;
                } else {
                    mConfig.setCurrentTerm(candidateTerm, 0);
                    heartbeatTimer.cancel();
                    RaftServerImpl.setMode(new FollowerMode());

                    return currentTerm;
                }
            } else {
                if (lastLogTerm >= mLog.getLastTerm()) {
                    int votedFor = mConfig.getVotedFor();
                    if (votedFor == 0 || votedFor == candidateID) {
                        heartbeatTimer.cancel();
                        RaftServerImpl.setMode(new FollowerMode());

                        return 0;
                    } else {
                        heartbeatTimer.cancel();
                        RaftServerImpl.setMode(new FollowerMode());

                        return currentTerm;
                    }
                } else {
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
            } else if (leaderTerm > currentTerm){
                mConfig.setCurrentTerm(leaderTerm, 0);
                heartbeatTimer.cancel();
                RaftServerImpl.setMode(new FollowerMode());

                return 0;
            } else {
                if (leaderID == mID) {
                    heartbeatTimer.cancel();
                    resetTimer();
                    return 0;
                } else {
                    if (entries.length > mLog.getLastIndex()) {
                        mConfig.setCurrentTerm(leaderTerm, 0);
                        heartbeatTimer.cancel();
                        RaftServerImpl.setMode(new FollowerMode());
                    }

                    return 0;
                }
            }
        }
    }

    public void handleTimeout(int timerID) {
        synchronized(mLock) {
            int currentTerm = mConfig.getCurrentTerm();
            int[] responseTerms = RaftResponses.getAppendResponses(currentTerm);

            for (int i = 0; i < responseTerms.length; i++) {
                if (responseTerms[i]>currentTerm) {
                    if (mID != i) {
                        mConfig.setCurrentTerm(responseTerms[i],0);
                        heartbeatTimer.cancel();
                        RaftServerImpl.setMode(new FollowerMode());
                        return;
                    }
                }
            }

            Entry[] entries = getEntries();
            sendAppendCommand(entries);
            heartbeatTimer.cancel();
            resetTimer();
        }
    }

    public Entry[] getEntries() {
        ArrayList<Entry> list = new ArrayList<Entry>();

        int j = 0;
        while (mLog.getEntry(j) != null) {
            list.add(mLog.getEntry(j));
            j++;
        }

        Entry[] entries = new Entry[list.size()];
        for (int i = 0; i < entries.length; i++) {
            entries[i] = list.get(i);
        }
        return entries;
    }

    public void sendAppendCommand(Entry[] entries) {
        int numServers = mConfig.getNumServers();
        int currentTerm = mConfig.getCurrentTerm();
        for (int i = 1; i <= numServers; i++) {
            remoteAppendEntries(i, currentTerm, mID, 0, 0, entries, mCommitIndex);
        }
    }

    public void resetTimer() {
        heartbeatTimer = scheduleTimer(HEARTBEAT_INTERVAL, heartbeatID);
    }

}
