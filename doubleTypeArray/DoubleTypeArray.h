#ifndef DOUBLE_T_A_H
#define DOUBLE_T_A_H
#include <iostream>
#include "LinkedListNode.h"

class DoubleTypeArray
{
    private:
        LinkedListNode* head;
    public:
        DoubleTypeArray();
        DoubleTypeArray(int size);
        ~DoubleTypeArray();
        LinkedListNode* getHead();
        double getAt(int index);
        void setAt(int index, double value);
        void print();
        bool checkIfConsensus();
};

#endif