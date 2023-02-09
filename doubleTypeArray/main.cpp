#include <iostream>
#include <math.h>
#include <time.h>
#include "LinkedListNode.h"
#include "DoubleTypeArray.h"
#include "rand-normal.h"
//#include "TimeInterval.h"

#define ARRAY_SIZE 10000

DoubleTypeArray* consensusize(DoubleTypeArray* prevArray);

//global counter
int counter = 0;

int main()
{
    srand(time(NULL));

    /** init array*/
    DoubleTypeArray* DTArray = new DoubleTypeArray(ARRAY_SIZE);

    /** recurse */
    DoubleTypeArray* consensus = consensusize(DTArray);

    /** print result */
    std::cout << "consensused value: " << std::endl;
    consensus->print();
    //consensus time
    std::cout << "consensus time: " << counter << std::endl;
    /** clean up */
    delete DTArray;
    return 0;
}

DoubleTypeArray* consensusize(DoubleTypeArray* prevArray){
    counter += 1;
    //create new array
    DoubleTypeArray* newArray = new DoubleTypeArray();
    //set current to the prev array's head
    LinkedListNode* current = prevArray->getHead();
        /*while the prev->current is not null*/
        while (current != NULL)
        {
            /** get consensus */
            /*k*/
            double k = current->getData();
            /*k+1*/
            double k1 = 0.0;
            double k2 = 0.0;
            //if *K+1 not null
            if (current->getNext() != NULL){
                //increament index by 1: k+1
                current = current->getNext();
                //get node k+1 data
                k1 = current->getData();
                //BASED on this, if k+2 is not null
                if (current->getNext() != NULL){
                    //increament index by 1: k+2
                    current = current->getNext();
                    //get node k+2 data
                    k2 = current->getData();
                }
            }
            //if *K+1 is null, natually k+2 is null as well
            else{
                k1 = 0;
                k2 = 0;
            }

            //求平均值
            //(k1+k2+k)/3
            double newK = (k1 + k2 + k) / 3;
            //the average value append to the new array
            newArray->append(newK);
            /**index ++ */
            current = current->getNext();
        }

        /** check consensus */
        if (newArray->length() == 1){
            //if yes, break while
            return newArray;
        }
        else{
            //else, call self
            return consensusize(newArray);
        }
}
