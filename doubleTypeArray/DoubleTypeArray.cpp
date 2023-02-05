#include "DoubleTypeArray.h"
#include "LinkedListNode.h"

DoubleTypeArray::DoubleTypeArray(int size)
{
    head = new LinkedListNode();
    LinkedListNode* current = head;
    for (int i = 0; i < size - 1; i++)
    {
        current->setNext(new LinkedListNode());
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

int DoubleTypeArray::get(int index)
{
    LinkedListNode* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }
    return current->getData();
}

void DoubleTypeArray::set(int index, int value)
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




