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
void DoubleTypeArray::append(LinkedListNode* newNode){
    LinkedListNode* current = head;
    //until the last one has no next
    while (current->getNext() != NULL)
    {
        current = current->getNext();
    }
    //set the next node as the incoming parameter
    current->setNext(newNode);
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

int DoubleTypeArray::length()
{
    int length = 0;
    LinkedListNode* current = head;
    while (current != NULL)
    {
        length++;
        current = current->getNext();
    }
    return length;
}

// bool DoubleTypeArray::checkIfConsensus()
// {
//     //if is initially empty
//     if(head == NULL) return false;
//     /** traverse */
//     LinkedListNode* current = head;
//     while (current->getNext() != NULL){
//         /**if data of this one != data of next one*/
//         if( current->getData() != current->getNext()->getData() )
//             /** is not conse */
//             return false;
//         /** keep traversing to next */
//         current = current->getNext();
//     }
//     return true;
// }
