// BTNode.hpp
// -----------------------------------------------
// BTNode functions
// Templatised BTNode
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-10-13
// -----------------------------------------------
#include "BTNode.h"


// Default constructor
template <typename T>
BTNode<T>::BTNode()
{
    parent = NULL;
    right = NULL;
    left = NULL;
}
// Specific constructor
template <typename T>
BTNode<T>::BTNode(const T& newData)
{
    data = newData;
    parent = NULL;
    right = NULL;
    left = NULL;
}
// Destructor
template <typename T>
BTNode<T>::~BTNode<T>()
{
    parent = NULL;
    right = NULL;
    left = NULL;
}
// Setters
// setting the data of the current BTNode<T>
template <typename T>
void BTNode<T>::setData(const T& newData){
    data = newData;
}

// setting the parent of the current BTNode<T>
template <typename T>
void BTNode<T>::setParent(BTNode<T>* newParent){
    parent = newParent;
}
// setting the right of the current BTNode<T>
template <typename T>
void BTNode<T>::setRight(BTNode<T>* newRight){
    right = newRight;
}
// setting the left of the current BTNode<T>
template <typename T>
void BTNode<T>::setLeft(BTNode<T>* newLeft){
    left = newLeft;
}
// getting the data of the current BTNode<T>
template <typename T>
T& BTNode<T>::getData()
{
    return data;
}
// getting the parent BTNode<T>
template <typename T>
BTNode<T> *BTNode<T>::getParent() const
{
    return parent;
}
// getting the right BTNode<T>
template <typename T>
BTNode<T> *BTNode<T>::getRight() const
{
    return right;
}
// getting the left BTNode<T>
template <typename T>
BTNode<T> *BTNode<T>::getLeft() const
{
    return left;
}