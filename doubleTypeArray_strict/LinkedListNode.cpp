#include <math.h>

#include "LinkedListNode.h"

LinkedListNode::LinkedListNode()
{
    this->data = 0;
    next = NULL;
}

LinkedListNode::LinkedListNode(double data)
{
    this->data = data;
    next = NULL;
}

LinkedListNode::~LinkedListNode()
{
    // delete next;
    // delete prev;
}

double LinkedListNode::getData()
{
    return data;
}

LinkedListNode* LinkedListNode::getNext()
{
    return next;
}

void LinkedListNode::setData(double data)
{
    this->data = data;
}

void LinkedListNode::setNext(LinkedListNode* next)
{
    this->next = next;
}

void LinkedListNode::setPrev(LinkedListNode* prev)
{
    this->prev = prev;
}

LinkedListNode* LinkedListNode::getPrev()
{
    return prev;
}