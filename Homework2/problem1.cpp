#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int sequence = 0;
sem_t finish;
sem_t offer1;
sem_t offer2;
sem_t offer3;

void *supplier_process(void*){
    // loop forever
    while(true){
        // seed rand with time function
        srand(time(NULL));
        // generate random number between 0 and 2
        sequence = rand() % 3;
        
        if(sequence == 0){
            std::cout << "Agent supplies tobacco and paper" << std::endl;
            sem_post(&offer1);
        }else if(sequence == 1){
            std::cout << "Agent supplies paper and matches" << std::endl;
            sem_post(&offer2);
        }else if(sequence == 2){
            std::cout << "Agent supplies tobacco and matches" << std::endl;
            sem_post(&offer3);
        }
        std::cout << "Agent waits for smokers to finish smoking" << std::endl;
        sem_wait(&finish);
    }
}

void* smoker1_process(void*){
    while(true){
        sem_wait(&offer3);
        //smoke
        std::cout << "Smoker 1 has tobacco, has paper and matches from the agent" << std::endl;
        sleep(1);
        sem_post(&finish);
    }
}

void* smoker2_process(void*){
    while(true){
        sem_wait(&offer2);
        //smoke
        std::cout << "Smoker 2 has paper, has tobacco and matches from the agent" << std::endl;
        sleep(1);
        sem_post(&finish);
    }
}

void* smoker3_process(void*){
    while(true){
        sem_wait(&offer1);
        //smoke
        std::cout << "Smoker 3 has matches, has tobacco and paper from the agent" << std::endl;
        sleep(1);
        sem_post(&finish);
    }
}

int main(void){
    sem_init(&finish, 0, 0);
    sem_init(&offer1, 0, 0);
    sem_init(&offer2, 0, 0);
    sem_init(&offer3, 0, 0);

    pthread_t supplier;
    pthread_t smoker[3];

    pthread_create(&supplier, nullptr, supplier_process, nullptr);
    pthread_create(&smoker[0], nullptr, smoker1_process, nullptr);
    pthread_create(&smoker[1], nullptr, smoker2_process, nullptr);
    pthread_create(&smoker[2], nullptr, smoker3_process, nullptr);
    pthread_join(supplier, nullptr);
    pthread_join(smoker[0], nullptr);
    pthread_join(smoker[1], nullptr);
    pthread_join(smoker[2], nullptr);

    return 0;
}