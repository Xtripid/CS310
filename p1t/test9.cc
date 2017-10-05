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
  thread_wait(1, 1);
  thread_wait(0, 1);
  thread_broadcast(1, 0);
  thread_signal(0, 1);
  thread_broadcast(1, 1);
  thread_wait(1, 0);
  thread_wait(1, 1);
  thread_wait(1, 1);
  thread_unlock(0);
  thread_unlock(1);
  cout << "80018329" << endl;
  thread_signal(1, 0);
  cout << "90299533" << endl;
  thread_signal(0, 1);
  thread_unlock(0);
  thread_signal(1, 1);
  thread_lock(1);
  thread_signal(1, 0);
  thread_broadcast(1, 1);
  thread_wait(0, 1);
  thread_broadcast(1, 0);
  cout << "84764187" << endl;
  thread_wait(1, 1);
  thread_yield();
  thread_wait(0, 1);
  thread_unlock(0);
  thread_unlock(1);
  thread_wait(0, 1);
  thread_lock(1);
  thread_lock(1);
  thread_signal(0, 0);
  cout << "65633698" << endl;
  thread_broadcast(0, 0);
  cout << "96257582" << endl;
  thread_wait(1, 0);
  thread_unlock(0);
  thread_signal(1, 0);
  thread_wait(1, 1);
  thread_unlock(1);
  thread_wait(1, 0);
  thread_broadcast(0, 1);
  cout << "34572799" << endl;
  thread_lock(0);
  thread_yield();
  thread_unlock(0);
  cout << "78217455" << endl;
  cout << "96998736" << endl;
  cout << "11518016" << endl;
  thread_signal(1, 0);
  thread_lock(0);
  cout << "6881771" << endl;
  thread_signal(1, 0);
  thread_lock(1);
  cout << "19651900" << endl;
  thread_broadcast(0, 1);
  thread_yield();
  thread_signal(1, 1);
  thread_wait(1, 1);
  thread_broadcast(1, 0);
  thread_broadcast(0, 1);
  thread_unlock(1);
  thread_lock(1);
  thread_unlock(1);
  thread_signal(0, 1);
  thread_broadcast(0, 0);
  thread_lock(0);
  thread_wait(1, 0);
  thread_unlock(0);
  thread_signal(1, 1);
  thread_broadcast(1, 1);
  cout << "70118939" << endl;
  thread_broadcast(0, 1);
  cout << "103562321" << endl;
  thread_broadcast(1, 0);
  thread_signal(0, 1);
  thread_wait(1, 0);
  thread_lock(0);
  cout << "7991006" << endl;
  thread_broadcast(1, 0);
  thread_broadcast(0, 0);
  thread_wait(1, 0);
  thread_broadcast(1, 0);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
    thread_yield();
  }
  thread_lock(0);
  cout << "11774748" << endl;
  thread_signal(1, 1);
  thread_unlock(0);
  thread_unlock(0);
  thread_signal(1, 1);
  thread_signal(1, 0);
  thread_unlock(1);
  thread_broadcast(1, 1);
  cout << "75005276" << endl;
  thread_lock(0);
  thread_signal(1, 1);
  thread_lock(1);
  thread_unlock(1);
  cout << "81931466" << endl;
  thread_unlock(0);
  thread_lock(0);
  thread_unlock(0);
  thread_signal(1, 1);
  thread_wait(1, 0);
  thread_broadcast(0, 1);
  thread_broadcast(1, 0);
  thread_wait(0, 0);
  thread_broadcast(0, 1);
  thread_signal(1, 0);
  thread_lock(0);
  thread_signal(1, 1);
  thread_broadcast(0, 0);
  thread_signal(0, 1);
  cout << "74032069" << endl;
  thread_lock(1);
  thread_broadcast(0, 0);
  thread_broadcast(0, 0);
  thread_wait(0, 1);
  thread_unlock(0);
  cout << "35995491" << endl;
  thread_unlock(1);
  thread_broadcast(1, 0);
  thread_unlock(1);
  thread_wait(1, 1);
  cout << "43059731" << endl;
  thread_broadcast(1, 0);
  thread_signal(1, 0);
  thread_signal(0, 1);
  cout << "95539320" << endl;
  cout << "91078066" << endl;
  thread_broadcast(0, 0);
  thread_lock(0);
  cout << "68159417" << endl;
  thread_wait(0, 0);
  thread_signal(1, 0);
  thread_wait(1, 0);
  thread_wait(0, 0);
  thread_lock(1);
  thread_signal(1, 0);
  thread_unlock(1);
  thread_wait(1, 0);
  thread_lock(0);
  thread_signal(0, 1);
  thread_unlock(0);
  thread_unlock(1);
  thread_yield();
  thread_lock(1);
  thread_broadcast(0, 1);
  cout << "119023440" << endl;
  thread_unlock(0);
  thread_signal(0, 1);
  thread_signal(0, 0);
}

