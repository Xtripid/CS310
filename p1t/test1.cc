#include <stdlib.h>
#include <iostream>
#include "thread.h"
#include <assert.h>

using namespace std;

void second_Thread(void* args) {
  cout << "Second thread started" << endl;
}

void first_Thread(void* args) {
  cout << "Start" << endl;
  cout << "About to call libinit again" << endl;
  thread_libinit((thread_startfunc_t)second_Thread, (void*)100);
  cout << "Failed" << endl;
}

int main(int argc, char *argv[]){
	thread_libinit((thread_startfunc_t)first_Thread, &argc);
}
