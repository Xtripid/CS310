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
  thread_lock(1);
  thread_wait(0, 0);
  thread_yield();
  thread_broadcast(1, 1);
  thread_unlock(1);
  thread_yield();
  thread_unlock(1);
  thread_broadcast(0, 0);
  thread_signal(1, 1);
  thread_broadcast(0, 1);
  cout << "48974287" << endl;
  thread_yield();
  thread_broadcast(0, 0);
  cout << "41223225" << endl;
  thread_broadcast(1, 1);
  thread_lock(0);
  thread_unlock(1);
  thread_signal(1, 0);
  thread_yield();
  thread_wait(0, 1);
  thread_signal(0, 0);
  thread_wait(0, 1);
  cout << "26400395" << endl;
  thread_wait(0, 0);
  thread_broadcast(1, 1);
  thread_broadcast(0, 0);
  thread_broadcast(0, 0);
  thread_signal(1, 1);
  thread_lock(0);
  thread_broadcast(0, 1);
  cout << "2948024" << endl;
  thread_lock(1);
  thread_lock(1);
  thread_yield();
  cout << "87876533" << endl;
  thread_unlock(0);
  cout << "83601977" << endl;
  cout << "27509190" << endl;
  thread_unlock(1);
  thread_wait(1, 1);
  cout << "55627621" << endl;
  thread_broadcast(0, 0);
  thread_lock(0);
  thread_signal(1, 1);
  cout << "112105589" << endl;
  thread_broadcast(0, 1);
  thread_lock(1);
  thread_unlock(0);
  thread_wait(0, 0);
  thread_broadcast(0, 0);
  thread_lock(1);
  thread_lock(1);
  thread_signal(1, 0);
  thread_wait(1, 0);
  thread_lock(1);
  thread_lock(0);
  thread_lock(0);
  thread_unlock(1);
  thread_unlock(0);
  thread_unlock(0);
  thread_lock(0);
  thread_unlock(1);
  thread_lock(1);
  thread_unlock(1);
  thread_signal(1, 0);
  thread_broadcast(0, 1);
  thread_lock(1);
  thread_lock(0);
  thread_broadcast(1, 0);
  thread_broadcast(0, 0);
  thread_broadcast(1, 1);
  thread_yield();
  thread_wait(1, 0);
  cout << "57952112" << endl;
  thread_lock(0);
  thread_lock(0);
  thread_lock(0);
  cout << "74850095" << endl;
  thread_yield();
  thread_broadcast(0, 1);
  thread_signal(0, 1);
  thread_unlock(1);
  thread_broadcast(1, 0);
  thread_lock(1);
  cout << "42798257" << endl;
  thread_broadcast(0, 0);
  thread_wait(0, 1);
  thread_wait(0, 1);
  thread_yield();
  thread_lock(1);
  thread_wait(0, 0);
  thread_broadcast(1, 0);
  thread_unlock(0);
  thread_signal(1, 1);
  thread_wait(1, 1);
  thread_signal(0, 1);
  thread_unlock(0);
  thread_lock(1);
  thread_yield();
  thread_yield();
  thread_lock(0);
  thread_lock(1);
  thread_lock(0);
  thread_signal(1, 1);
  thread_lock(1);
  cout << "3892168" << endl;
  thread_broadcast(1, 0);
  thread_lock(0);
  thread_broadcast(1, 1);
  thread_broadcast(0, 0);
  thread_signal(1, 1);
  cout << "69589761" << endl;
  thread_lock(0);
  thread_signal(1, 0);
  thread_broadcast(0, 1);
  thread_broadcast(0, 1);
  thread_lock(1);
  thread_wait(0, 0);
  cout << "44799587" << endl;
  thread_lock(0);
  thread_signal(0, 1);
  thread_lock(1);
  thread_lock(1);
  cout << "18723185" << endl;
  thread_wait(0, 1);
  thread_signal(0, 0);
  cout << "92432539" << endl;
  thread_wait(0, 0);
  cout << "41777561" << endl;
  thread_signal(1, 0);
  thread_yield();
  thread_unlock(1);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_lock(0);
  thread_lock(0);
  cout << "12635044" << endl;
  thread_unlock(1);
  cout << "11916644" << endl;
  thread_yield();
  thread_yield();
  thread_lock(1);
  thread_signal(0, 1);
  cout << "28420532" << endl;
  thread_unlock(1);
  cout << "55071125" << endl;
  thread_broadcast(1, 1);
  thread_wait(1, 1);
  cout << "123320477" << endl;
  cout << "38016309" << endl;
  thread_signal(1, 1);
  thread_signal(1, 1);
}

