// Node.h
// -----------------------------------------------
// Node header for Node cpp, defines student as typedef
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-08-31
// -----------------------------------------------
#ifndef NODE_H
#define NODE_H

#include "Student.h"
class Node
{

public:
    typedef Student value_type; // typedef
    Node();                     // default constructor
    Node(const value_type &defaultData, Node *defaultNext = NULL, Node *defaultPrev = NULL);
    ~Node(); // destructor

    // Setters
    // Pre: default or previously set values
    // Post: updated values
    void setNext(Node *newNext);
    void setPrev(Node *newPrev);
    void setData(const value_type &data);

    // Getters
    // Pre: default or previously set values
    // Post: no change to values
    Node *getNext() const;
    Node *getPrev() const;
    value_type &getData();

private:
    // Private members variables
    value_type data; // data stored in the node of value_type
    Node *next;      // pointer to the next Node
    Node *prev;      // pointer to the previous Node
};
#endif