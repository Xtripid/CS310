#include <stdlib.h>
#include <iostream>
#include "thread.h"
#include <assert.h>
#include <stdio.h>
using namespace std;

void first_Thread(void* args) {
  int lock = 5;
  int condition = 12;
  cout << "Start" << endl;
  cout << "Help my dog is a mummy" << endl;
  if (thread_wait(lock,condition) == -1) {
    printf("FAILED\n");
  }
  cout << "Done with failing unlock" << endl;
}

int main(int argc, char *argv[]){
	thread_libinit((thread_startfunc_t)first_Thread, &argc);
}
