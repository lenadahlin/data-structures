// LQueue.hpp
// -----------------------------------------------
// LQueue functions
// Templatised LQueue
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-09-20
// -----------------------------------------------

#include "LinkedList.h"
#include "LQueue.h"

// Constructor of LQueue
template <typename T>
LQueue<T>::LQueue()
{
    list = LinkedList<T>();
    size = 0;
}

// Destructor of LQueue
template <typename T>
LQueue<T>::~LQueue()
{
    // No destructor required, as the object does
    // not own any dynamic members
}

// data in and out

// Adds data to the head of the list
template <typename T>
void LQueue<T>::enqueue(const T data)
{

    list.addToTail(data); // new data is added to the head
    size++;               // size of the queue is increased
}

// Dequeue
template <typename T>
T LQueue<T>::dequeue()
{
    if (this->isEmpty()) // exception if the queue is empty, will end function if queue is empty
    {
        throw "Cannot dequeue an empty queue";
    }

    size--;                       // size of the queue is decreased
    return list.removeFromHead(); // data is removed from the head
}

// Query functions
// Returns a reference to the object at the front of the queue.
template <typename T>
T &LQueue<T>::front()
{
    if (this->isEmpty()) // exception if the queue is empty, will end function if queue is empty
    {
        throw "Cannot front an empty queue";
    }

    list.start();              // current moves to the head
    return list.getFromHead(); // data returned is the head
}

// get size
template <typename T>
int LQueue<T>::getSize() const
{
    return size; // size of the queue is returned
}

// Check if Queue is empty
template <typename T>
bool LQueue<T>::isEmpty() const
{
    return size == 0;
}

// overloaded ostream << operator
template <typename T>
ostream &operator<<(ostream &out, LQueue<T> &value)
{
    value.front(); // value is moved to the head of the queue

    for (int i = 0; i < value.getSize(); i++)
    {
        T item = value.dequeue(); // temp item to hold objects for the output
        out << item << " ";       // dequeue'd item is added to out
        value.enqueue(item);      // objects re-inserted into the tail of value
    }
    return out;
}