void xyz2(void* args) {
  thread_wait(5, 4);
  thread_yield();
  thread_lock(5);
  thread_signal(10, 9);
  cout << "71241179" << endl;
  thread_wait(6, 0);
  thread_lock(10);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(1);
  thread_lock(7);
  thread_broadcast(11, 12);
  thread_wait(10, 4);
  thread_yield();
  thread_wait(2, 7);
  thread_signal(3, 10);
  cout << "91842205" << endl;
  thread_wait(6, 1);
  thread_wait(8, 10);
  thread_yield();
  thread_broadcast(1, 12);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(5, 0);
  thread_yield();
  thread_wait(4, 8);
  thread_broadcast(2, 1);
  thread_broadcast(6, 6);
  thread_signal(2, 0);
  thread_unlock(10);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(3);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
    thread_yield();
  }
  thread_signal(0, 9);
  thread_lock(2);
  thread_broadcast(10, 5);
  thread_yield();
  thread_yield();
  thread_wait(9, 7);
  thread_unlock(9);
  thread_unlock(0);
  thread_yield();
  thread_lock(7);
  thread_signal(7, 3);
  thread_broadcast(7, 0);
  thread_yield();
  thread_unlock(10);
  thread_wait(4, 4);
  cout << "68365826" << endl;
  thread_yield();
  thread_wait(12, 7);
  cout << "53042391" << endl;
  thread_broadcast(11, 9);
  thread_yield();
}

void xyz3(void* args) {
  thread_yield();
  thread_yield();
  thread_yield();
  thread_lock(2);
  cout << "13156092" << endl;
  cout << "7417887" << endl;
  thread_lock(1);
  thread_unlock(2);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(3, 5);
  thread_broadcast(5, 4);
  thread_unlock(3);
  thread_signal(2, 6);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_wait(5, 1);
  thread_wait(6, 1);
  thread_broadcast(3, 0);
  thread_yield();
  thread_wait(2, 3);
  thread_yield();
  thread_yield();
  cout << "7860696" << endl;
  thread_yield();
}

