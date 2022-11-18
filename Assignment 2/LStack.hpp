// LStack.hpp
// -----------------------------------------------
// LStack functions
// Templatised LStack
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-09-20
// -----------------------------------------------
#include "LinkedList.h"
#include "LStack.h"

// Constructor of Queue
template <typename T>
LStack<T>::LStack()
{
    list = LinkedList<T>();
    size = 0;
}

// Destructor of LStack
template <typename T>
LStack<T>::~LStack()
{
    // No destructor required, as the object does
    // not own any dynamic members
}

// Returns a reference to the object at the front of the stack.
template <typename T>
T &LStack<T>::peek()
{
    if (this->isEmpty()) // exception if the stack is empty, will end function if stack is empty
    {
        throw "Cannot peek an empty stack";
    }

    T &item = list.getFromHead(); // reference to the head of the object
    return item;                  // data returned is the head
}

// Pop
template <typename T>
T LStack<T>::pop()
{
    if (this->isEmpty()) // exception if the stack is empty, will end function if stack is empty
    {
        throw "Cannot pop an empty stack";
    }
    size--;                       // size of the stack is decreased
    return list.removeFromHead(); // data is removed from the head
}

// Adds data to the head of the list
template <typename T>
void LStack<T>::push(const T entry)
{

    list.addToHead(entry); // new data is added to the head
    size++;                // size of the queue is increased
}

// Check if stack is empty
template <typename T>
bool LStack<T>::isEmpty() const
{
    return size == 0;
}

// overloaded ostream << operator
template <typename T>
ostream &operator<<(ostream &out, LStack<T> &stack)
{
    if (stack.isEmpty()) // base case to prevent infinite loop
    {
        return out; // nothing to print if stack is empty
    }
    T topItem = stack.pop();        // front of stack is popped
    out << topItem << " " << stack; // recursion prints the smaller stacks
    stack.push(topItem);            // items will be pushed back in after the recursion ends

    return out;
}
