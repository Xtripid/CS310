#include <stdlib.h>
#include <iostream>
#include "thread.h"
#include <assert.h>
#include <stdio.h>
using namespace std;

unsigned int lock = 1;

void help(void* args) {
  cout << "Help" << endl;
}
void first_Thread(void* args) {
    for (int i = 0; i < 100000; i++) {
      thread_create((thread_startfunc_t)help, &args);
    }
}

int main(int argc, char *argv[]){
	thread_libinit((thread_startfunc_t)first_Thread, &argc);
}
