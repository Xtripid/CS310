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
  thread_unlock(1);
  thread_unlock(0);
  thread_unlock(0);
  thread_wait(1, 0);
  thread_signal(1, 1);
  cout << "25489640" << endl;
  thread_lock(1);
  thread_broadcast(0, 1);
  thread_broadcast(1, 0);
  thread_unlock(1);
  thread_signal(0, 1);
  cout << "118234876" << endl;
  thread_broadcast(0, 1);
  thread_lock(0);
  thread_signal(0, 0);
  thread_broadcast(1, 1);
  thread_signal(0, 1);
  thread_wait(1, 1);
  thread_unlock(1);
  thread_lock(0);
  thread_wait(1, 1);
  thread_yield();
  thread_signal(1, 0);
  thread_broadcast(1, 1);
  thread_broadcast(0, 1);
  thread_yield();
  cout << "52252359" << endl;
  thread_unlock(1);
  thread_signal(1, 1);
  thread_broadcast(1, 0);
  thread_wait(1, 0);
  cout << "51666920" << endl;
  thread_unlock(0);
  thread_yield();
  thread_signal(0, 0);
  cout << "8348989" << endl;
  thread_unlock(0);
  thread_wait(0, 0);
  thread_yield();
  thread_unlock(0);
  thread_unlock(1);
  thread_unlock(0);
  thread_signal(1, 1);
  thread_broadcast(0, 0);
  thread_lock(0);
  thread_wait(1, 0);
  thread_signal(1, 1);
  thread_lock(1);
  thread_signal(0, 1);
  thread_signal(1, 0);
  thread_yield();
  thread_lock(0);
  thread_yield();
  thread_yield();
  cout << "11312811" << endl;
  cout << "82229765" << endl;
  cout << "10505411" << endl;
  thread_signal(1, 1);
  thread_wait(1, 1);
  thread_unlock(0);
  thread_broadcast(0, 1);
  thread_broadcast(0, 1);
  cout << "116000070" << endl;
  thread_unlock(0);
  thread_yield();
  thread_lock(1);
  thread_unlock(1);
  thread_unlock(1);
  thread_lock(1);
  thread_lock(1);
  thread_yield();
  thread_lock(1);
  thread_signal(1, 1);
  thread_broadcast(0, 1);
  thread_lock(1);
  thread_yield();
  thread_lock(1);
  cout << "81856809" << endl;
  thread_signal(0, 0);
  thread_lock(0);
  thread_yield();
  thread_broadcast(1, 1);
  thread_unlock(0);
  thread_signal(1, 0);
  thread_broadcast(1, 0);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_lock(1);
  thread_lock(1);
  thread_yield();
  thread_broadcast(0, 1);
  thread_broadcast(1, 0);
  thread_wait(1, 0);
  thread_broadcast(1, 0);
  thread_lock(0);
  thread_yield();
  thread_lock(0);
  thread_lock(1);
  thread_signal(0, 0);
  cout << "94264009" << endl;
  thread_wait(1, 0);
  thread_broadcast(1, 0);
  thread_unlock(0);
  cout << "23583537" << endl;
  thread_unlock(0);
  thread_yield();
  cout << "66824255" << endl;
  thread_yield();
  cout << "23408532" << endl;
  thread_lock(0);
  thread_lock(1);
  thread_unlock(0);
  thread_unlock(0);
  thread_lock(1);
  thread_signal(0, 0);
  thread_signal(1, 1);
  thread_broadcast(1, 0);
  thread_yield();
  thread_signal(1, 1);
  thread_unlock(0);
  thread_unlock(1);
  thread_wait(0, 0);
  thread_signal(0, 0);
  thread_lock(1);
  thread_signal(0, 0);
  thread_wait(0, 0);
  thread_broadcast(0, 0);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_wait(1, 0);
  thread_broadcast(1, 1);
  thread_yield();
  thread_signal(0, 1);
  thread_lock(1);
  thread_unlock(0);
  thread_lock(1);
  thread_broadcast(0, 0);
  thread_lock(0);
  thread_unlock(0);
  thread_yield();
  thread_wait(0, 0);
  thread_lock(1);
  thread_unlock(1);
  thread_signal(1, 1);
  thread_unlock(0);
  thread_yield();
  thread_wait(1, 1);
  thread_broadcast(1, 0);
  thread_broadcast(0, 0);
  cout << "32762981" << endl;
  thread_signal(0, 0);
  thread_unlock(1);
  thread_wait(1, 0);
  thread_lock(1);
}

