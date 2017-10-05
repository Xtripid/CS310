#include <stdlib.h>
#include <assert.h>
#include "thread.h"
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

void first(void* args);
void second(void* args);
void third(void* args);
void fourth(void* args);
void fifth(void* args);
void sixth(void* args);
void seventh(void* args);
void eigth(void* args);
void first_Thread(void* args);
void xyz(void* args);
void www(void* args);

void first(void* args) {
  thread_create((thread_startfunc_t) second, args);
  thread_yield();
  cout << "hello MAMA" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(2, 7);
  thread_lock(1);
  thread_yield();
  thread_yield();
  thread_create((thread_startfunc_t) third, args);
  thread_yield();
  thread_unlock(0);
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_yield();
  thread_yield();
  thread_signal(2, 3);
  thread_lock(5);
  thread_yield();
  thread_create((thread_startfunc_t) fourth, args);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(9, 7);
  thread_create((thread_startfunc_t) fifth, args);
  thread_yield();
  thread_signal(6, 0);
  thread_yield();
  thread_lock(9);
  thread_create((thread_startfunc_t) sixth, args);
  thread_yield();
  thread_yield();
  thread_create((thread_startfunc_t) seventh, args);
  thread_yield();
  thread_yield();
  thread_unlock(9);
  thread_create((thread_startfunc_t) eigth, args);
  thread_yield();
  thread_create((thread_startfunc_t) first_Thread, args);
  thread_create((thread_startfunc_t) xyz, args);
  thread_yield();
  thread_yield();
  thread_create((thread_startfunc_t) www,args);
  thread_yield();
  
}

int num=500;

void afterThreads(void* args) {
    thread_lock(0);
    thread_unlock(0);
}

void xyz(void* args) {
  int **inputs = (int**) args;
  long count = 0;
  while(num != 0) {
      if (thread_create((thread_startfunc_t) afterThreads, (void*) 10) == -1) {
          printf("ERROR, so far %ld threads created\n", count);
          perror("Fail:");
      }
      count++;
      num --;
  }
}

void first_Thread(void* args) {
  for(int i = 0; i < num; i++) {
      if (thread_create((thread_startfunc_t) afterThreads, (void*) 10) == -1) {
          perror("Fail:");
      }
      else {
        printf("Working\n");
      }
  }
}

void www(void* args) {
  int waiting = thread_wait(2,1);
  if (waiting == -1) {
    cout << "Failed because wait" << endl;
  }
}

void second(void* args) {
  thread_signal(0, 1);
  thread_yield();
  thread_yield();
  thread_wait(0, 1);
  thread_yield();
  thread_lock(0);
  thread_yield();
  cout << "hello MAMA" << endl;
  cout << "hello MAMA" << endl;
  thread_lock(0);
  thread_broadcast(0, 0);
  cout << "hello MAMA" << endl;
  thread_signal(1, 1);
  thread_unlock(0);
  thread_broadcast(0, 1);
  thread_wait(0, 0);
  thread_yield();
  thread_unlock(0);
  thread_broadcast(0, 1);
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_lock(0);
  thread_lock(0);
  thread_yield();
  thread_broadcast(0, 0);
  cout << "hello MAMA" << endl;
  thread_signal(1, 1);
  thread_unlock(0);
  thread_broadcast(0, 1);
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_wait(1, 0);
  thread_yield();
  thread_wait(0, 0);
  cout << "hello MAMA" << endl;
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_unlock(1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(1, 1);
  thread_unlock(0);
  thread_wait(0, 1);
  thread_wait(0, 1);
}

void third(void* args) {
  thread_yield();
  thread_lock(5);
  thread_yield();
  thread_signal(3, 4);
  thread_lock(2);
  thread_yield();
  cout << "hello MAMA" << endl;
  cout << "hello MAMA" << endl;
  thread_signal(10, 3);
  thread_yield();
  thread_yield();
  thread_wait(2, 0);
  thread_wait(4, 5);
  thread_yield();
  thread_signal(2, 3);
  thread_lock(5);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(7, 10);
  thread_yield();
  thread_yield();
  thread_signal(9, 7);
  thread_yield();
  thread_signal(6, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_lock(9);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(9);
  thread_yield();
  thread_wait(1, 10);
}

void fourth(void* args) {
  thread_signal(0, 1);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 0);
  cout << "hello MAMA" << endl;
  thread_signal(1, 1);
  thread_unlock(0);
  thread_broadcast(0, 1);
  thread_wait(0, 0);
  thread_yield();
  thread_signal(1, 1);
  thread_signal(0, 0);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 0);
  thread_yield();
  thread_lock(0);
  thread_yield();
  cout << "hello MAMA" << endl;
  cout << "hello MAMA" << endl;
  thread_lock(0);
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 0);
  cout << "hello MAMA" << endl;
  thread_signal(1, 1);
  thread_unlock(0);
  thread_broadcast(0, 1);
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_lock(0);
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_wait(1, 0);
  thread_broadcast(0, 0);
  cout << "hello MAMA" << endl;
  thread_signal(1, 1);
  thread_unlock(0);
  thread_broadcast(0, 1);
  thread_wait(0, 0);
  thread_yield();
}

