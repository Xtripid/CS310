#include <stdlib.h>
#include <iostream>
#include "thread.h"
#include <assert.h>
#include <vector>
#include <string.h>
#include <fstream>
using namespace std;

void threadone() {
    thread_lock(10);
    for (int i = 0; i < 1231023; i++) {
        thread_yield();
        cout << "asldfkja;sldkfj" << endl;
        thread_yield();
    }
    thread_unlock(10);
}

void threadtwo() {
    thread_lock(11);
    for (int i = 0; i < 1231023; i++) {
        thread_yield();
        cout << "1293487198234;sldkfj" << endl;
        thread_yield();
    }
    thread_unlock(11);

}

void threadthree() {
    thread_lock(12);
    for (int i = 0; i < 1231023; i++) {
        thread_yield();
        cout << "asldfkja;]w[epr]pr]epw]][][]" << endl;
        thread_yield();
    }
    thread_unlock(12);

}

void threadfour() {
    thread_lock(13);
    for (int i = 0; i < 1231023; i++) {
        thread_yield();
        cout << "asldfkja;12i34h1i234o1i23u4h12i34l1" << endl;
        thread_yield();
    }
    thread_unlock(13);
}

void thread() {
    thread_lock(10);
    thread_create((thread_startfunc_t) threadtwo, (void*) 10);
    thread_create((thread_startfunc_t) threadthree, (void*) 10);
    for (int i = 0; i < 1231023; i++) {
        thread_yield();
        cout << "/././././qw.e/qw.e/qw.e;sldkfj" << endl;
        thread_yield();
    }
    thread_create((thread_startfunc_t) threadone, (void*) 10);
    thread_create((thread_startfunc_t) threadfour, (void*) 10);
    thread_unlock(10);
}

int main() {
    thread_libinit((thread_startfunc_t) thread, (void*) 10);
    thread_lock(9);

    for (int i = 0; i < 10; i++) {
        thread_yield();
        cout << "asdfalsdfjlasdkfj" << endl;
    }
}
