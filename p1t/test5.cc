#include <stdlib.h>
#include <iostream>
#include "thread.h"
#include <assert.h>

using namespace std;


void second(void* args) {
  thread_lock(3);
  cout << "Second thread started" << endl;
  thread_wait(3,1);
  thread_signal(2,1);
  thread_unlock(3);
}

void third(void* args) {
  thread_lock(2);
  cout << "Third thread started" << endl;
  thread_wait(2,1);
  thread_signal(3,1);
  thread_unlock(2);
}

void first(void* args) {
  thread_lock(2);
  cout << "Started threads" << endl;
  thread_create((thread_startfunc_t)second, args);
  thread_yield();
  thread_create((thread_startfunc_t)third, args);
  thread_yield();
  thread_yield();
  thread_broadcast(2,1);
  cout << "Done" << endl;
  thread_unlock(2);
}

int main(int argc, char *argv[]){
	int num = 123456789;
	thread_libinit((thread_startfunc_t) first, &num);
}
