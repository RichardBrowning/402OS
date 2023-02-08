#include <iostream>
#include <math.h>
#include <time.h>
#include "LinkedListNode.h"
#include "DoubleTypeArray.h"
#include "rand-normal.h"


#define ARRAY_SIZE 30

DoubleTypeArray* consensusize();

int main()
{
    srand(time(NULL));
    // for (int i = 0; i < 10; i++)
    // {
    //     std::cout << rand_normal(0, 1) << std::endl;
    // }

    /** init array*/
    DoubleTypeArray* DTArray = new DoubleTypeArray(ARRAY_SIZE);
    DTArray->print();
    
    /** recurse */


    /** clean up */
    delete DTArray;
    return 0;
}

DoubleTypeArray* consensusize(DoubleTypeArray* prevArray){
    /** consensusize */
        //create new array
    DoubleTypeArray* newArray = new DoubleTypeArray();
    //set current to the prev array's head
    LinkedListNode* current = prevArray->getHead();
    //get the next one to the head
    current = current->getNext();
        /*while the prev->current is not null*/
        {
            /** get consensus */
            //k-1 
            //k data at current
            /*k+1*/
                //if *K+1 not null, get data
                //else if null, put 0
            //求平均值

            //the average value append to the new array

            //index + 1
        }
    /** check consensus */
            //if yes, break while

            //else, call self
    return newArray;
}
