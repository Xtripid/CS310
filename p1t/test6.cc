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
    thread_yield();
    thread_yield();
    thread_yield();

    thread_yield();
    int num = cashier_num;
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();

    thread_yield();
    cashier_num++;
    thread_yield();
    thread_yield();
    thread_yield();

    thread_yield();
    int* input = (int*) args;
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    int i;
    thread_yield();

    thread_yield();

    thread_yield();
    thread_yield();
    int next_order;
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    while (i < 5) {
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();

        thread_yield();
        while (board.size() == min(boardMaxSize,num_CashiersLeft)) {
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_wait(lock,-1);

            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
        }
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        next_order = rand()%1000;
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        board.push_back(next_order);
        thread_yield();
        thread_yield();
        thread_yield();

        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        cout << "POSTED: cashier " << num << " sandwich " << next_order << endl;
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
        thread_yield();
        thread_signal(lock,-2);
        thread_yield();

        thread_yield();
        thread_yield();
        thread_yield();
        thread_wait(lock,next_order);
        thread_yield();
        thread_yield();
        thread_yield();

        thread_yield();
        thread_yield();
        cout << "READY: cashier " << num << " sandwich " << next_order << endl;
        thread_yield();
        thread_yield();
        thread_yield();

        thread_yield();
        thread_yield();
        thread_yield();
        thread_signal(lock,-2);
        thread_yield();
        thread_yield();
        thread_yield();

        thread_yield();
        thread_yield();
        thread_yield();
        thread_wait(lock, -1);

        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();

        i++;
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
        thread_yield();
    }
    thread_yield();
    thread_yield();
    thread_yield();

    thread_yield();
    thread_yield();
    num_CashiersLeft--;
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    boardMaxSize = min(boardMaxSize, num_CashiersLeft);
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_signal(lock,-2);
    thread_yield();

    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_unlock(lock);
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
}

void maker(void* args) {
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_lock(lock); //lock it down
    thread_yield();
    thread_yield();
    thread_yield();


    //start_preemptions(true,true,1000);
    thread_yield();
    thread_yield();
    thread_yield();

    thread_yield();
    thread_yield();
    thread_yield();
    char **inputs = (char**) args;
    thread_yield();
    thread_yield();

    thread_yield();

    thread_yield();
    thread_yield();
    for (int i = 0; i < num_CashiersLeft; i++) {
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();

        thread_yield();
        thread_yield();

        thread_create((thread_startfunc_t) cashier, inputs[i]);
        thread_yield();
        thread_yield();

        thread_yield();
        thread_yield();
        thread_yield();

    }

    while(board.size() != min(boardMaxSize,num_CashiersLeft)) { //iterate through until you reach the poiint where the board is full for the first time
        thread_yield();
        thread_yield();
        thread_yield();


        thread_yield();
        thread_yield();
        thread_signal(lock, -1);
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();

        thread_yield();
        thread_wait(lock, -2);
        thread_yield();
        thread_yield();
        thread_yield();

        thread_yield();
        thread_yield();
        thread_yield();
    }

    // if(board.size() == min(boardMaxSize,num_CashiersLeft)){ //for the first time that the board is full, we get the first order on the board and we save that in currentOrder and erase it from the board
    //     currentOrder = board.front();
    //     board.erase(board.begin());
    //     thread_signal(lock, currentOrder);
    //     thread_wait(lock, -2);
    // }
    thread_yield();
    thread_yield();
    thread_yield();

    thread_yield();
    thread_yield();
    while(num_CashiersLeft > 0) {
        while(board.size() != min(boardMaxSize,num_CashiersLeft)) { //wait until the board is full
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();

            thread_signal(lock, -1);
            thread_yield();
            thread_yield();
            thread_yield();

            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_wait(lock, -2);
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();
            if(num_CashiersLeft==0) {
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();

              goto endloops;
              thread_yield();
              thread_yield();
              thread_yield();
              thread_yield();

              thread_yield();
              thread_yield();
            }
        }
        int diff = abs(currentOrder - board.at(0));
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();

        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        int smallestDiffIndex = 0;
        thread_yield();
        thread_yield();
        thread_yield();

        thread_yield();
        thread_yield();
        for(int i = 1; i < board.size(); i++) { //get the smallest difference between sandwich ids to get the next sandwich
            thread_yield();
            thread_yield();
            thread_yield();
            thread_yield();

            thread_yield();

            if(abs(currentOrder - board.at(i)) < diff){
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();
                thread_yield();

                diff = abs(currentOrder - board.at(i));
                thread_yield();
                thread_yield();
                thread_yield();

                thread_yield();
                thread_yield();

                smallestDiffIndex = i;
                thread_yield();
                thread_yield();
                thread_yield();

                thread_yield();
                thread_yield();
                thread_yield();
            }
        }
        currentOrder = board.at(smallestDiffIndex); //set the currentOrder to the smallest diff sandwich order
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();

        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        board.erase(board.begin() + smallestDiffIndex); //delete that order from the board
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_broadcast(lock, currentOrder); //signal that the sandwich is ready
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_wait(lock, -2);
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();
        thread_yield();

    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
}
    endloops:
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();

    thread_unlock(lock);
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();
    thread_yield();

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
