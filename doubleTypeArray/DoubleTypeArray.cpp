#include "DoubleTypeArray.h"
#include "LinkedListNode.h"

#include "rand-normal.h"

DoubleTypeArray::DoubleTypeArray(int size)
{
    head = new LinkedListNode();
    LinkedListNode* current = head;
    for (int i = 0; i < size - 1; i++)
    {
        /** randomize the data of each node*/
        current->setNext(new LinkedListNode(rand_normal(0, 1)));
        current = current->getNext();
    }
}

DoubleTypeArray::~DoubleTypeArray()
{
    LinkedListNode* current = head;
    while (current != NULL)
    {
        LinkedListNode* next = current->getNext();
        delete current;
        current = next;
    }
}

double DoubleTypeArray::getAt(int index)
{
    LinkedListNode* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }
    return current->getData();
}

void DoubleTypeArray::setAt(int index, double value)
{
    LinkedListNode* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }
    current->setData(value);
}

void DoubleTypeArray::print()
{
    LinkedListNode* current = head;
    while (current != NULL)
    {
        std::cout << current->getData() << std::endl;
        current = current->getNext();
    }
}