void fifth(void* args) {
  thread_yield();
  thread_lock(5);
  thread_yield();
  thread_signal(3, 4);
  thread_lock(2);
  thread_yield();
  cout << "hello MAMA" << endl;
  cout << "hello MAMA" << endl;
  thread_signal(10, 3);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(9, 7);
  thread_yield();
  thread_signal(6, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(0, 0);
  cout << "hello MAMA" << endl;
  thread_signal(1, 1);
  thread_unlock(0);
  thread_broadcast(0, 1);
  thread_wait(0, 0);
  thread_yield();
  thread_unlock(9);
  thread_yield();
  thread_wait(1, 10);
}

void sixth(void* args) {
  thread_signal(0, 1);
  thread_yield();
  thread_yield();
  thread_wait(0, 1);
  thread_yield();
  thread_lock(1);
  thread_yield();
  thread_broadcast(0, 1);
  thread_signal(1, 1);
  thread_signal(0, 0);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 0);
  thread_yield();
  thread_lock(0);
  thread_yield();
  cout << "hello MAMA" << endl;
  cout << "hello MAMA" << endl;
  thread_lock(0);
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 0);
  cout << "hello MAMA" << endl;
  thread_signal(1, 1);
  thread_unlock(0);
  thread_broadcast(0, 1);
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_lock(0);
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_wait(1, 0);
  thread_yield();
  thread_wait(0, 0);
  cout << "hello MAMA" << endl;
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_unlock(1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(1, 1);
  thread_unlock(0);
  thread_wait(0, 1);
  thread_wait(0, 1);
}

void seventh(void* args) {
  thread_yield();
  thread_lock(5);
  thread_yield();
  thread_signal(3, 4);
  thread_lock(2);
  thread_yield();
  cout << "hello MAMA" << endl;
  cout << "hello MAMA" << endl;
  thread_signal(10, 3);
  thread_yield();
  thread_yield();
  thread_yield();
  cout << "hello MAMA" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(2, 7);
  thread_lock(1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_wait(2, 0);
  thread_wait(4, 5);
  thread_yield();
  thread_signal(2, 3);
  thread_lock(5);
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_yield();

}

void eigth(void* args) {
  thread_signal(0, 1);
  thread_yield();
  thread_yield();
  thread_wait(0, 1);
  thread_yield();
  thread_lock(1);
  thread_yield();
  thread_broadcast(0, 1);
  thread_signal(1, 1);
  thread_signal(0, 0);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 0);
  thread_yield();
  thread_lock(0);
  thread_yield();
  cout << "hello MAMA" << endl;
  cout << "hello MAMA" << endl;
  thread_lock(0);
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 0);
  cout << "hello MAMA" << endl;
  thread_signal(1, 1);
  thread_unlock(0);
  thread_broadcast(0, 1);
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_lock(0);
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_wait(1, 0);
  thread_yield();
  thread_wait(0, 0);
  cout << "hello MAMA" << endl;
  thread_lock(0);
  thread_yield();
  thread_signal(1, 1);
  thread_unlock(0);
  thread_wait(0, 1);
  thread_wait(0, 1);
}

int main(int argc, char *argv[]) {
  thread_libinit( (thread_startfunc_t) first, &argc);
}
