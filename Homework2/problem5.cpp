#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <queue>

//wait queue
std::queue<int> wait_queue;
//assume the number of chairs is 5
#define CHAIRS 5
int waiting = 0;

//semaphores barber customer
sem_t barber;
sem_t consumers;
//semaphore for mutual exclusion
sem_t mutex;
 
//barber process
void* barber_process(void*)
{
    //loop forever
   while(true)
   {
       int id = 0;
       //wait for customer
       sem_wait(&consumers);
       sem_wait(&mutex);
       //readuce waiting list by 1
       waiting = waiting - 1;
       id = wait_queue.front();
       wait_queue.pop();
       sem_post(&barber);
       sem_post(&mutex);
       std::cout << "Barber is serving the " << id << "th customer." << std::endl; 
       srand(time(NULL));
       sleep(3);
   }
}

void* consumer_process(void* p)
{
    int i = *(int*)p;
    sem_wait(&mutex);
    if(waiting < CHAIRS)
    {
        wait_queue.push(i);
        waiting = waiting + 1;
        sem_post(&consumers);
        sem_post(&mutex);
        sem_wait(&barber);
        std::cout << "The barber is serving the " << i << "th Customer." << std::endl;
        std::cout << "There are " << waiting << " customers waiting." << std::endl << std::endl;
    }
    else
    {
        sem_post(&mutex);
        std::cout << "The " << i << "th costumer left as there is no more empty chairs" << std::endl << std::endl;
    }

    pthread_exit(0);
}

int main()
{
    pthread_t p_barber;
    pthread_t p_consumers[10];

    int num_consumers = 20;

    sem_init(&barber, 0 ,0);
    sem_init(&consumers, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&p_barber, nullptr, barber_process, nullptr);
    
    for(int i = 0; i < num_consumers; i++)
    {
        pthread_create(&p_consumers[i], nullptr, consumer_process, &i);
        srand(time(0));
        sleep(rand() % 2 + 1);
    }

    for(int i = 0; i < num_consumers; i++)
    {
        pthread_join(p_consumers[i], nullptr);
    }

    sleep(5);

    return 0;
}