void xyz4(void* args) {
  thread_yield();
  thread_broadcast(6, 7);
  thread_yield();
  thread_wait(6, 6);
  thread_yield();
  cout << "105733868" << endl;
  thread_yield();
  thread_yield();
  cout << "45644916" << endl;
  thread_lock(7);
  thread_wait(1, 0);
  thread_wait(0, 3);
  thread_lock(8);
  thread_broadcast(4, 1);
  thread_yield();
  thread_broadcast(5, 8);
  thread_broadcast(5, 8);
  cout << "25059245" << endl;
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_signal(3, 5);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(0, 1);
  thread_broadcast(7, 0);
  thread_broadcast(7, 8);
  thread_wait(8, 4);
  thread_yield();
  cout << "74975178" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(3, 0);
  thread_broadcast(7, 8);
  thread_signal(3, 5);
  thread_yield();
  thread_unlock(1);
  thread_yield();
  thread_lock(5);
  cout << "18903066" << endl;
  cout << "28058551" << endl;
  thread_wait(3, 8);
  thread_wait(4, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(2);
  thread_yield();
  thread_wait(3, 7);
  thread_unlock(5);
}

void xyz5(void* args) {
  thread_yield();
  thread_yield();
  thread_unlock(11);
  thread_wait(14, 4);
  thread_yield();
  thread_lock(14);
  thread_yield();
  thread_broadcast(10, 12);
  thread_yield();
  thread_signal(17, 3);
  thread_yield();
  thread_yield();
  thread_unlock(5);
  thread_unlock(6);
  cout << "1183918" << endl;
  thread_unlock(12);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(16, 10);
  thread_lock(14);
  thread_broadcast(6, 14);
  thread_unlock(18);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_wait(7, 16);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(6, 16);
  thread_unlock(3);
  thread_unlock(11);
  thread_broadcast(2, 1);
  thread_lock(2);
  thread_yield();
  thread_yield();
  thread_wait(8, 14);
  thread_signal(1, 5);
  thread_yield();
  thread_unlock(6);
  thread_yield();
  thread_signal(12, 4);
  thread_yield();
  thread_yield();
  thread_signal(3, 16);
  thread_yield();
  thread_yield();
  thread_broadcast(8, 2);
  thread_yield();
  thread_lock(11);
  thread_signal(8, 17);
  thread_yield();
  thread_wait(7, 12);
  thread_yield();
  thread_lock(15);
  thread_lock(7);
  thread_signal(10, 6);
  thread_yield();
  thread_yield();
  thread_signal(11, 10);
  thread_yield();
  thread_broadcast(1, 6);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(4, 8);
  thread_yield();
  thread_signal(9, 13);
  thread_unlock(12);
  thread_lock(2);
  thread_yield();
  thread_yield();
  thread_signal(9, 15);
  thread_yield();
  thread_wait(0, 3);
  thread_broadcast(8, 6);
  thread_broadcast(9, 3);
  thread_wait(16, 6);
  thread_lock(14);
  thread_yield();
  cout << "1179916" << endl;
  thread_unlock(1);
  thread_wait(15, 11);
  thread_lock(14);
  thread_yield();
  thread_broadcast(0, 8);
  thread_signal(2, 14);
  cout << "912029" << endl;
  thread_broadcast(1, 7);
  thread_wait(14, 1);
  thread_yield();
  thread_signal(16, 0);
  thread_lock(15);
  thread_yield();
  thread_yield();
  thread_lock(13);
  thread_yield();
  thread_lock(0);
  thread_signal(13, 4);
  thread_broadcast(17, 11);
  cout << "149146" << endl;
  thread_yield();
  thread_wait(5, 10);
  cout << "812226" << endl;
  thread_broadcast(17, 12);
  thread_unlock(7);
  thread_wait(10, 10);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_yield();
  thread_broadcast(8, 15);
  thread_unlock(4);
  thread_lock(7);
  thread_yield();
  thread_lock(14);
  thread_signal(16, 15);
  thread_lock(5);
  thread_wait(3, 13);
  thread_yield();
  thread_wait(9, 5);
  thread_signal(11, 11);
  cout << "1183238" << endl;
}

void xyz6(void* args) {
  cout << "413101" << endl;
  thread_yield();
  thread_signal(0, 1);
  thread_yield();
  thread_wait(1, 2);
  thread_unlock(0);
  thread_wait(0, 2);
  thread_signal(0, 3);
  thread_wait(2, 1);
  cout << "488181" << endl;
  thread_lock(1);
  thread_wait(0, 2);
  thread_yield();
  cout << "1182831" << endl;
  thread_signal(0, 1);
  thread_wait(1, 1);
  thread_broadcast(3, 3);
  thread_yield();
  cout << "1229818" << endl;
  cout << "1178245" << endl;
  thread_yield();
  thread_yield();
  thread_signal(3, 1);
  thread_unlock(2);
  thread_signal(0, 1);
  thread_unlock(1);
  thread_yield();
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_unlock(1);
  cout << "52375" << endl;
  thread_yield();
  thread_yield();
  thread_broadcast(0, 1);
  thread_wait(1, 3);
  thread_unlock(2);
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_broadcast(2, 3);
  thread_signal(2, 3);
  thread_yield();
  thread_wait(2, 2);
  thread_wait(3, 0);
}

void xyz7(void* args) {
  thread_yield();
  thread_signal(5, 6);
  thread_yield();
  thread_wait(7, 1);
  thread_unlock(5);
  thread_wait(6, 11);
  thread_yield();
  cout << "3065728" << endl;
  thread_unlock(5);
  thread_lock(4);
  thread_wait(0, 5);
  thread_lock(13);
  cout << "2257822" << endl;
  thread_signal(13, 0);
  thread_yield();
  thread_wait(5, 7);
  thread_yield();
  thread_yield();
  thread_wait(5, 10);
  thread_yield();
  thread_wait(4, 7);
  thread_lock(10);
  thread_lock(12);
  thread_broadcast(4, 11);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(13, 8);
  thread_yield();
  thread_yield();
  thread_unlock(2);
  thread_broadcast(10, 0);
  thread_wait(9, 9);
  thread_unlock(13);
  thread_yield();
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_lock(10);
  thread_wait(0, 7);
  thread_signal(1, 9);
  thread_broadcast(4, 8);
  thread_yield();
  thread_signal(11, 12);
  thread_broadcast(5, 2);
  cout << "3305435" << endl;
  cout << "2405847" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(6);
  thread_yield();
  cout << "872189" << endl;
  thread_wait(8, 9);
  thread_yield();
  thread_lock(13);
  thread_lock(5);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  cout << "2180838" << endl;
  thread_wait(8, 11);
  thread_signal(1, 13);
  cout << "1857485" << endl;
  thread_signal(8, 1);
  thread_broadcast(11, 5);
  thread_yield();
  thread_unlock(6);
  thread_wait(11, 9);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
    thread_yield();
  }
  thread_lock(12);
  thread_yield();
  thread_unlock(13);
  cout << "2384493" << endl;
  thread_signal(13, 13);
  cout << "2879257" << endl;
  thread_broadcast(9, 11);
  thread_signal(10, 9);
  thread_yield();
  cout << "21261" << endl;
  cout << "2044550" << endl;
  thread_yield();
  thread_yield();
  thread_unlock(4);
  thread_wait(8, 2);
  thread_yield();
  thread_yield();
  thread_yield();
}

