#include <iostream>
#include "doubleTypeArray.h"
#include "linkedListNode.h"

doubleTypeArray::doubleTypeArray(int size)
{
    head = new linkedListNode();
    linkedListNode* current = head;
    for (int i = 0; i < size - 1; i++)
    {
        current->next = new linkedListNode();
        current = current->next;
    }
}

doubleTypeArray::~doubleTypeArray()
{
    linkedListNode* current = head;
    while (current != NULL)
    {
        linkedListNode* next = current->next;
        delete current;
        current = next;
    }
}

int doubleTypeArray::get(int index)
{
    linkedListNode* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->getData();
}

void doubleTypeArray::set(int index, int value)
{
    linkedListNode* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    current->setData(value);
}

void doubleTypeArray::print()
{
    linkedListNode* current = head;
    while (current != NULL)
    {
        std::cout << current->getData() << std::endl;
        current = current->next;
    }
}