void xyz2(void* args) {
  thread_yield();
  thread_wait(10, 9);
  thread_signal(9, 12);
  thread_wait(12, 12);
  thread_wait(1, 9);
  thread_yield();
  thread_wait(5, 5);
  thread_wait(4, 12);
  thread_yield();
  thread_yield();
  thread_unlock(11);
  thread_yield();
  thread_broadcast(5, 7);
  thread_unlock(0);
  thread_lock(8);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(2, 3);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_signal(0, 3);
  thread_yield();
  thread_signal(7, 5);
  thread_yield();
  thread_yield();
  thread_unlock(4);
  thread_signal(8, 8);
  thread_broadcast(10, 11);
  thread_signal(7, 9);
  cout << "25315981" << endl;
  thread_yield();
  thread_unlock(4);
  thread_wait(5, 8);
  thread_signal(4, 0);
  cout << "28531479" << endl;
  thread_yield();
  thread_yield();
  thread_broadcast(8, 3);
  thread_broadcast(8, 3);
  thread_yield();
  thread_lock(4);
  thread_broadcast(6, 5);
  thread_yield();
  thread_yield();
  thread_unlock(6);
  thread_lock(0);
  thread_unlock(12);
  thread_yield();
  thread_signal(6, 6);
  thread_unlock(2);
  thread_yield();
  thread_yield();
  thread_unlock(12);
  thread_unlock(3);
  cout << "101107546" << endl;
  thread_yield();
  thread_broadcast(5, 12);
  thread_wait(12, 12);
  thread_lock(8);
  thread_signal(9, 4);
  thread_lock(0);
}

void xyz3(void* args) {
  thread_lock(3);
  cout << "8715832" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_lock(0);
  thread_broadcast(1, 6);
  thread_wait(3, 1);
  thread_unlock(5);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_unlock(2);
  thread_yield();
  thread_broadcast(4, 1);
  thread_broadcast(4, 4);
  thread_broadcast(6, 6);
  thread_yield();
  cout << "8272250" << endl;
  thread_yield();
  thread_unlock(0);
  thread_broadcast(0, 5);
  cout << "6314266" << endl;
  thread_broadcast(4, 2);
  thread_yield();
  thread_broadcast(5, 3);
}

void xyz4(void* args) {
  thread_yield();
  thread_yield();
  thread_lock(2);
  thread_unlock(4);
  cout << "105015843" << endl;
  thread_lock(1);
  cout << "41684947" << endl;
  thread_lock(1);
  thread_signal(4, 7);
  thread_yield();
  thread_yield();
  thread_lock(8);
  thread_yield();
  thread_yield();
  thread_broadcast(8, 8);
  thread_signal(0, 0);
  thread_lock(3);
  thread_unlock(3);
  cout << "69311346" << endl;
  thread_wait(4, 1);
  thread_yield();
  thread_signal(2, 8);
  thread_yield();
  thread_lock(7);
  cout << "97085138" << endl;
  thread_yield();
  thread_broadcast(0, 5);
  cout << "113505129" << endl;
  thread_signal(1, 7);
  thread_wait(0, 0);
  thread_lock(6);
  thread_broadcast(8, 6);
  thread_signal(6, 1);
  cout << "45624144" << endl;
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_yield();
  cout << "51417290" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(3, 2);
  thread_broadcast(5, 2);
  thread_yield();
  thread_wait(5, 0);
  thread_yield();
  cout << "47749836" << endl;
  thread_unlock(5);
  thread_broadcast(2, 2);
  thread_wait(6, 8);
  thread_yield();
}

