#include <stdlib.h>
#include <iostream>
#include "thread.h"
#include <assert.h>
#include <vector>
#include <string.h>
#include <fstream>
using namespace std;

void xyz1(void* args);
void xyz2(void* args);
void xyz3(void* args);
void xyz4(void* args);
void xyz5(void* args);
void xyz6(void* args);
void xyz7(void* args) ;
void xyz8(void* args);
void xyz9(void* args);
void xyz10(void* args);
void maker(void *args);
void xyz1(void* args) {
  thread_unlock(0);
  thread_unlock(1);
  thread_broadcast(1, 0);
  thread_signal(0, 1);
  thread_signal(1, 0);
  thread_signal(0, 1);
  thread_unlock(1);
  thread_signal(1, 1);
  thread_lock(1);
  thread_broadcast(0, 1);
  thread_wait(0, 0);
  thread_unlock(0);
  thread_signal(1, 0);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_unlock(1);
  thread_signal(0, 0);
  thread_wait(0, 0);
  thread_broadcast(0, 1);
  thread_lock(0);
  thread_broadcast(0, 0);
  thread_yield();
  thread_yield();
  thread_signal(1, 1);
  thread_lock(0);
  cout << "108593465" << endl;
  thread_yield();
  cout << "81394599" << endl;
  thread_signal(0, 1);
  cout << "68128580" << endl;
  thread_signal(1, 1);
  thread_signal(0, 1);
  thread_lock(1);
  thread_broadcast(1, 0);
  thread_wait(0, 1);
  thread_lock(0);
  thread_unlock(1);
  thread_lock(0);
  thread_lock(0);
  thread_lock(1);
  thread_signal(0, 0);
  thread_unlock(0);
  thread_yield();
  thread_unlock(0);
  cout << "33665012" << endl;
  thread_wait(0, 0);
  thread_unlock(0);
  thread_unlock(0);
  thread_lock(0);
  cout << "70556911" << endl;
  thread_unlock(1);
  thread_yield();
  thread_broadcast(1, 0);
  thread_unlock(1);
  cout << "40561875" << endl;
  thread_wait(0, 0);
  thread_wait(1, 1);
  thread_broadcast(0, 0);
  thread_broadcast(1, 0);
  thread_signal(0, 0);
  thread_wait(1, 0);
  thread_lock(1);
  thread_broadcast(0, 1);
  thread_signal(0, 0);
  thread_signal(1, 0);
  thread_broadcast(1, 0);
  thread_wait(0, 0);
  thread_lock(1);
  thread_lock(0);
  cout << "44687533" << endl;
  thread_yield();
  cout << "106115277" << endl;
  thread_lock(1);
  thread_signal(0, 1);
  thread_lock(1);
  cout << "37305576" << endl;
  thread_broadcast(1, 0);
  cout << "49390855" << endl;
  thread_signal(0, 1);
  thread_signal(1, 0);
  thread_broadcast(1, 1);
  cout << "74393857" << endl;
  thread_signal(1, 0);
  cout << "101384487" << endl;
  thread_signal(1, 1);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 1);
  thread_yield();
  thread_broadcast(1, 0);
  thread_unlock(0);
  thread_lock(0);
  thread_broadcast(0, 0);
  thread_wait(0, 0);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_lock(0);
  thread_lock(1);
  thread_broadcast(1, 0);
  thread_broadcast(1, 1);
  thread_broadcast(0, 0);
  thread_lock(0);
  cout << "36099910" << endl;
  thread_lock(1);
  thread_signal(1, 0);
  cout << "24798727" << endl;
  thread_wait(1, 1);
  thread_lock(1);
  thread_wait(0, 1);
  thread_lock(0);
  cout << "122664344" << endl;
  cout << "37505631" << endl;
  thread_broadcast(0, 1);
  thread_broadcast(1, 0);
  thread_yield();
  thread_lock(0);
  thread_broadcast(1, 1);
  thread_unlock(0);
  thread_unlock(1);
  thread_yield();
  thread_lock(0);
  cout << "121495046" << endl;
  thread_signal(1, 1);
  thread_wait(1, 0);
  thread_lock(1);
  thread_signal(1, 0);
  thread_wait(0, 1);
  thread_wait(1, 1);
  thread_unlock(0);
  thread_wait(1, 1);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_signal(0, 1);
  thread_wait(0, 1);
  thread_signal(1, 0);
  thread_yield();
  thread_wait(0, 1);
  cout << "100620150" << endl;
  cout << "3840884" << endl;
  thread_lock(1);
  cout << "109861001" << endl;
  thread_signal(0, 0);
  thread_unlock(0);
  thread_signal(1, 0);
  thread_unlock(1);
  thread_wait(0, 0);
  cout << "69870136" << endl;
  thread_signal(1, 1);
  thread_signal(1, 1);
  thread_broadcast(0, 1);
  thread_signal(0, 0);
  thread_signal(0, 0);
  thread_unlock(1);
  thread_unlock(0);
  cout << "65538093" << endl;
  cout << "39084426" << endl;
}

