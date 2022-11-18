// LStack.h
// -----------------------------------------------
// A LStack header file for LStack.hpp
//  Templatised LStack
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-09-20
// -----------------------------------------------
#ifndef LSTACK_H
#define LSTACK_H

using namespace std;
#include "LinkedList.h"

template <typename T>
class LStack
{
public:
    LStack();  // default constructor
    ~LStack(); // destructor
    // data in and out
    // Precondition: T data is passed in
    // Postcondition: T data is inserted as the head of the stack
    void push(const T entry);

    // Precondition: the stack is not empty
    // Postcondition: Return a reference to the object at the top of the stack.
    T &peek();
    // Precondition: the stack is not empty
    // Postcondition: the head is removed from the stack, the deleted data is returned
    T pop();
    // Precondition: none
    // Postcondition: returns a boolean indicating whether the stack is empty
    bool isEmpty() const;

private:
    LinkedList<T> list; // LinkedList object
    int size;           // size of the stack
};

// overloads << to allow LStack to be printed
template <typename T>
ostream &operator<<(ostream &out, LStack<T> &value); // overloads << to allow LStack to be printed
#include "LStack.hpp"

#endif