void xyz5(void* args) {
  thread_yield();
  thread_wait(4, 10);
  thread_unlock(1);
  thread_yield();
  thread_lock(8);
  thread_yield();
  thread_lock(18);
  thread_yield();
  thread_signal(17, 13);
  thread_unlock(1);
  cout << "546251" << endl;
  thread_yield();
  thread_yield();
  thread_broadcast(13, 9);
  cout << "607443" << endl;
  thread_broadcast(13, 11);
  thread_broadcast(16, 2);
  thread_signal(7, 13);
  thread_unlock(9);
  cout << "3810" << endl;
  thread_unlock(16);
  thread_unlock(18);
  thread_unlock(1);
  thread_wait(4, 9);
  thread_signal(0, 18);
  thread_signal(3, 11);
  cout << "798026" << endl;
  cout << "904170" << endl;
  thread_signal(13, 15);
  thread_yield();
  thread_lock(9);
  thread_broadcast(2, 18);
  cout << "733663" << endl;
  thread_broadcast(10, 3);
  thread_yield();
  thread_lock(7);
  thread_yield();
  cout << "123455" << endl;
  thread_yield();
  thread_yield();
  cout << "304282" << endl;
  thread_lock(15);
  thread_wait(12, 7);
  thread_yield();
  thread_yield();
  thread_lock(15);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_broadcast(10, 14);
  thread_broadcast(0, 3);
  cout << "907961" << endl;
  thread_broadcast(14, 3);
  thread_unlock(0);
  thread_yield();
  thread_unlock(5);
  cout << "216670" << endl;
  thread_yield();
  thread_yield();
  thread_signal(1, 1);
  thread_lock(7);
  thread_yield();
  thread_signal(11, 5);
  thread_broadcast(2, 9);
  thread_wait(13, 15);
  thread_yield();
  thread_lock(0);
  thread_signal(1, 10);
  thread_broadcast(8, 6);
  thread_yield();
  thread_yield();
  cout << "393784" << endl;
  thread_yield();
  thread_wait(2, 18);
  thread_lock(11);
  thread_signal(6, 10);
  thread_yield();
  thread_yield();
  thread_broadcast(9, 3);
  thread_broadcast(18, 1);
  thread_signal(10, 18);
  thread_unlock(14);
  thread_yield();
  thread_unlock(1);
  thread_unlock(4);
  thread_lock(3);
  thread_wait(0, 17);
  thread_yield();
  thread_yield();
  thread_lock(6);
  thread_lock(4);
  cout << "839786" << endl;
  thread_yield();
  thread_unlock(7);
  thread_yield();
  cout << "209594" << endl;
  thread_yield();
  thread_yield();
  thread_wait(5, 5);
  thread_broadcast(2, 8);
  thread_signal(13, 7);
  thread_lock(4);
  thread_wait(13, 3);
  thread_broadcast(5, 11);
  thread_broadcast(18, 0);
  thread_yield();
  thread_signal(6, 9);
  thread_yield();
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
    thread_yield();
  }
  thread_yield();
  thread_wait(15, 15);
  thread_broadcast(9, 14);
  thread_wait(7, 18);
  thread_unlock(9);
  thread_yield();
  thread_yield();
  thread_unlock(2);
  thread_broadcast(5, 4);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(4, 4);
  thread_lock(12);
  thread_yield();
}

void xyz6(void* args) {
  thread_yield();
  thread_yield();
  cout << "688148" << endl;
  thread_signal(3, 2);
  thread_yield();
  thread_yield();
  thread_unlock(1);
  thread_wait(3, 2);
  thread_signal(2, 1);
  thread_yield();
  thread_yield();
  cout << "557575" << endl;
  thread_unlock(1);
  thread_signal(1, 3);
  cout << "359471" << endl;
  thread_wait(1, 1);
  thread_lock(2);
  thread_wait(3, 1);
  thread_signal(0, 2);
  thread_wait(2, 2);
  thread_yield();
  thread_signal(3, 3);
  thread_wait(0, 1);
  thread_wait(1, 3);
  cout << "22793" << endl;
  thread_yield();
  thread_lock(3);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_unlock(1);
  thread_signal(2, 3);
  thread_yield();
  thread_yield();
  thread_broadcast(3, 2);
  thread_lock(0);
  thread_broadcast(2, 0);
  thread_unlock(2);
  thread_yield();
  thread_lock(2);
  thread_unlock(3);
  thread_unlock(1);
  thread_yield();
  thread_yield();
}

