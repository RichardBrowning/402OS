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
        while (current != NULL)
        {
            /** get consensus */
            //k-1 
            double k1 = current->getPrev()->getData();
            //k data at current
            double k = current->getData();
            /*k+1*/
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
            //if already the last one
            if (current->getNext() == NULL){
                break;
            }
            current = current->getNext();
            
            //if the second is the last one 
            if (current->getNext() == NULL){
                break;
            }
            current = current->getNext();
            //if the third one is the last one, meaning next triple only has one element
            if(current->getNext() == NULL){
                //add that one to new array
                newArray->append(new LinkedListNode(current->getData()));
                //and break
                break;
            }
        }
    /** check consensus */
            //if yes, break while

            //else, call self
    return newArray;
}
