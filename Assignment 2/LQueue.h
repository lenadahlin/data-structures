// LQueue.h
// -----------------------------------------------
// A LQuee header file for LQueue.hpp
// Templatised LQueue
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-09-20
// -----------------------------------------------
#ifndef LQUEUE_H
#define LQUEUE_H

#include "LinkedList.h"
using namespace std;

template <typename T>
class LQueue
{

public:
    LQueue();  // default constructor
    ~LQueue(); // destructor

    // data in and out

    // Precondition: T data is passed in
    // Postcondition: T data is inserted as the tail of the queue
    void enqueue(const T data);
    // Precondition: the queue is not empty
    // Postcondition: the head is removed from the queue, the deleted data is returned
    T dequeue();

    // Query functions

    // Precondition: the queue is not empty
    // Postcondition: Returns a reference to the object at the front of the queue.
    T &front();
    // Precondition: none
    // Postcondition: returns size of the queue
    int getSize() const;
    // Precondition: none
    // Postcondition: returns a boolean indicating whether the queue is empty
    bool isEmpty() const;

private:
    LinkedList<T> list; // LinkedList object
    int size;           // Size of the Queue
};
// overloads << to allow LQueue to be printed
template <typename T>
ostream &operator<<(ostream &out, LQueue<T> &value); // overloads << to allow LQueue to be printed

#include "LQueue.hpp"

#endif