#include "DoubleTypeArray.h"
#include "LinkedListNode.h"

#include "rand-normal.h"

DoubleTypeArray::DoubleTypeArray(int size)
{
    head = new LinkedListNode(rand_normal(0, 1));
    LinkedListNode* current = head;
    for (int i = 0; i < size - 1; i++)
    {
        /** randomize the data of each node*/
        current->setNext(new LinkedListNode(rand_normal(0, 1)));
        current = current->getNext();
    }
}

//polymorphism: create with only the head, WARNING: head is null
DoubleTypeArray::DoubleTypeArray()
{
    head = NULL;
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

LinkedListNode* DoubleTypeArray::getHead()
{
    return head;
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

bool DoubleTypeArray::checkIfConsensus()
{
    //if is initially empty
    if(head == NULL) return false;
    /** traverse */
    LinkedListNode* current = head;
    while (current->getNext() != NULL){
        /**if data of this one != data of next one*/
        if( current->getData() != current->getNext()->getData() )
            /** is not conse */
            return false;
        /** keep traversing to next */
        current = current->getNext();
    }
}
