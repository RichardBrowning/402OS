#include <iostream>
#include <math.h>

LinkedListedNode::LinkedListedNode()
{
    data = 0;
    next = NULL;
    prev = NULL;
}


LinkedListedNode::LinkedListedNode(double data)
{
    data = 0;
    next = NULL;
    prev = NULL;
}

LinkedListedNode::~LinkedListedNode()
{
    delete next;
    delete prev;
}

int LinkedListedNode::getData()
{
    return data;
}

LinkedListedNode* LinkedListedNode::getNext()
{
    return next;
}

void LinkedListedNode::setData(int data)
{
    this->data = data;
}

void LinkedListedNode::setNext(LinkedListedNode* next)
{
    this->next = next;
}

LinkedListedNode* LinkedListedNode::getPrev()
{
    return prev;
}

void LinkedListedNode::setPrev(LinkedListedNode* prev)
{
    this->prev = prev;
}