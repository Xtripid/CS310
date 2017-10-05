#include "thread.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

unsigned int lock;
unsigned int waitCashier;
unsigned int waitMaker;

int board_size;
int num_cashiers;
int cashier_nums;

vector<int> board;


//MAKER:
//when board is not full, maker wait on 2
//when board is full, signal maker at 2

//CASHIER:
//when board is not full, signal cashier at 1
//when board is full, cashier wait on 1

void cashier(void* args) {
    thread_lock(lock);

    int cashier_num = cashier_nums;
    cashier_nums++;

    char* input = (char*) args;
    ifstream stream(input);
    int order;

    while (!stream.eof()) {
        stream >> order;

        if (stream.eof()) {
            break;
        }

        while (board.size() == min(board_size, num_cashiers)) {
            thread_wait(lock, waitCashier);
        }

        board.push_back(order);
        cout << "POSTED: cashier " << cashier_num << " sandwich " << order << endl;

        if (board.size() == min(board_size, num_cashiers)) {
            thread_signal(lock, waitMaker);
        }

        thread_wait(lock, order);
        cout << "READY: cashier " << cashier_num << " sandwich " << order << endl;
    }

    num_cashiers--;
    thread_signal(lock, waitMaker);

    thread_unlock(lock);
}

void maker(void* args) {
    thread_lock(lock);

    char **inputs = (char**) args;
    for (int i = 0; i < num_cashiers; i++) {
        thread_create((thread_startfunc_t) cashier, inputs[i]);
    }

    while (num_cashiers > 0) {
        while (board.size() < min(board_size, num_cashiers)) {
            thread_signal(lock, waitCashier);
            thread_wait(lock, waitMaker);
        }

        

        int order = board.front();
        board.erase(board.begin());
        thread_signal(lock, order);
        thread_wait(lock, waitMaker);
    }

    thread_unlock(lock);
}

int main(int argc, char *argv[]) {
    board_size = atoi(argv[1]);
    num_cashiers = argc - 2;
    cashier_nums = 0;
    lock = 1;
    waitCashier = 2;
    waitMaker = 3;

    char* cashier_inputs[num_cashiers];

    for (int i = 0; i < num_cashiers; i++) {
        cashier_inputs[i] = argv[i+2];
    }

    thread_libinit((thread_startfunc_t) maker, cashier_inputs);
}
