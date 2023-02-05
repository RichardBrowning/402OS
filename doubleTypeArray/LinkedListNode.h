#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

#include <iostream>
#include <stdlib.h>

class LinkedListNode
{
    private:
        double data;
        LinkedListNode* next;
        LinkedListNode* prev;
    public:
        LinkedListNode();
        LinkedListNode(double data);
        ~LinkedListNode();
        int getData();
        void setData(double data);
        LinkedListNode* getNext();
        void setNext(LinkedListNode* next);
        LinkedListNode* getPrev();
        void setPrev(LinkedListNode* prev);
};

#endif