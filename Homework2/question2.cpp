#include <iostream>
#include <pthread.h>
#include <queue>

std::queue<pthread_t> process_queue;
int guard = 0;
int semaphore_value = 0;

void wait() { 
    while (TestAndSet(&guard) == 1); 
    if (semaphore_value == 0) { 
        //atomically add process to a queue of processes waiting for the 
        //semaphore and set guard to 0; 
        process_queue.push(pthread_self());
        guard = 0;
    } 
    else 
    { 
    semaphore_value--;
    guard = 0; 
    } 
}

void signal() { 
    while (TestAndSet(&guard) == 1); 
    if (semaphore_value == 0 && process_queue.empty() == false) {
        //wake up the first process in the queue of waiting processes 
        
    }
    else {
        semaphore_value++; 
        guard = 0; 
    }
        
}

int main(void){
    int guard = 0; 
    int semaphore_value = 0;
}
