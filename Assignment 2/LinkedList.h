// LinkedList.h
// -----------------------------------------------
// A LinkedList header file for LinkedList.hpp
//  Templatised LinkedList
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-09-20
// -----------------------------------------------
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{

public:
    LinkedList();  // default constructor
    ~LinkedList(); // destructor

    // data in and out
    // Precondition: T data is passed in
    // Postcondition: a Node of T is inserted as the head of the list
    void addToHead(const T &data);
    // Precondition: T data is passed in
    // Postcondition: a Node of T is inserted as the tail of the list
    void addToTail(const T &data);
    // Precondition: T data is passed in
    // Postcondition: a Node of T is inserted as the tail of the list
    void addToCurrent(const T &data);

    // Precondition: the list is not empty
    // Postcondition: the head is removed from the list, data of the deleted node is returned
    T removeFromHead();
    // Precondition: the list is not empty
    // Postcondition: the tail is removed from the list, data of the deleted node is returned
    T removeFromTail();
    // Precondition: current points to the node to be removed
    // Postcondition: the node pointed to by current before is now gone; current points to the head of the list, data of the deleted node is returned
    T removeFromCurrent();
    // Getters

    // Precondition: none
    // Postcondition: returns the current node of the linked list
    T &getFromCurrent() const;

    // Precondition: none
    // Postcondition: returns the head node of the linked list
    T &getFromHead() const;

    // Precondition: none
    // Postcondition: returns the tail node of the linked list
    T &getFromTail() const;

    // Precondition: none
    // Postcondition: returns size of the list
    int getSize() const;

    // current pointer manipulation
    // Precondition: none
    // Postcondition: current is changed to head
    void start();

    // Precondition: none
    // Postcondition: current is changed to tail
    void end();

    // Precondition: none
    //  Postcondition: current is changed to next in list
    void forward();
    // Precondition: none
    // Postcondition: current is changed to previous in list
    void back();

    // Precondition: a name from Node is passed in
    // Postcondition: the list searches through the names in the list, adding +1 for each time the entered name is found, then returns the count as an int
    // int count(const string name);

    // Precondition: none
    // Postcondition: concatenates listTwo with the first list
    void operator+=(LinkedList<T> &listTwo);

private:
    Node<T> *head;    // head of the list
    Node<T> *tail;    // tail of the list
    Node<T> *current; // current node
    int size;         // size of the list
};

// overloads << to allow LinkedList to be printed
template <typename T>
ostream &operator<<(ostream &out, LinkedList<T> &value);

#include "LinkedList.hpp"

#endif