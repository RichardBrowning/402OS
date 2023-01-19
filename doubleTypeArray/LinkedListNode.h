#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

class linkedListNode
{
    private:
        int data;
        linkedListNode* next;
        linkedListNode* prev;
    public:
        linkedListNode();
        linkedListNode(int data);
        ~linkedListNode();
        int getData();
        linkedListNode* getNext();
        linkedListNode* getPrev();
        void setNext(linkedListNode* next);
        void setPrev(linkedListNode* prev);
};

#endif