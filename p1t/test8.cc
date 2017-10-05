#include <stdlib.h>
#include <assert.h>
#include "thread.h"
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

static int global;

void threadone() {
    thread_lock(10);
    thread_lock(122);
    thread_create((thread_startfunc_t) thread, (void*) 10);
    thread_unlock(10);
    for (int i = 0; i < 1000000; i++) {
        global++;
        thread_yield();
        thread_wait(1, 17);
        thread_yield();
        thread_lock(i+29);
        thread_unlock(58);
    }
    thread_unlock(10);
}

void threadtwo() {
    thread_lock(10);
    thread_yield();
    thread_create((thread_startfunc_t) threadtwo, (void*) 10);
    thread_create((thread_startfunc_t) threadone, (void*) 10);
    for (int i = 0; i < 1000000; i++) {
        global++;
        thread_yield();
        thread_broadcast(200, -100000);
    }
    thread_unlock(10);
}

void threadthree() {
    thread_lock(10);
    for (int i = 0; i < 1000000; i++) {
        global++;
        thread_yield();
        thread_wait(i, i+9);
        thread_signal(1, i+9);
        thread_wait(i+7, i-9);
        thread_yield();
        thread_unlock(i+100);
        thread_create((thread_startfunc_t) threadthree, (void*) 10);
        thread_create((thread_startfunc_t) thread, (void*) 10);
    }
    thread_unlock(10);
}

void thread() {
    thread_create((thread_startfunc_t) threadone, (void*) 10);
    thread_create((thread_startfunc_t) threadtwo, (void*) 10);
    thread_create((thread_startfunc_t) threadthree, (void*) 10);
    thread_yield();
}

int main() {
    thread_libinit((thread_startfunc_t) thread, (void*) 10);
    thread_create((thread_startfunc_t) thread, (void*) 10);
}
