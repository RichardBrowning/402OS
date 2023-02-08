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

        /*while the prev->current is not null*/
        while (current != NULL)
        {
            /** get consensus */
            //k
            double k = current->getData();
            /*k+2*/
            //increament index by 1
            current = current->getNext();
            //if *K+1 not null, get data
            //else if null, put 0
            double k1;
            if (current->getNext() != NULL)
            {
                k1 = current->getNext()->getData();
            }
            else
            {
                k1 = 0;
            }
            /*k+2*/
            //increament index by 1
            current = current->getNext();
            //if *K+1 not null, get data
            //else if null, put 0
            double k2;
            if (current->getNext() != NULL)
            {
                k2 = current->getNext()->getData();
            }
            else
            {
                k2 = 0;
            }
            
            //求平均值
            //(k1+k2+k)/3
            double newK = (k1 + k2 + k) / 3;
            //the average value append to the new array
            newArray->append(new LinkedListNode(newK));
            /**index ++ */
            
        }
    /** check consensus */
            //if yes, break while

            //else, call self
    return newArray;
}