void xyz8(void* args) {
  thread_yield();
  thread_yield();
  thread_wait(0, 2);
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_yield();
  thread_yield();
  thread_lock(2);
  thread_wait(2, 1);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_unlock(2);
  thread_wait(2, 1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_lock(0);
  thread_wait(1, 2);
  thread_lock(0);
  thread_yield();
}

void xyz9(void* args) {
  cout << "894526" << endl;
  thread_yield();
  thread_lock(0);
  thread_signal(1, 1);
  thread_broadcast(1, 1);
  thread_signal(0, 0);
  thread_yield();
  thread_yield();
  thread_unlock(1);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_lock(0);
  thread_yield();
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_lock(1);
  thread_unlock(0);
  thread_lock(0);
  thread_yield();
  thread_yield();
  cout << "439210" << endl;
  thread_yield();
  thread_broadcast(1, 0);
  thread_yield();
  thread_signal(0, 1);
  thread_yield();
  thread_yield();
  thread_unlock(1);
  thread_yield();
  thread_yield();
  cout << "1226562" << endl;
  thread_yield();
  thread_wait(0, 1);
  thread_yield();
  thread_unlock(1);
  thread_unlock(0);
  thread_unlock(1);
  thread_signal(1, 1);
  thread_signal(0, 1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(1, 0);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 1);
  thread_yield();
  thread_broadcast(1, 0);
  thread_wait(0, 1);
  thread_signal(1, 0);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_yield();
  thread_lock(1);
  thread_signal(1, 1);
  thread_yield();
  thread_unlock(1);
  thread_unlock(1);
  thread_yield();
  thread_broadcast(1, 0);
  thread_signal(1, 0);
  thread_wait(0, 1);
  thread_yield();
  cout << "823261" << endl;
  thread_unlock(0);
  thread_yield();
  cout << "376339" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_lock(0);
  thread_broadcast(0, 1);
  thread_yield();
  cout << "2187609" << endl;
  thread_signal(1, 1);
  cout << "175682" << endl;
  thread_wait(1, 0);
  thread_signal(1, 1);
  thread_lock(0);
  thread_yield();
}

void xyz10(void* args) {
  thread_yield();
  thread_yield();
  thread_unlock(3);
  thread_yield();
  thread_unlock(0);
  thread_unlock(3);
  thread_yield();
  thread_lock(3);
  thread_broadcast(2, 3);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_broadcast(0, 1);
  thread_yield();
  thread_lock(2);
  thread_yield();
  thread_wait(4, 3);
  thread_yield();
  thread_yield();
  thread_lock(1);
  thread_yield();
  thread_unlock(4);
  thread_yield();
  thread_broadcast(0, 2);
  thread_wait(0, 0);
  thread_signal(1, 5);
  cout << "59819" << endl;
  cout << "216883" << endl;
  thread_wait(3, 3);
  thread_unlock(0);
  thread_yield();
  thread_unlock(2);
  thread_yield();
  thread_signal(4, 0);
  thread_yield();
  thread_wait(4, 2);
  thread_broadcast(0, 2);
  thread_broadcast(0, 1);
  thread_yield();
  thread_broadcast(4, 2);
  thread_unlock(1);
  thread_yield();
  thread_lock(0);
  thread_yield();
  cout << "183449" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(2, 1);
  thread_yield();
  thread_signal(3, 2);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_wait(4, 0);
  thread_unlock(0);
  thread_yield();
  thread_yield();
  thread_unlock(4);
  thread_yield();
  cout << "224457" << endl;
  thread_yield();
  thread_signal(3, 3);
}

void maker(void *args) {
  thread_wait(1, 0);
  thread_create((thread_startfunc_t) xyz1, (void *) 100);
  thread_yield();
  thread_signal(1, 1);
  thread_signal(0, 1);
  thread_create((thread_startfunc_t) xyz2, (void *) 100);
  thread_create((thread_startfunc_t) xyz3, (void *) 100);
  thread_broadcast(1, 0);
  thread_wait(0, 1);
  thread_create((thread_startfunc_t) xyz4, (void *) 100);
  thread_lock(1);
  thread_create((thread_startfunc_t) xyz5, (void *) 100);
  thread_create((thread_startfunc_t) xyz6, (void *) 100);
  thread_create((thread_startfunc_t) xyz7, (void *) 100);
  thread_yield();
  thread_create((thread_startfunc_t) xyz8, (void *) 100);
  thread_create((thread_startfunc_t) xyz9, (void *) 100);
  thread_wait(1, 0);
  thread_broadcast(1, 0);
  thread_yield();
  thread_create((thread_startfunc_t) xyz10, (void *) 100);
  thread_unlock(1);
  thread_broadcast(1, 0);
  thread_lock(1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(1, 1);
  thread_wait(0, 1);
  thread_lock(0);
  thread_yield();
  thread_lock(1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(0, 0);
  thread_wait(0, 1);
  thread_yield();
  thread_broadcast(1, 0);
  thread_unlock(0);
  thread_yield();
  thread_yield();
  thread_unlock(1);
  thread_wait(0, 1);
  thread_lock(0);
  thread_signal(0, 1);
  thread_yield();
  thread_wait(0, 1);
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_yield();
  thread_broadcast(0, 1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(0, 0);
  thread_unlock(1);
  thread_unlock(1);
  thread_yield();
  thread_lock(0);
  thread_wait(0, 1);
  thread_unlock(1);
  thread_yield();
  thread_wait(1, 0);
  thread_unlock(0);
  thread_unlock(0);
  thread_lock(1);
  thread_yield();
  thread_signal(0, 0);
  thread_wait(1, 0);
  thread_yield();
  thread_yield();
  thread_signal(0, 1);
  thread_yield();
  thread_unlock(1);
  thread_signal(1, 0);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_broadcast(0, 0);
  thread_yield();
  thread_lock(1);
  thread_signal(1, 1);
  thread_signal(0, 1);
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

int main(int argc, char *argv[]) {
  thread_libinit((thread_startfunc_t)maker, &argc);
}
