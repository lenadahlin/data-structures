// Node.cpp
// -----------------------------------------------
// Node functions
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-08-31
// -----------------------------------------------
#include "Node.h"
#include <cstdlib>

// Constructor
Node::Node()
{
    prev = NULL;
    next = NULL;
}

Node::Node(const value_type &defaultData, Node *defaultNext, Node *defaultPrev) // constructor
{
    data = defaultData;
    prev = defaultPrev;
    next = defaultNext;
}
// Destructor
Node::~Node()
{
    // No destructor required, as the object does
    // not own any dynamic members
}

// Setters
// setting next node in the list
void Node::setNext(Node *nextPtr)
{
    next = nextPtr;
}
// setting previous node in the list
void Node::setPrev(Node *prevPtr)
{
    prev = prevPtr;
}
// setting the data of the current node
void Node::setData(const value_type &newData)
{
    data = newData;
}

// Getters
// getting the next node
Node *Node::getNext() const
{
    return next;
}
// getting the previous node
Node *Node::getPrev() const
{
    return prev;
}
// getting the data of the current node
Node::value_type &Node::getData()
{
    return data;
}