#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

void wait() { 
    while (TestAndSet(&guard) == 1); 
    if (semaphore value == 0) 
    { 
    atomically add process to a queue of processes waiting for the 
    semaphore and set guard to 0; 
    } 
    else 
    { 
    semaphore value--; 
    guard = 0; 
    } 
}

void signal() { 
    while (TestAndSet(&guard) == 1); 
    if (semaphore value == 0 && there is a process on the wait queue) 
    wake up the first process in the queue of waiting processes 
    else 
    semaphore value++; 
    guard = 0; 
}

int main(void){
    int guard = 0; 
    int semaphore value = 0;
}
