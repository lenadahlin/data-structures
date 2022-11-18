// Node.hpp
// -----------------------------------------------
// Node functions
// Templatised Node
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-09-20
// -----------------------------------------------
#include "Node.h"

// Constructor
template <typename T>
Node<T>::Node()
{
    prev = NULL;
    next = NULL;
}

template <typename T>
Node<T>::Node(const T &defaultData, Node<T> *defaultNext, Node<T> *defaultPrev) // constructor
{
    data = defaultData;
    prev = defaultPrev;
    next = defaultNext;
}
// Destructor
template <typename T>
Node<T>::~Node<T>()
{
    // No destructor required, as the object does
    // not own any dynamic members
}

// Setters
// setting next Node<T> in the list
template <typename T>
void Node<T>::setNext(Node<T> *nextPtr)
{
    next = nextPtr;
}

// setting previous Node<T> in the list
template <typename T>
void Node<T>::setPrev(Node<T> *prevPtr)
{
    prev = prevPtr;
}
// setting the data of the current Node<T>
template <typename T>
void Node<T>::setData(const T &newData)
{
    data = newData;
}

// Getters
// getting the next Node<T>
template <typename T>
Node<T> *Node<T>::getNext() const
{
    return next;
}
// getting the previous Node<T>
template <typename T>
Node<T> *Node<T>::getPrev() const
{
    return prev;
}
// getting the data of the current Node<T>
template <typename T>
T &Node<T>::getData()
{
    return data;
}