void xyz7(void* args) {
  thread_unlock(10);
  cout << "2598492" << endl;
  thread_signal(8, 1);
  thread_yield();
  cout << "161826" << endl;
  thread_yield();
  thread_signal(3, 8);
  thread_yield();
  thread_yield();
  thread_signal(12, 0);
  thread_yield();
  thread_yield();
  thread_signal(2, 13);
  thread_yield();
  thread_unlock(12);
  thread_broadcast(3, 4);
  thread_yield();
  thread_lock(7);
  thread_lock(10);
  thread_yield();
  thread_signal(0, 6);
  thread_yield();
  thread_yield();
  thread_wait(8, 13);
  thread_signal(9, 9);
  thread_wait(8, 13);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_lock(12);
  thread_wait(9, 13);
  thread_unlock(4);
  thread_yield();
  thread_yield();
  thread_lock(6);
  thread_lock(5);
  thread_unlock(0);
  cout << "194621" << endl;
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_yield();
  thread_lock(7);
  thread_yield();
  thread_broadcast(1, 7);
  cout << "429724" << endl;
  thread_lock(2);
  thread_unlock(7);
  thread_yield();
  cout << "529001" << endl;
  cout << "1693097" << endl;
  thread_yield();
  thread_signal(3, 10);
  thread_unlock(9);
  thread_lock(10);
  thread_signal(11, 4);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(12, 10);
  thread_yield();
  thread_broadcast(5, 5);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(6, 0);
  thread_signal(7, 13);
  thread_wait(13, 3);
  thread_broadcast(0, 0);
  thread_unlock(12);
  cout << "2956146" << endl;
  thread_wait(12, 8);
  thread_broadcast(8, 9);
  thread_yield();
  thread_wait(2, 6);
  thread_lock(13);
  thread_lock(1);
  thread_wait(2, 5);
  cout << "3086994" << endl;
  thread_broadcast(6, 4);
  cout << "1907251" << endl;
  thread_yield();
  thread_lock(4);
  thread_yield();
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_unlock(10);
  thread_wait(6, 3);
  thread_signal(10, 9);
  thread_wait(5, 8);
  thread_yield();
  thread_yield();
}

void xyz8(void* args) {
  cout << "3938" << endl;
  thread_yield();
  thread_signal(1, 0);
  cout << "21403" << endl;
  thread_yield();
  cout << "678" << endl;
  thread_signal(2, 2);
  thread_unlock(1);
  thread_yield();
  thread_yield();
  cout << "3410" << endl;
  thread_wait(2, 1);
  thread_yield();
  thread_yield();
  cout << "17147" << endl;
  thread_signal(1, 1);
  thread_wait(2, 0);
  thread_yield();
  cout << "8198" << endl;
  thread_signal(0, 0);
}

void xyz9(void* args) {
  thread_lock(0);
  thread_unlock(1);
  thread_yield();
  thread_yield();
  thread_signal(0, 1);
  thread_broadcast(1, 0);
  thread_yield();
  thread_wait(1, 0);
  thread_wait(0, 1);
  thread_yield();
  thread_unlock(1);
  thread_broadcast(1, 0);
  thread_signal(1, 1);
  thread_yield();
  thread_lock(1);
  thread_broadcast(0, 0);
  thread_yield();
  cout << "221130" << endl;
  thread_lock(1);
  cout << "1351024" << endl;
  thread_yield();
  thread_yield();
  thread_lock(1);
  thread_signal(1, 0);
  thread_yield();
  thread_unlock(0);
  thread_yield();
  thread_lock(0);
  thread_yield();
  thread_lock(1);
  thread_yield();
  thread_unlock(0);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_unlock(0);
  thread_unlock(0);
  thread_unlock(0);
  thread_yield();
  thread_lock(0);
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_lock(0);
  thread_wait(1, 0);
  thread_yield();
  thread_unlock(1);
  thread_yield();
  thread_broadcast(0, 1);
  cout << "2091141" << endl;
  thread_wait(1, 0);
  thread_broadcast(0, 1);
  thread_broadcast(0, 1);
  thread_wait(0, 1);
  thread_unlock(0);
  thread_yield();
  thread_signal(0, 0);
  thread_yield();
  thread_wait(0, 1);
  thread_yield();
  thread_unlock(0);
  thread_wait(0, 0);
  thread_lock(0);
  thread_wait(1, 1);
  thread_yield();
  thread_wait(1, 0);
  thread_signal(1, 0);
  thread_signal(0, 1);
  thread_broadcast(0, 1);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
    thread_yield();
  }
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_yield();
  thread_signal(0, 1);
  thread_signal(1, 1);
  thread_signal(1, 0);
  thread_signal(0, 1);
  thread_yield();
  cout << "1497443" << endl;
  thread_yield();
  thread_yield();
  thread_signal(0, 1);
}

