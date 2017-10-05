#include "thread.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int boardMaxSize = 0;
int num_CashiersLeft;
int cashier_num = 0;
unsigned int lock;
vector<int> board;
int currentOrder=-1;

void cashier(void* args){
    thread_lock(lock);
    int num = cashier_num;
    cashier_num++;
    int* input = (int*) args;
    int i;
    int next_order;
    while (i < 5) {
        while (board.size() == min(boardMaxSize,num_CashiersLeft)) {
            thread_wait(lock,-1);
        }
        next_order = rand()%1000;
        board.push_back(next_order);
        cout << "POSTED: cashier " << num << " sandwich " << next_order << endl;
        thread_signal(lock,-2);
        thread_wait(lock,next_order);
        cout << "READY: cashier " << num << " sandwich " << next_order << endl;
        thread_signal(lock,-2);
        thread_wait(lock, -1);
        i++;
    }
    num_CashiersLeft--;
    boardMaxSize = min(boardMaxSize, num_CashiersLeft);
    thread_signal(lock,-2);
    thread_unlock(lock);
}

void maker(void* args) {
    thread_lock(lock); //lock it down
    //start_preemptions(true,true,1000);
    char **inputs = (char**) args;
    for (int i = 0; i < num_CashiersLeft; i++) {
        thread_create((thread_startfunc_t) cashier, inputs[i]);
    }

    while(board.size() != min(boardMaxSize,num_CashiersLeft)) { //iterate through until you reach the poiint where the board is full for the first time
        thread_signal(lock, -1);
        thread_wait(lock, -2);
    }

    // if(board.size() == min(boardMaxSize,num_CashiersLeft)){ //for the first time that the board is full, we get the first order on the board and we save that in currentOrder and erase it from the board
    //     currentOrder = board.front();
    //     board.erase(board.begin());
    //     thread_signal(lock, currentOrder);
    //     thread_wait(lock, -2);
    // }
    while(num_CashiersLeft > 0) {
        while(board.size() != min(boardMaxSize,num_CashiersLeft)) { //wait until the board is full
            thread_signal(lock, -1);
            thread_wait(lock, -2);
            if(num_CashiersLeft==0) {
              goto endloops;
            }
        }
        int diff = abs(currentOrder - board.at(0));

        int smallestDiffIndex = 0;
        for(int i = 1; i < board.size(); i++) { //get the smallest difference between sandwich ids to get the next sandwich
            if(abs(currentOrder - board.at(i)) < diff){
                diff = abs(currentOrder - board.at(i));
                smallestDiffIndex = i;
            }
        }
        currentOrder = board.at(smallestDiffIndex); //set the currentOrder to the smallest diff sandwich order
        board.erase(board.begin() + smallestDiffIndex); //delete that order from the board
        thread_broadcast(lock, currentOrder); //signal that the sandwich is ready
        thread_wait(lock, -2);
    }
    endloops:
    thread_unlock(lock);
}

int main(int argc, char *argv[]) {
    boardMaxSize = 3;
    num_CashiersLeft = 5;

    int inputs[num_CashiersLeft];

    inputs[0] = 0;
    inputs[1] = 1;
    inputs[2] = 2;
    inputs[3] = 3;
    inputs[4] = 4;

    thread_libinit((thread_startfunc_t) maker, inputs); //initialize maker
}
