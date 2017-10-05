#include "thread.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "interrupt.h"
#include <ucontext.h>
#include <queue>
#include <map>

using namespace std;

static int libinitOnce = 0;
static int next_threadID = 0;

typedef struct myThread {
  ucontext_t* ucontext_ptr;
  char* stack;
  int finished;
  int threadID;
} myThread;

typedef struct myLock {
  int locked;
  queue <myThread*>* blocked;
  myThread* lock_holder;
} myLock;

static queue <myThread*> ready;
static myThread* currThread;
static ucontext_t* prev;
static map<int, myLock*> lock_map;
static map<int, queue<myThread*>*> cv_map;

static int start(thread_startfunc_t func, void *arg) {
  interrupt_enable();
  func(arg);
  interrupt_disable();
  currThread->finished = 1;
  swapcontext(currThread->ucontext_ptr,prev);
  return 0;
}

extern int thread_libinit(thread_startfunc_t func, void *arg) {
  interrupt_disable();
  if (libinitOnce == 1) {
    interrupt_enable();
    return -1;
  }
  libinitOnce = 1;

  myThread* newThread;
  try {
    newThread = new myThread;
    newThread->ucontext_ptr = new ucontext_t;
    newThread->stack = new char [STACK_SIZE];
    newThread->finished = 0;
    newThread->threadID = next_threadID;
    next_threadID++;
  }
  catch (const std::bad_alloc& ba ) {
    interrupt_enable();
    return -1;
  }

  if (getcontext(newThread->ucontext_ptr) == -1) {
    interrupt_enable();
    return -1;
  }

  getcontext(newThread->ucontext_ptr);

  newThread->ucontext_ptr->uc_stack.ss_sp = newThread->stack;
  newThread->ucontext_ptr->uc_stack.ss_size = STACK_SIZE;
  newThread->ucontext_ptr->uc_stack.ss_flags = 0;
  newThread->ucontext_ptr->uc_link = NULL;

  makecontext(newThread->ucontext_ptr, (void (*)()) start, 2, func, arg);
  ready.push(newThread);

  currThread = ready.front();
  ready.pop();

  try {
    prev = new ucontext_t;
  }
  catch (const std::bad_alloc& ba) {
    interrupt_enable();
    return -1;
  }
  if (getcontext(prev) == -1) {
    interrupt_enable();
    return -1;
  }
  getcontext(prev);

  swapcontext(prev, currThread->ucontext_ptr);

  while (ready.size() != 0 ) {
    if (currThread->finished == 1) {

      currThread->ucontext_ptr->uc_stack.ss_sp = NULL;
      currThread->ucontext_ptr->uc_stack.ss_size = 0;
      currThread->ucontext_ptr->uc_stack.ss_flags = 0;
      currThread->ucontext_ptr->uc_link = NULL;
      //might have to delete more things

      delete currThread;
      currThread = NULL;
      cout << "Deleted a thread" << endl;
    }
    currThread = ready.front();
    ready.pop();
    swapcontext(prev, currThread->ucontext_ptr);
  }

  if (currThread != NULL) {

    currThread->ucontext_ptr->uc_stack.ss_sp = NULL;
    currThread->ucontext_ptr->uc_stack.ss_size = 0;
    currThread->ucontext_ptr->uc_stack.ss_flags = 0;
    currThread->ucontext_ptr->uc_link = NULL;
    //might have to delete more things

    delete currThread;
    currThread = NULL;
    cout << "Deleted a thread" << endl;
  }
  cout << "Thread library exiting.\n";
  interrupt_enable();
  exit(0);
}

extern int thread_create(thread_startfunc_t func, void *arg) {
  interrupt_disable();
  if (libinitOnce == 0) {
    interrupt_enable();
    return -1;
  }
  myThread* newCreate;
  try {
    newCreate = new myThread;
    newCreate->ucontext_ptr = new ucontext_t;
    getcontext(newCreate->ucontext_ptr);
    newCreate->stack = new char [STACK_SIZE];
    newCreate->finished = 0;
    newCreate->threadID = next_threadID;
    next_threadID++;
  }
  catch (const std::bad_alloc& ba ) {

    interrupt_enable();
    return -1;
  }
  newCreate->ucontext_ptr->uc_stack.ss_sp = newCreate->stack;
  newCreate->ucontext_ptr->uc_stack.ss_size = STACK_SIZE;
  newCreate->ucontext_ptr->uc_stack.ss_flags = 0;
  newCreate->ucontext_ptr->uc_link = NULL;
  if (getcontext(newCreate->ucontext_ptr) == -1) {
    interrupt_enable();
    return -1;
  }

  makecontext(newCreate->ucontext_ptr, (void (*)()) start, 2, func, arg);
  ready.push(newCreate);
  interrupt_enable();
  return 0;
}

extern int thread_yield(void) {
  interrupt_disable();
  if (libinitOnce == 0) {
    interrupt_enable();
    return -1;
  }
  if (ready.size() != 0 ) {
    ready.push(currThread);
    swapcontext(currThread->ucontext_ptr,prev);
  }
  interrupt_enable();
  return 0;
}