void xyz2(void* args) {
  thread_yield();
  cout << "66020043" << endl;
  thread_broadcast(12, 1);
  thread_yield();
  thread_signal(0, 8);
  thread_signal(5, 10);
  thread_wait(8, 7);
  thread_broadcast(2, 1);
  thread_signal(10, 7);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_yield();
  thread_broadcast(6, 0);
  thread_unlock(12);
  thread_unlock(3);
  cout << "71116760" << endl;
  thread_wait(6, 11);
  thread_yield();
  thread_yield();
  thread_yield();
  cout << "109745805" << endl;
  thread_lock(5);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 1);
  thread_lock(8);
  thread_yield();
  cout << "121413589" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(12, 8);
  thread_lock(1);
  thread_yield();
  cout << "9338564" << endl;
  thread_yield();
  thread_yield();
  thread_wait(2, 8);
  thread_broadcast(1, 10);
  thread_unlock(1);
  thread_signal(4, 4);
  thread_unlock(3);
  thread_yield();
  thread_yield();
  thread_lock(5);
  thread_lock(9);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_lock(6);
  thread_signal(10, 0);
  thread_yield();
  cout << "122373639" << endl;
  thread_unlock(6);
  thread_yield();
  thread_lock(0);
  thread_yield();
  thread_wait(10, 5);
  thread_wait(6, 5);
  thread_broadcast(9, 10);
}

void xyz3(void* args) {
  cout << "10786951" << endl;
  thread_wait(0, 4);
  cout << "7815481" << endl;
  cout << "1211318" << endl;
  thread_yield();
  thread_lock(2);
  thread_yield();
  thread_unlock(1);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_broadcast(6, 2);
  thread_yield();
  thread_yield();
  thread_unlock(2);
  thread_yield();
  thread_wait(1, 6);
  thread_unlock(2);
  cout << "9881240" << endl;
  thread_yield();
  thread_yield();
  thread_unlock(4);
  thread_wait(4, 0);
  thread_yield();
  cout << "11387324" << endl;
  thread_broadcast(5, 1);
  cout << "2658088" << endl;
  thread_yield();
}

