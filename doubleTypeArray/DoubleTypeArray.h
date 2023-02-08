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
        void append(double data);
        double getAt(int index);
        void setAt(int index, double value);
        void print();
        int length();
        //bool checkIfConsensus();
};

#endif