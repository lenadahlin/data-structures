// LinkedList.hpp
// -----------------------------------------------
// LinkedList functions
// Templatised LinkedList
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-09-20
// -----------------------------------------------

#include "Node.h"
#include "LinkedList.h"
using namespace std;

// Constructor of LinkedList
template <typename T>
LinkedList<T>::LinkedList()
{
    current = NULL;
    head = NULL;
    tail = NULL;
    size = 0;
}
// Destructor of LinkedList
template <typename T>
LinkedList<T>::~LinkedList()
{
    while (head != NULL)
    {
        removeFromHead();
    }
}
// Add
template <typename T>
void LinkedList<T>::addToTail(const T &data)
{
    Node<T> *newNode = new Node<T>(data);
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

template <typename T>
void LinkedList<T>::addToHead(const T &data)
{
    Node<T> *newNode = new Node<T>(data);
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

template <typename T>
void LinkedList<T>::addToCurrent(const T &data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->setNext(current);
    newNode->setPrev(current->getPrev());
    current->setPrev(newNode);
    newNode->getPrev()->setNext(newNode);
    start();
    size++;
}

// Remove from head
template <typename T>
T LinkedList<T>::removeFromHead()
{
    Node<T> *temp;
    T data = head->getData();
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
    return data;
}
// Remove from tail
template <typename T>
T LinkedList<T>::removeFromTail()
{
    Node<T> *temp;
    temp = tail;
    T data = tail->getData();
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
    return data;
}

template <typename T>
T LinkedList<T>::removeFromCurrent()
{
    T data = current->getData();
    Node<T> *temp = current->getNext(); // temp will become the new current
    current->getPrev()->setNext(current->getNext());
    current->getNext()->setPrev(current->getPrev());
    delete current; // remove the Node
    current = temp; // new current is now set as the next Node
    size--;
    return data;
}

// Getters
// get size of the list
template <typename T>
int LinkedList<T>::getSize() const
{
    return size;
}
// get data from current
template <typename T>
T &LinkedList<T>::getFromCurrent() const
{
    return current->getData();
}

// get data from head
template <typename T>
T &LinkedList<T>::getFromHead() const
{
    return head->getData();
}

// get data from tail
template <typename T>
T &LinkedList<T>::getFromTail() const
{
    return tail->getData();
}

// current pointer manipulation
// start: set current to head
template <typename T>
void LinkedList<T>::start()
{
    current = head;
}

// end: set current to tail
template <typename T>
void LinkedList<T>::end()
{
    current = tail;
}
// forward
template <typename T>
void LinkedList<T>::forward()
{
    current = current->getNext();
}
// back
template <typename T>
void LinkedList<T>::back()
{
    current = current->getPrev();
}

// overloaded ostream << operator
template <typename T>
ostream &operator<<(ostream &out, LinkedList<T> &value)
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
template <typename T>
void LinkedList<T>::operator+=(LinkedList<T> &listTwo)
{
    listTwo.start();

    for (int i = 0; i < listTwo.getSize(); i++)
    {
        T data = listTwo.getFromCurrent();
        this->addToTail(data);
        listTwo.forward();
    }
}