void xyz4(void* args) {
  thread_broadcast(4, 1);
  thread_yield();
  thread_yield();
  thread_lock(5);
  thread_yield();
  thread_lock(7);
  thread_yield();
  thread_lock(1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(7, 7);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
    thread_yield();
  }
  thread_wait(2, 1);
  thread_unlock(0);
  thread_unlock(4);
  thread_wait(5, 7);
  thread_unlock(0);
  thread_signal(5, 2);
  cout << "44275800" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(0, 7);
  thread_signal(4, 3);
  thread_lock(6);
  thread_yield();
  thread_lock(8);
  thread_signal(0, 6);
  thread_broadcast(1, 1);
  thread_yield();
  cout << "314501" << endl;
  thread_yield();
  thread_lock(7);
  thread_wait(7, 0);
  thread_yield();
  thread_broadcast(2, 7);
  thread_lock(0);
  thread_signal(2, 2);
  thread_wait(7, 6);
  thread_lock(3);
  thread_broadcast(6, 6);
  thread_broadcast(1, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(5);
  thread_yield();
  thread_yield();
  thread_lock(0);
}

void xyz5(void* args) {
  thread_lock(16);
  thread_lock(6);
  thread_broadcast(3, 15);
  thread_wait(10, 7);
  thread_wait(7, 7);
  cout << "398001" << endl;
  thread_yield();
  thread_signal(17, 15);
  thread_yield();
  thread_lock(10);
  thread_unlock(0);
  thread_lock(0);
  thread_yield();
  thread_yield();
  cout << "63379" << endl;
  cout << "69214" << endl;
  thread_signal(3, 16);
  thread_yield();
  thread_yield();
  thread_wait(11, 13);
  thread_yield();
  thread_yield();
  cout << "1115252" << endl;
  thread_yield();
  thread_yield();
  thread_unlock(3);
  thread_yield();
  thread_yield();
  thread_lock(16);
  thread_yield();
  thread_yield();
  cout << "212601" << endl;
  thread_unlock(3);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_unlock(4);
  thread_yield();
  thread_signal(17, 15);
  thread_unlock(9);
  thread_unlock(7);
  thread_yield();
  thread_signal(17, 15);
  thread_signal(9, 17);
  thread_wait(2, 9);
  thread_signal(15, 11);
  thread_yield();
  thread_broadcast(12, 8);
  thread_unlock(6);
  thread_unlock(1);
  thread_lock(0);
  thread_wait(5, 8);
  thread_unlock(2);
  cout << "474555" << endl;
  thread_unlock(15);
  thread_yield();
  thread_lock(5);
  thread_yield();
  thread_broadcast(2, 0);
  thread_broadcast(15, 17);
  thread_lock(14);
  thread_signal(15, 5);
  thread_broadcast(17, 12);
  cout << "858647" << endl;
  thread_yield();
  thread_broadcast(16, 16);
  thread_lock(14);
  cout << "188958" << endl;
  thread_yield();
  thread_signal(3, 10);
  thread_lock(1);
  thread_unlock(14);
  thread_broadcast(8, 1);
  thread_yield();
  cout << "1210036" << endl;
  thread_yield();
  thread_signal(5, 6);
  thread_unlock(12);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(15, 14);
  cout << "285667" << endl;
  thread_yield();
  thread_lock(10);
  thread_lock(11);
  thread_lock(18);
  thread_signal(7, 0);
  thread_broadcast(16, 18);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_signal(17, 15);
  thread_signal(17, 1);
  thread_unlock(14);
  thread_yield();
  thread_signal(3, 8);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_lock(11);
  thread_yield();
  thread_yield();
  thread_signal(9, 10);
  thread_unlock(3);
  thread_lock(10);
  cout << "553873" << endl;
  thread_broadcast(8, 10);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(6, 9);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(18, 9);
  thread_wait(10, 12);
  thread_signal(16, 14);
  thread_yield();
  thread_yield();
  cout << "316065" << endl;
  thread_yield();
}

void xyz6(void* args) {
  cout << "266396" << endl;
  thread_signal(1, 1);
  thread_yield();
  thread_signal(2, 2);
  thread_broadcast(1, 1);
  thread_unlock(2);
  thread_signal(3, 0);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_yield();
  thread_unlock(3);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_yield();
  thread_wait(2, 2);
  thread_yield();
  thread_yield();
  thread_lock(2);
  thread_yield();
  thread_wait(3, 0);
  thread_yield();
  thread_signal(2, 1);
  thread_lock(3);
  thread_broadcast(2, 2);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_lock(3);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(2, 1);
  thread_yield();
  thread_unlock(0);
  thread_signal(3, 3);
  thread_broadcast(1, 2);
  thread_yield();
  thread_signal(2, 0);
  thread_yield();
  thread_signal(2, 3);
  thread_yield();
  thread_yield();
  thread_lock(2);
}

void xyz7(void* args) {
  thread_unlock(2);
  thread_broadcast(11, 12);
  thread_yield();
  thread_signal(6, 1);
  cout << "493910" << endl;
  thread_signal(5, 9);
  thread_yield();
  thread_unlock(11);
  thread_yield();
  thread_yield();
  thread_yield();
  cout << "667990" << endl;
  thread_signal(6, 12);
  thread_signal(0, 8);
  cout << "2883215" << endl;
  thread_broadcast(4, 13);
  cout << "1357257" << endl;
  thread_lock(0);
  thread_lock(1);
  thread_lock(13);
  thread_yield();
  thread_lock(1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(9, 4);
  thread_broadcast(3, 1);
  thread_unlock(1);
  thread_yield();
  thread_yield();
  thread_unlock(11);
  cout << "1221282" << endl;
  thread_signal(2, 7);
  thread_yield();
  thread_yield();
  thread_unlock(11);
  cout << "1559756" << endl;
  thread_yield();
  thread_yield();
  thread_wait(9, 8);
  thread_signal(13, 13);
  thread_yield();
  thread_yield();
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_lock(2);
  thread_lock(12);
  thread_lock(2);
  cout << "1726728" << endl;
  thread_yield();
  thread_wait(13, 1);
  thread_yield();
  thread_yield();
  thread_wait(4, 8);
  thread_broadcast(8, 0);
  thread_signal(13, 1);
  cout << "1243632" << endl;
  cout << "2187516" << endl;
  thread_yield();
  thread_yield();
  thread_lock(4);
  thread_lock(11);
  thread_yield();
  thread_unlock(5);
  thread_lock(4);
  thread_wait(7, 9);
  thread_yield();
  cout << "172760" << endl;
  thread_yield();
  thread_yield();
  thread_lock(7);
  thread_yield();
  thread_broadcast(1, 5);
  thread_lock(12);
  thread_broadcast(6, 5);
  thread_yield();
  thread_unlock(0);
  thread_unlock(9);
  thread_yield();
  thread_wait(2, 5);
  thread_signal(9, 10);
  thread_signal(7, 10);
  thread_unlock(7);
  thread_broadcast(1, 6);
  thread_broadcast(0, 0);
  cout << "1167435" << endl;
  thread_wait(11, 6);
  thread_yield();
  thread_unlock(1);
  thread_lock(10);
}

void xyz8(void* args) {
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  cout << "3506" << endl;
  thread_wait(2, 2);
  thread_signal(0, 1);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_broadcast(1, 0);
  thread_signal(2, 2);
  thread_unlock(2);
  thread_broadcast(2, 2);
  cout << "12182" << endl;
  thread_yield();
  thread_yield();
  thread_wait(2, 1);
  thread_yield();
}

void xyz9(void* args) {
  thread_yield();
  thread_unlock(0);
  thread_yield();
  thread_yield();
  cout << "1406296" << endl;
  thread_yield();
  thread_broadcast(0, 0);
  thread_yield();
  thread_yield();
  thread_wait(0, 1);
  thread_unlock(0);
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  cout << "152201" << endl;
  thread_yield();
  thread_unlock(0);
  thread_broadcast(0, 0);
  thread_unlock(1);
  thread_yield();
  thread_yield();
  cout << "2184847" << endl;
  thread_yield();
  thread_unlock(0);
  thread_broadcast(0, 0);
  thread_unlock(0);
  thread_yield();
  thread_signal(1, 0);
  thread_wait(1, 0);
  thread_unlock(1);
  thread_unlock(0);
  thread_broadcast(1, 1);
  cout << "1133879" << endl;
  thread_signal(1, 0);
  thread_lock(1);
  thread_yield();
  thread_broadcast(0, 0);
  thread_unlock(1);
  cout << "1337055" << endl;
  thread_signal(0, 1);
  thread_broadcast(0, 0);
  thread_lock(0);
  thread_lock(1);
  thread_yield();
  thread_lock(0);
  thread_yield();
  thread_unlock(1);
  thread_unlock(0);
  thread_broadcast(0, 0);
  thread_broadcast(1, 0);
  thread_signal(1, 1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(0, 1);
  thread_yield();
  thread_signal(0, 1);
  thread_lock(1);
  cout << "1859237" << endl;
  thread_yield();
  thread_signal(1, 1);
  thread_unlock(1);
  thread_broadcast(0, 1);
  thread_wait(1, 1);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_broadcast(0, 0);
  thread_unlock(1);
  thread_yield();
  cout << "179903" << endl;
  thread_lock(1);
  thread_yield();
  thread_yield();
  thread_wait(1, 0);
  thread_unlock(0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(0, 1);
}

void xyz10(void* args) {
  thread_lock(3);
  thread_unlock(4);
  thread_signal(0, 1);
  thread_yield();
  thread_unlock(0);
  thread_yield();
  thread_unlock(4);
  thread_wait(4, 5);
  thread_signal(0, 1);
  thread_lock(2);
  thread_wait(3, 3);
  cout << "175691" << endl;
  thread_unlock(3);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(1, 1);
  thread_yield();
  thread_lock(1);
  thread_lock(1);
  thread_broadcast(4, 4);
  thread_yield();
  thread_broadcast(0, 3);
  thread_yield();
  cout << "4494" << endl;
  thread_yield();
  thread_wait(4, 0);
  thread_yield();
  thread_signal(3, 1);
  thread_broadcast(1, 4);
  thread_yield();
  thread_unlock(2);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 2);
  thread_lock(1);
  thread_yield();
  thread_signal(3, 4);
  thread_wait(2, 5);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_lock(4);
  thread_signal(1, 0);
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_wait(4, 1);
  thread_broadcast(2, 4);
  thread_lock(3);
  cout << "185410" << endl;
  thread_yield();
  thread_unlock(2);
  thread_yield();
  thread_yield();
  thread_broadcast(2, 1);
  thread_wait(4, 4);
  thread_lock(1);
  thread_yield();
  thread_unlock(0);
}

void maker(void *args) {
  thread_lock(0);
  thread_create((thread_startfunc_t) xyz1, (void *) 100);
  thread_create((thread_startfunc_t) xyz2, (void *) 100);
  thread_wait(1, 1);
  thread_signal(0, 0);
  thread_yield();
  thread_wait(1, 1);
  thread_signal(1, 0);
  thread_wait(0, 0);
  thread_create((thread_startfunc_t) xyz3, (void *) 100);
  thread_unlock(0);
  thread_signal(1, 0);
  thread_create((thread_startfunc_t) xyz4, (void *) 100);
  thread_create((thread_startfunc_t) xyz5, (void *) 100);
  thread_lock(0);
  thread_wait(1, 0);
  thread_create((thread_startfunc_t) xyz6, (void *) 100);
  thread_create((thread_startfunc_t) xyz7, (void *) 100);
  thread_wait(0, 1);
  thread_wait(0, 0);
  thread_broadcast(1, 1);
  thread_signal(1, 1);
  thread_create((thread_startfunc_t) xyz8, (void *) 100);
  thread_yield();
  thread_create((thread_startfunc_t) xyz9, (void *) 100);
  thread_signal(0, 0);
  thread_create((thread_startfunc_t) xyz10, (void *) 100);
  thread_unlock(0);
  thread_yield();
  thread_yield();
  thread_signal(0, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(1, 0);
  thread_yield();
  thread_yield();
  thread_signal(0, 1);
  thread_yield();
  thread_unlock(0);
  thread_lock(0);
  thread_unlock(0);
  thread_broadcast(1, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(0, 0);
  thread_yield();
  thread_broadcast(0, 1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(0, 0);
  thread_unlock(1);
  thread_signal(0, 1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_unlock(1);
  thread_yield();
  thread_yield();
  thread_signal(1, 0);
  thread_yield();
  thread_yield();
  thread_broadcast(1, 1);
  thread_signal(0, 1);
  thread_wait(0, 1);
  thread_signal(0, 1);
  thread_signal(0, 1);
  thread_signal(1, 1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(0, 0);
  thread_yield();
  thread_signal(0, 1);
  thread_wait(1, 1);
  thread_signal(1, 1);
  thread_yield();
  thread_yield();
  thread_lock(1);
  thread_signal(1, 1);
  thread_unlock(0);
  thread_wait(1, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
}

int main(int argc, char *argv[]) {
  thread_libinit((thread_startfunc_t)maker, &argc);
}