void xyz10(void* args) {
  thread_unlock(3);
  thread_yield();
  thread_broadcast(4, 3);
  thread_yield();
  thread_yield();
  cout << "38987" << endl;
  thread_signal(1, 4);
  thread_signal(2, 2);
  thread_unlock(2);
  thread_yield();
  thread_yield();
  thread_lock(4);
  cout << "89728" << endl;
  thread_broadcast(0, 5);
  thread_unlock(2);
  thread_yield();
  thread_broadcast(3, 3);
  cout << "233549" << endl;
  thread_lock(4);
  thread_wait(0, 1);
  thread_broadcast(4, 1);
  thread_lock(0);
  thread_broadcast(2, 4);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  cout << "86433" << endl;
  thread_yield();
  thread_lock(2);
  thread_yield();
  thread_yield();
  thread_signal(3, 2);
  thread_yield();
  thread_lock(4);
  cout << "6430" << endl;
  thread_signal(3, 3);
  thread_yield();
  thread_wait(4, 3);
  thread_yield();
  thread_yield();
  thread_signal(2, 2);
  cout << "162022" << endl;
  thread_unlock(3);
  thread_signal(1, 2);
  thread_yield();
  thread_broadcast(4, 1);
  thread_yield();
  thread_lock(4);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(2, 5);
  cout << "189977" << endl;
  thread_lock(2);
  thread_broadcast(2, 4);
  thread_broadcast(2, 4);
  thread_broadcast(1, 4);
  thread_signal(2, 5);
  thread_broadcast(2, 5);
  thread_unlock(3);
  thread_yield();
  thread_lock(2);
}

void maker(void *args) {
  thread_yield();
  thread_lock(1);
  thread_create((thread_startfunc_t) xyz1, (void *) 100);
  thread_create((thread_startfunc_t) xyz2, (void *) 100);
  thread_wait(0, 0);
  thread_signal(1, 1);
  thread_yield();
  thread_create((thread_startfunc_t) xyz3, (void *) 100);
  thread_signal(1, 0);
  thread_create((thread_startfunc_t) xyz4, (void *) 100);
  thread_broadcast(1, 1);
  thread_create((thread_startfunc_t) xyz5, (void *) 100);
  thread_unlock(0);
  thread_create((thread_startfunc_t) xyz6, (void *) 100);
  thread_signal(0, 0);
  thread_yield();
  thread_create((thread_startfunc_t) xyz7, (void *) 100);
  thread_create((thread_startfunc_t) xyz8, (void *) 100);
  thread_signal(0, 1);
  thread_create((thread_startfunc_t) xyz9, (void *) 100);
  thread_unlock(0);
  thread_lock(1);
  thread_signal(0, 0);
  thread_broadcast(1, 0);
  thread_broadcast(1, 1);
  thread_yield();
  thread_broadcast(1, 0);
  thread_create((thread_startfunc_t) xyz10, (void *) 100);
  thread_yield();
  thread_wait(1, 1);
  thread_yield();
  thread_wait(1, 1);
  thread_broadcast(1, 1);
  thread_broadcast(1, 1);
  thread_yield();
  thread_signal(0, 1);
  thread_yield();
  thread_yield();
  thread_lock(1);
  thread_yield();
  thread_broadcast(1, 0);
  thread_yield();
  thread_wait(0, 0);
  thread_lock(0);
  thread_yield();
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(1, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_signal(0, 1);
  thread_broadcast(1, 0);
  thread_unlock(1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(0, 1);
  thread_yield();
  thread_broadcast(0, 0);
  thread_yield();
  thread_yield();
  thread_signal(1, 1);
  thread_lock(0);
  thread_yield();
  thread_wait(0, 0);
  thread_signal(0, 1);
  thread_unlock(0);
  thread_unlock(1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(1, 0);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(0, 1);
  thread_yield();
  thread_broadcast(0, 1);
  thread_yield();
  thread_lock(1);
  thread_signal(1, 1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(1, 1);
  thread_lock(1);
}

int main(int argc, char *argv[]) {
  thread_libinit((thread_startfunc_t)maker, &argc);
}