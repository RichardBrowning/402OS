#ifndef DOUBLE_T_A_H
#define DOUBLE_T_A_H
#include <iostream>
#include "LinkedListNode.h"

class DoubleTypeArray
{
    private:
        LinkedListNode* head;
    public:
        DoubleTypeArray(int size);
        ~DoubleTypeArray();
        int get(int index);
        void set(int index, int value);
        void print();
};

#endif