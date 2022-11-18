// BTNode.h
// -----------------------------------------------
// A BTNode header file for BTNode.hpp
// Templatised BTNode
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-10-13
// -----------------------------------------------
#ifndef BTNode_H
#define BTNode_H

#include <cstdlib>
using namespace std;

template <typename T>
class BTNode
{
    public:
    BTNode();   //default constructor
    BTNode(const T& newData);
    ~BTNode();  //destructor

    //Setters
    //Pre: default or previously set values
    //Post: updated values
    void setData(const T& newData);
    void setParent(BTNode<T>* newParent);
    void setRight(BTNode<T>* newRight);
    void setLeft(BTNode<T>* newLeft);

    // Getters
    // Pre: default or previously set values
    // Post: returns values

    T& getData();
    BTNode<T>* getParent() const;
    BTNode<T>* getRight() const;
    BTNode<T>* getLeft() const;


    private:
    // Private member variables
    BTNode<T>* parent;  //pointer to parent BTNode
    BTNode<T>* right;   //pointer to right BTNode
    BTNode<T>* left;    //pointer to left BTNode
    T data;             //data of current BTNode

};

#include "BTNode.hpp"

#endif