extern int thread_lock(unsigned int lock) {
  interrupt_disable();
  if (libinitOnce == 0) {
    interrupt_enable();
    return -1;
  }
  myLock* newLock;
  if (lock_map.find(lock) == lock_map.end()) {
    try {
      newLock = new myLock;
      newLock->locked = 1;
      newLock->blocked = new queue<myThread*>;
      newLock->lock_holder = currThread;
      lock_map.insert(pair<int, myLock*>(lock,newLock));
    }
    catch (const std::bad_alloc& ba ){

      delete newLock;
      interrupt_enable();
      return -1;
    }
  }
  else {
    if (lock_map.find(lock)->second->lock_holder == NULL) {
      lock_map.find(lock)->second->locked = 1;
      lock_map.find(lock)->second->lock_holder = currThread;
    }
    else if (lock_map.find(lock)->second->lock_holder->threadID == currThread->threadID){ //can't compare structs but idk how to do this otherwise so I'm just keeping it here
      interrupt_enable();
      return -1;
    }
    else {
      lock_map.find(lock)->second->blocked->push(currThread);
      swapcontext(currThread->ucontext_ptr, prev);
    }
  }
  interrupt_enable();
  return 0;
}

extern int thread_unlock(unsigned int lock) {
  interrupt_disable();
  if (libinitOnce == 0) {
    interrupt_enable();
    return -1;
  }
  if (lock_map.find(lock) == lock_map.end()) {
    interrupt_enable();
    return -1;
  }
  if (lock_map.find(lock)->second->lock_holder == NULL) {
    interrupt_enable();
    return -1;
  }
  if (lock_map.find(lock)->second->lock_holder->threadID != currThread->threadID) { //same error as above
    interrupt_enable();
    return -1;
  }
  if (lock_map.find(lock)->second->blocked->size() > 0) {
    lock_map.find(lock)->second->lock_holder = lock_map.find(lock)->second->blocked->front();
    lock_map.find(lock)->second->blocked->pop();
    ready.push(lock_map.find(lock)->second->lock_holder);
  }
  else {
    lock_map.find(lock)->second->lock_holder = NULL;
    lock_map.find(lock)->second->locked == 0;
  }
  interrupt_enable();
  return 0;
}

extern int thread_wait(unsigned int lock, unsigned int cond) {
  interrupt_disable();
  if (libinitOnce == 0) {
    interrupt_enable();
    return -1;
  }
  if (lock_map.find(lock) == lock_map.end()) {
    interrupt_enable();
    return -1;
  }
  if (lock_map.find(lock)->second->locked == 0) {
    interrupt_enable();
    return -1;
  }
  if (lock_map.find(lock)->second->lock_holder != currThread) { //same error as above
    interrupt_enable();
    return -1;
  }
  if (lock_map.find(lock)->second->blocked->size() > 0) {
    lock_map.find(lock)->second->lock_holder = lock_map.find(lock)->second->blocked->front();
    lock_map.find(lock)->second->blocked->pop();
    ready.push(lock_map.find(lock)->second->lock_holder);
  }
  else {
    lock_map.find(lock)->second->lock_holder = NULL;
    lock_map.find(lock)->second->locked == 0;
  }
  if(cv_map.find(cond) == cv_map.end()) {
    queue<myThread*>* waiting;
    try {
      waiting = new queue<myThread*>;
    }
    catch (const std::bad_alloc& ba ) {
      delete waiting;
      interrupt_enable();
      return -1;
    }
    waiting->push(currThread);
    cv_map.insert(pair<int, queue<myThread*>*>(cond,waiting));
  }
  else {
    cv_map.find(cond)->second->push(currThread);
  }
  swapcontext(currThread->ucontext_ptr, prev);
  interrupt_enable();
  return thread_lock(lock);
}

extern int thread_signal(unsigned int lock, unsigned int cond) {
  interrupt_disable();
  if (libinitOnce == 0) {
    interrupt_enable();
    return -1;
  }
  if (lock_map.find(lock) == lock_map.end()) {
    interrupt_enable();
    return 0;
  }
  if (cv_map.find(cond) == cv_map.end()) {
    interrupt_enable();
    return 0;
  }
  else {
    if (cv_map.find(cond)->second->size() != 0) {
      ready.push(cv_map.find(cond)->second->front());
      cv_map.find(cond)->second->pop();
    }
  }
  interrupt_enable();
  return 0;
}

extern int thread_broadcast(unsigned int lock, unsigned int cond) {
  interrupt_disable();
  if (libinitOnce == 0) {
    interrupt_enable();
    return -1;
  }
  if (lock_map.find(lock) == lock_map.end()) {
    interrupt_enable();
    return 0;
  }
  if (cv_map.find(cond) == cv_map.end()) {
    interrupt_enable();
    return 0;
  }
  queue<myThread*>* threads = cv_map.find(cond)->second;
  while (threads->size() != 0) {
    ready.push(cv_map.find(cond)->second->front());
    cv_map.find(cond)->second->pop();
  }
  interrupt_enable();
  return 0;
}
