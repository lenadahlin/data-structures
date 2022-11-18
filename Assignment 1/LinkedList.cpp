// LinkedList.cpp
// -----------------------------------------------
// LinkedList cpp functions
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-08-31
// -----------------------------------------------

#include "LinkedList.h"
#include "Node.h"
#include <cstdlib>

// Constructor of LinkedList
LinkedList::LinkedList()
{
    current = NULL;
    head = NULL;
    tail = NULL;
    size = 0;
}
// Destructor of LinkedList
LinkedList::~LinkedList()
{
    while (head != NULL)
    {
        removeFromHead();
    }
}
// Add
void LinkedList::addToTail(const value_type &data)
{
    Node *newNode = new Node(data);
    if (tail != NULL)
    {
        tail->setNext(newNode);
        newNode->setPrev(tail);
    }
    if (size == 0) // if list is empty, newNode will also be head
    {
        head = newNode;
    }
    tail = newNode;
    size++;
}

void LinkedList::addToHead(const value_type &data)
{
    Node *newNode = new Node(data);
    if (head != NULL)
    {
        head->setPrev(newNode);
        newNode->setNext(head);
    }
    if (size == 0) // if list is empty, head also becomes tail
    {
        tail = newNode;
    }
    head = newNode;
    size++;
}

void LinkedList::addToCurrent(const value_type &data)
{
    Node *newNode = new Node(data);
    newNode->setNext(current);
    newNode->setPrev(current->getPrev());
    current->setPrev(newNode);
    newNode->getPrev()->setNext(newNode);
    start();
    size++;
}
// Remove
void LinkedList::remove(const string name)
{
    for (current = head; current != NULL; current = current->getNext()) // loop will search through all nodes to ensure all instances of name are removed
    {
        value_type item = getFromCurrent();
        if (item.get_name() == name)
        {
            if (current == head)
            {
                removeFromHead();
            }
            else if (current == tail)
            {
                removeFromTail();
            }
            else
            {
                removeFromCurrent();
            }
        }
    }
}
// Remove from head
void LinkedList::removeFromHead()
{
    Node *temp;
    temp = head;
    head = head->getNext();
    if (head != NULL)
    {
        head->setPrev(NULL);
    }
    else
    {
        tail = NULL; // list is empty, update tail
    }
    delete temp; // remove the Node
    size--;
}
// Remove from tail
void LinkedList::removeFromTail()
{
    Node *temp;
    temp = tail;
    tail = tail->getPrev();
    if (tail != NULL)
    {
        tail->setNext(NULL);
    }
    else
    {
        head = NULL; // list is empty, update head
    }
    delete temp; // remove the Node
    size--;
}

void LinkedList::removeFromCurrent()
{
    Node *temp = current->getNext(); // temp will become the new current
    current->getPrev()->setNext(current->getNext());
    current->getNext()->setPrev(current->getPrev());
    delete current; // remove the Node
    current = temp; // new current is now set as the next Node
    size--;
}

// Getters
// get size
int LinkedList::getSize()
{
    return size;
}
// get from current
LinkedList::value_type &LinkedList::getFromCurrent() const
{
    return current->getData();
}

// get from head
LinkedList::value_type &LinkedList::getFromHead() const
{
    return head->getData();
}

// get from tail
LinkedList::value_type &LinkedList::getFromTail() const
{
    return tail->getData();
}

// current pointer manipulation
// start
void LinkedList::start()
{
    current = head;
}

// end
void LinkedList::end()
{
    current = tail;
}
// forward
void LinkedList::forward()
{
    current = current->getNext();
}
// back
void LinkedList::back()
{
    current = current->getPrev();
}
// calc average
double LinkedList::calcAverage()
{
    double sum = 0;
    for (current = head; current != NULL; current = current->getNext())
    {
        value_type item = getFromCurrent();
        sum += item.get_score(); // all scores are added to sum
    }
    return sum / size; // sum is divided by the size of the list to provide the average
}
// count; counts how many instances of the name are in the list
int LinkedList::count(const string name)
{
    double count = 0;
    for (current = head; current != NULL; current = current->getNext())
    {
        value_type item = getFromCurrent();
        if (item.get_name() == name)
        {
            count++;
        }
    }
    return count;
}

// overloaded ostream operator
ostream &operator<<(ostream &out, LinkedList &value)
{
    value.start();
    for (int i = 0; i <= value.getSize() - 1; i++)
    {
        out << value.getFromCurrent();
        value.forward();
    }
    return out;
}
// overloaded += for concatenating lists
void LinkedList::operator+=(LinkedList &listTwo)
{
    listTwo.start();

    for (int i = 0; i < listTwo.getSize(); i++)
    {
        value_type data = listTwo.getFromCurrent();
        this->addToTail(data);
        listTwo.forward();
    }
}
