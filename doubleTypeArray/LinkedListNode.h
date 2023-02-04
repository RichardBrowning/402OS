#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

class LinkedListNode
{
    private:
        int data;
        LinkedListNode* next;
        LinkedListNode* prev;
    public:
        LinkedListNode();
        LinkedListNode(int data);
        ~LinkedListNode();
        int getData();
        LinkedListNode* getNext();
        LinkedListNode* getPrev();
        void setNext(LinkedListNode* next);
        void setPrev(LinkedListNode* prev);
};

#endif