void xyz2(void* args) {
  thread_wait(6, 6);
  thread_yield();
  thread_wait(2, 10);
  thread_yield();
  thread_yield();
  cout << "13862293" << endl;
  cout << "117846683" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_wait(9, 6);
  thread_broadcast(3, 12);
  thread_yield();
  thread_wait(8, 7);
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(7, 5);
  thread_unlock(9);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_lock(2);
  thread_signal(2, 11);
  thread_unlock(8);
  thread_unlock(7);
  thread_yield();
  thread_broadcast(1, 6);
  thread_yield();
  thread_yield();
  cout << "44478749" << endl;
  thread_lock(4);
  thread_wait(9, 1);
  thread_yield();
  cout << "109999086" << endl;
  thread_lock(6);
  thread_lock(8);
  thread_lock(8);
  cout << "113094168" << endl;
  thread_wait(12, 4);
  thread_yield();
  thread_signal(9, 4);
  thread_unlock(10);
  thread_wait(10, 3);
  thread_lock(9);
  thread_signal(7, 3);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(8);
  thread_broadcast(5, 5);
  thread_lock(12);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  cout << "31253053" << endl;
  thread_broadcast(9, 11);
  cout << "55571978" << endl;
  thread_lock(10);
}

void xyz3(void* args) {
  thread_broadcast(0, 5);
  thread_yield();
  thread_broadcast(0, 2);
  thread_signal(6, 4);
  cout << "4608447" << endl;
  thread_lock(1);
  thread_yield();
  thread_yield();
  thread_wait(6, 5);
  thread_wait(6, 6);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_broadcast(5, 0);
  thread_broadcast(6, 0);
  thread_yield();
  thread_signal(4, 3);
  thread_broadcast(6, 5);
  thread_broadcast(1, 3);
  thread_yield();
  thread_yield();
  cout << "9782669" << endl;
  thread_signal(1, 6);
  thread_lock(1);
  thread_lock(6);
  thread_wait(0, 3);
  thread_yield();
  thread_yield();
}

void xyz4(void* args) {
  cout << "76754138" << endl;
  cout << "99861280" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(0, 7);
  thread_signal(4, 2);
  thread_signal(2, 7);
  thread_broadcast(1, 6);
  thread_yield();
  thread_yield();
  thread_broadcast(4, 6);
  thread_lock(3);
  cout << "43086835" << endl;
  thread_broadcast(2, 3);
  thread_wait(7, 0);
  thread_yield();
  thread_yield();
  thread_wait(7, 7);
  thread_yield();
  thread_wait(3, 6);
  thread_broadcast(4, 0);
  cout << "91145336" << endl;
  thread_yield();
  thread_broadcast(7, 2);
  thread_yield();
  thread_yield();
  thread_broadcast(8, 0);
  thread_yield();
  thread_yield();
  thread_signal(3, 8);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_unlock(8);
  thread_yield();
  thread_signal(0, 5);
  thread_yield();
  thread_unlock(8);
  thread_lock(1);
  thread_yield();
  thread_lock(4);
  cout << "45292605" << endl;
  thread_signal(0, 0);
  thread_yield();
  thread_unlock(7);
  thread_yield();
  thread_signal(0, 1);
  cout << "101440692" << endl;
  thread_yield();
  thread_signal(8, 7);
  thread_yield();
  thread_lock(6);
}

