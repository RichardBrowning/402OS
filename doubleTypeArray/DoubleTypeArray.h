#ifndef DOUBLE_T_A_H
#define DOUBLE_T_A_H

#include "LinkedListNode.h"

class doubleTypeArray
{
    private:
    
        linkedListNode* head;
    public:
        doubleTypeArray(int size);
        ~doubleTypeArray();
        int get(int index);
        void set(int index, int value);
        void print();
};

#endif