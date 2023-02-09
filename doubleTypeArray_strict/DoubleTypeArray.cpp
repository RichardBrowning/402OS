#include "DoubleTypeArray.h"
#include "LinkedListNode.h"

#include "rand-normal.h"

DoubleTypeArray::DoubleTypeArray(int size)
{
    // randomly generate the data of the head
    head = new LinkedListNode(rand_normal(0, 1));
    //set current node to head
    LinkedListNode* current = head;
    //loop through the rest of the nodes
    for (int i = 0; i < size - 1; i++)
    {
        /** randomize the data of each node*/
        current->setNext(new LinkedListNode(rand_normal(0, 1)));
        //set next to be current's next
        LinkedListNode* next = current->getNext();
        //set current to be next's prev
        next->setPrev(current);
        //set current to be next
        current = next;
    }
    //link the last node -> next to the head
    current->setNext(head);
    //link the head -> prev to the last node
    head->setPrev(current);
}

//polymorphism: create with only the head, WARNING: head is null
DoubleTypeArray::DoubleTypeArray()
{
    head = NULL;
    head->setNext(head);
}

DoubleTypeArray::~DoubleTypeArray()
{
    //set current to head
    LinkedListNode* current = head -> getNext();
    //
    while (current != head)
    {
        //set next to be current's next
        LinkedListNode* next = current->getNext();
        //delete current
        delete current;
        //make next current
        current = next;
    }
    delete head;
}

LinkedListNode* DoubleTypeArray::getHead()
{
    return head;
}

void DoubleTypeArray::append(double data){
    //if head is null
    if (head == NULL){
        //std::cout << "head is null" << std::endl;//debug line
        head = new LinkedListNode(data);
        head->setNext(head);
        head->setPrev(head);
        return;
    }

    LinkedListNode* tail = head -> getPrev();
    //create a new node
    LinkedListNode* newNode = new LinkedListNode(data);
    // tail's next is the new node
    tail->setNext(newNode);
    // head's prev is the new node
    head->setPrev(newNode);
    //set the next node with the head
    newNode->setNext(head);
    //set the prev node with the tail
    newNode->setPrev(tail);
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
    //set current to head's next
    LinkedListNode* current = head->getNext();
    while (current != head)
    {
        std::cout << current->getData() << std::endl;
        current = current->getNext();
    }
}

int DoubleTypeArray::length()
{
    //initial length is 1 (head)
    int length = 1;
    //@deprecate if is initially empty
    // if(head == NULL) return length;
    //assign head to current, increament one
    LinkedListNode* current = head->getNext();
    //if not reached head yet
    while (current != head)
    {
        length++;
        current = current->getNext();
    }
    return length;
}

bool DoubleTypeArray::checkIfConsensus()
{
    //if is initially empty
    if(head == NULL) return false;
    /** traverse */
    LinkedListNode* current = head;
    do {
        /**if data of this one != data of next one*/
        if( current->getData() != current->getNext()->getData() )
            /** is not conse */
            return false;
        /** keep traversing to next */
        current = current->getNext();
    } while (current->getNext() != head);
    return true;
}