void xyz5(void* args) {
  thread_wait(2, 0);
  thread_unlock(11);
  thread_yield();
  thread_unlock(8);
  thread_unlock(7);
  thread_signal(15, 10);
  thread_lock(14);
  thread_lock(12);
  thread_broadcast(3, 2);
  cout << "813618" << endl;
  thread_signal(4, 11);
  cout << "212178" << endl;
  thread_yield();
  cout << "648727" << endl;
  thread_wait(6, 9);
  thread_yield();
  thread_lock(12);
  thread_yield();
  thread_yield();
  thread_wait(1, 18);
  cout << "743230" << endl;
  thread_broadcast(4, 15);
  thread_lock(18);
  thread_broadcast(5, 15);
  thread_unlock(16);
  thread_broadcast(5, 8);
  thread_wait(16, 5);
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_broadcast(17, 11);
  thread_wait(5, 12);
  thread_wait(6, 4);
  thread_signal(14, 12);
  thread_unlock(4);
  thread_signal(18, 5);
  thread_yield();
  thread_wait(9, 2);
  thread_signal(14, 4);
  cout << "729303" << endl;
  thread_broadcast(3, 16);
  thread_yield();
  thread_yield();
  thread_lock(17);
  thread_yield();
  cout << "138467" << endl;
  thread_broadcast(0, 4);
  thread_broadcast(6, 10);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(18, 13);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_lock(16);
  thread_wait(0, 18);
  cout << "61297" << endl;
  thread_broadcast(8, 9);
  thread_yield();
  thread_signal(2, 11);
  thread_lock(6);
  thread_signal(16, 1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(1, 9);
  thread_wait(16, 15);
  thread_yield();
  thread_wait(12, 8);
  thread_lock(1);
  thread_broadcast(15, 5);
  thread_yield();
  thread_lock(10);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(4, 15);
  thread_signal(9, 14);
  thread_lock(10);
  thread_wait(11, 18);
  cout << "695342" << endl;
  thread_yield();
  thread_yield();
  cout << "635114" << endl;
  thread_yield();
  thread_unlock(4);
  thread_broadcast(15, 11);
  thread_yield();
  thread_yield();
  thread_signal(16, 0);
  thread_yield();
  cout << "787548" << endl;
  thread_broadcast(17, 0);
  thread_signal(16, 4);
  thread_lock(5);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_yield();
  thread_unlock(15);
  thread_yield();
  cout << "216779" << endl;
  thread_lock(12);
  thread_yield();
  thread_lock(16);
  thread_yield();
  thread_yield();
  thread_broadcast(12, 5);
  thread_yield();
  thread_unlock(11);
  thread_broadcast(14, 16);
  thread_wait(9, 4);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(15, 10);
  thread_yield();
  thread_yield();
  thread_wait(11, 13);
  thread_signal(18, 6);
  thread_yield();
  thread_lock(4);
  thread_broadcast(14, 16);
}

void xyz6(void* args) {
  thread_signal(0, 0);
  thread_wait(3, 0);
  thread_yield();
  thread_unlock(1);
  thread_wait(2, 3);
  thread_broadcast(0, 0);
  thread_signal(0, 0);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_yield();
  thread_broadcast(3, 1);
  thread_signal(3, 1);
  thread_yield();
  thread_yield();
  thread_broadcast(2, 0);
  thread_yield();
  thread_unlock(0);
  thread_yield();
  cout << "1050043" << endl;
  thread_broadcast(1, 0);
  thread_yield();
  thread_broadcast(1, 0);
  thread_yield();
  thread_yield();
  thread_wait(1, 0);
  thread_yield();
  thread_wait(1, 3);
  cout << "980629" << endl;
  thread_yield();
  thread_unlock(2);
  thread_yield();
  thread_yield();
  thread_lock(2);
  thread_lock(0);
  thread_wait(2, 0);
  thread_signal(1, 2);
  thread_wait(2, 1);
  thread_broadcast(0, 1);
  thread_yield();
  thread_wait(1, 1);
  thread_wait(0, 2);
  thread_signal(3, 0);
  thread_signal(3, 2);
  thread_yield();
}

void xyz7(void* args) {
  thread_wait(2, 3);
  thread_yield();
  thread_wait(2, 0);
  thread_wait(11, 5);
  cout << "1126370" << endl;
  cout << "1217067" << endl;
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_lock(4);
  thread_signal(12, 1);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
    thread_yield();
  }
  thread_lock(8);
  thread_wait(10, 6);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(1, 2);
  thread_signal(8, 1);
  thread_lock(0);
  cout << "2163124" << endl;
  cout << "2919626" << endl;
  thread_yield();
  thread_wait(1, 0);
  thread_wait(12, 2);
  thread_yield();
  thread_broadcast(3, 11);
  cout << "2143575" << endl;
  thread_yield();
  thread_yield();
  thread_wait(1, 9);
  thread_wait(8, 2);
  thread_unlock(9);
  thread_wait(0, 0);
  thread_unlock(9);
  cout << "868295" << endl;
  thread_unlock(2);
  thread_signal(8, 10);
  thread_signal(1, 9);
  cout << "588357" << endl;
  thread_yield();
  thread_broadcast(0, 3);
  cout << "1692646" << endl;
  thread_yield();
  thread_signal(2, 9);
  cout << "893008" << endl;
  thread_yield();
  thread_broadcast(1, 0);
  thread_yield();
  thread_wait(3, 4);
  thread_signal(8, 3);
  cout << "1832810" << endl;
  thread_yield();
  thread_unlock(7);
  thread_yield();
  thread_signal(1, 4);
  thread_lock(6);
  thread_broadcast(8, 2);
  thread_broadcast(7, 9);
  thread_yield();
  thread_wait(9, 5);
  thread_broadcast(6, 2);
  thread_signal(13, 12);
  thread_yield();
  thread_lock(5);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_wait(1, 10);
  thread_broadcast(4, 3);
  thread_yield();
  cout << "1078279" << endl;
  thread_yield();
  thread_broadcast(4, 1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(11, 1);
  thread_broadcast(13, 4);
  thread_yield();
  thread_yield();
  thread_signal(4, 8);
  thread_signal(12, 6);
  thread_wait(7, 1);
  thread_signal(6, 12);
  thread_unlock(11);
  thread_lock(1);
  thread_unlock(3);
  thread_lock(2);
  thread_yield();
  thread_broadcast(10, 2);
  thread_signal(7, 13);
}

void xyz8(void* args) {
  thread_wait(2, 1);
  cout << "16637" << endl;
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(2);
  thread_yield();
  thread_signal(1, 0);
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_wait(0, 0);
  thread_signal(0, 2);
  thread_lock(0);
  cout << "16683" << endl;
  thread_wait(0, 2);
  thread_unlock(1);
  thread_broadcast(1, 0);
  thread_yield();
  thread_broadcast(1, 2);
}

void xyz9(void* args) {
  thread_unlock(1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(1, 1);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_broadcast(0, 0);
  thread_yield();
  cout << "1196121" << endl;
  thread_wait(0, 0);
  thread_yield();
  thread_lock(1);
  thread_wait(0, 1);
  cout << "1195194" << endl;
  thread_broadcast(0, 1);
  cout << "1623719" << endl;
  thread_yield();
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_unlock(0);
  thread_broadcast(1, 0);
  thread_yield();
  thread_wait(0, 0);
  thread_signal(1, 0);
  thread_yield();
  thread_wait(0, 1);
  cout << "1362073" << endl;
  thread_broadcast(0, 1);
  thread_lock(1);
  thread_yield();
  thread_lock(1);
  thread_yield();
  thread_lock(1);
  cout << "2118563" << endl;
  thread_yield();
  thread_yield();
  thread_signal(0, 0);
  thread_lock(1);
  thread_broadcast(0, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_lock(0);
  thread_broadcast(1, 0);
  thread_lock(1);
  thread_yield();
  thread_yield();
  thread_broadcast(0, 1);
  thread_wait(1, 1);
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_broadcast(0, 0);
  thread_yield();
  thread_broadcast(0, 0);
  thread_wait(1, 1);
  thread_yield();
  cout << "691790" << endl;
  thread_lock(0);
  thread_yield();
  thread_yield();
  thread_wait(0, 0);
  thread_yield();
  thread_yield();
  thread_unlock(0);
  thread_unlock(1);
  thread_broadcast(0, 1);
  thread_lock(1);
  thread_lock(1);
  thread_lock(1);
  thread_lock(1);
  thread_broadcast(0, 1);
  thread_unlock(1);
  thread_yield();
  thread_yield();
}

void xyz10(void* args) {
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  cout << "201644" << endl;
  cout << "35842" << endl;
  thread_wait(1, 4);
  thread_unlock(0);
  thread_yield();
  thread_yield();
  thread_unlock(2);
  thread_yield();
  thread_yield();
  cout << "151371" << endl;
  thread_wait(4, 5);
  thread_yield();
  thread_signal(0, 4);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(0, 4);
  thread_broadcast(4, 1);
  thread_broadcast(1, 1);
  thread_lock(4);
  thread_yield();
  thread_yield();
  cout << "67404" << endl;
  thread_lock(1);
  thread_lock(3);
  thread_wait(0, 4);
  thread_broadcast(2, 4);
  thread_yield();
  thread_yield();
  thread_yield();
  for (int i = 0; i < 10; i ++) {
    cout << i << endl;
  }
  thread_wait(4, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_lock(0);
  thread_signal(1, 3);
  thread_yield();
  cout << "118916" << endl;
  thread_signal(1, 1);
  thread_lock(2);
  thread_yield();
  thread_unlock(0);
  thread_yield();
  thread_broadcast(4, 4);
  thread_unlock(1);
  thread_unlock(4);
  cout << "120646" << endl;
  thread_yield();
  thread_lock(3);
  thread_yield();
  thread_lock(1);
}

void maker(void *args) {
  thread_yield();
  thread_create((thread_startfunc_t) xyz1, (void *) 100);
  thread_wait(0, 0);
  thread_yield();
  thread_create((thread_startfunc_t) xyz2, (void *) 100);
  thread_create((thread_startfunc_t) xyz3, (void *) 100);
  thread_yield();
  thread_create((thread_startfunc_t) xyz4, (void *) 100);
  thread_broadcast(0, 0);
  thread_yield();
  thread_yield();
  thread_lock(1);
  thread_wait(1, 1);
  thread_create((thread_startfunc_t) xyz5, (void *) 100);
  thread_yield();
  thread_create((thread_startfunc_t) xyz6, (void *) 100);
  thread_unlock(0);
  thread_yield();
  thread_lock(0);
  thread_wait(0, 0);
  thread_create((thread_startfunc_t) xyz7, (void *) 100);
  thread_lock(0);
  thread_lock(0);
  thread_broadcast(1, 1);
  thread_broadcast(0, 0);
  thread_lock(0);
  thread_lock(1);
  thread_create((thread_startfunc_t) xyz8, (void *) 100);
  thread_wait(0, 1);
  thread_signal(1, 1);
  thread_broadcast(0, 1);
  thread_create((thread_startfunc_t) xyz9, (void *) 100);
  thread_wait(0, 0);
  thread_unlock(1);
  thread_unlock(0);
  thread_unlock(0);
  thread_create((thread_startfunc_t) xyz10, (void *) 100);
  thread_wait(0, 0);
  thread_yield();
  thread_unlock(1);
  thread_signal(0, 1);
  thread_yield();
  thread_lock(1);
  thread_yield();
  thread_yield();
  thread_lock(1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(1, 0);
  thread_yield();
  thread_yield();
  thread_lock(0);
  thread_yield();
  thread_broadcast(0, 1);
  thread_wait(1, 1);
  thread_lock(0);
  thread_yield();
  thread_broadcast(1, 0);
  thread_yield();
  thread_yield();
  thread_signal(0, 1);
  thread_lock(0);
  thread_signal(1, 1);
  thread_signal(1, 0);
  thread_signal(1, 1);
  thread_wait(0, 0);
  thread_signal(1, 0);
  thread_yield();
  thread_unlock(1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_signal(1, 0);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_unlock(1);
  thread_yield();
  thread_yield();
  thread_wait(1, 1);
  thread_signal(1, 0);
  thread_unlock(0);
  thread_yield();
  thread_lock(1);
  thread_unlock(1);
  thread_yield();
  thread_yield();
  thread_lock(1);
  thread_broadcast(0, 1);
  thread_yield();
  thread_signal(1, 0);
  thread_signal(0, 1);
  thread_signal(1, 1);
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
  thread_yield();
}

int main(int argc, char *argv[]) {
  thread_libinit((thread_startfunc_t)maker, &argc);
}