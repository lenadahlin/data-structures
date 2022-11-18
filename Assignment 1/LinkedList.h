// LinkedList.h
// -----------------------------------------------
// A LinkedList header file for LinkedList.cpp
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-08-31
// -----------------------------------------------
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "Node.h"
#include <cstdlib>

class LinkedList
{

public:
    typedef Node::value_type value_type;

    LinkedList();  // default constructor
    ~LinkedList(); // destructor

    // data in and out
    // Precondition: value_type data is passed in
    // Postcondition: a Node of value_type is inserted as the head of the list
    void addToHead(const value_type &data);
    // Precondition: value_type data is passed in
    // Postcondition: a Node of value_type is inserted as the tail of the list
    void addToTail(const value_type &data);
    // Precondition: value_type data is passed in
    // Postcondition: a Node of value_type is inserted as the tail of the list
    void addToCurrent(const value_type &data);

    // Precondition: recieves a string (name) that will be from a Node to be removed
    // Postcondition: if there's a Node with this name, the Node will be removed
    void remove(const string name);
    // Precondition: the list is not empty
    // Postcondition: the head is removed from the list
    void removeFromHead();
    // Precondition: the list is not empty
    // Postcondition: the tail is removed from the list
    void removeFromTail();
    // Precondition: current points to the node to be removed
    // Postcondition: the node pointed to by current before is now gone; current points to the head of the list
    void removeFromCurrent();
    // Getters

    // Precondition: none
    // Postcondition: returns the current node of the linked list
    value_type &getFromCurrent() const;

    // Precondition: none
    // Postcondition: returns the head node of the linked list
    value_type &getFromHead() const;

    // Precondition: none
    // Postcondition: returns the tail node of the linked list
    value_type &getFromTail() const;

    // Precondition: none
    // Postcondition: returns size of the list
    int getSize();

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

    // Precondition: none
    // Postcondition: all scores are added then divided by the count size of the list, returned as a double
    double calcAverage();

    // Precondition: a name from Node is passed in
    // Postcondition: the list searches through the names in the list, adding +1 for each time the entered name is found, then returns the count as an int
    int count(const string name);

    // Precondition: none
    // Postcondition: concatenates listTwo with the first list
    void operator+=(LinkedList &listTwo);

private:
    Node *head;    // head of the list
    Node *tail;    // tail of the list
    Node *current; // current node
    int size;      // size of the list
};

// overloads << to allow LinkedList to be printed
ostream &operator<<(ostream &, LinkedList &);

#endif