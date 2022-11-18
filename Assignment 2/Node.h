// Node.h
// -----------------------------------------------
// A Node header file for Node.hpp
// Templatised Node
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-09-20
// -----------------------------------------------
#ifndef Node_H
#define Node_H

#include <cstdlib>

using namespace std;

template <typename T>
class Node
{

public:
    Node(); // default constructor
    Node(const T &defaultData, Node<T> *defaultNext = NULL, Node<T> *defaultPrev = NULL);
    ~Node(); // destructor

    // Setters
    // Pre: default or previously set values
    // Post: updated values
    void setNext(Node<T> *newNext);
    void setPrev(Node<T> *newPrev);
    void setData(const T &data);

    // Getters
    // Pre: default or previously set values
    // Post: no change to values
    Node<T> *getNext() const;
    Node<T> *getPrev() const;
    T &getData();

private:
    // Private members variables
    T data;        // data stored in the Node<T> of T
    Node<T> *next; // pointer to the next Node<T>
    Node<T> *prev; // pointer to the previous Node<T>
};

#include "Node.hpp"

#endif