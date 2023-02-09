#include <iostream>
#include <math.h>
#include <time.h>
#include "LinkedListNode.h"
#include "DoubleTypeArray.h"
#include "rand-normal.h"

#define ARRAY_SIZE 30

DoubleTypeArray* consensusize(DoubleTypeArray* prevArray);

//global counter
int counter = 0;

int main()
{
    srand(time(NULL));

    /** init array*/
    DoubleTypeArray* DTArray = new DoubleTypeArray(ARRAY_SIZE);
    //print the array
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
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            //get the current node's data
            double k = current->getData();
            //get the next node's data
            double k1 = current->getNext()->getData();
            //get the previous node's data
            double k2 = current->getPrev()->getData();
            //(k1+k2+k)/3
            double newK = (k1 + k2 + k) / 3;
            //the average value append to the new array
            newArray->append(newK);
            /**index ++ */
            current = current->getNext();
        }
        //return newArray;
        /** check consensus */
        if (newArray->checkIfConsensus()){
            //if yes, break while
            return newArray;
        }
        else{
            //else, call self
            return consensusize(newArray);
        }
}
