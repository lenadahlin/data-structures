// BSTree.h
// -----------------------------------------------
// A BSTree header file for BSTree.hpp
// Templatised BSTree
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-10-13
// -----------------------------------------------
#ifndef BSTree_H
#define BSTree_H

#include "BTNode.h"
#include <iostream>
using namespace std;

template <typename T>
class BSTree
{
    public:
    BSTree();   // Constructor
    ~BSTree();  // Destructor

    //mutators
    void add(const T& newData);    //inserts new data to the tree; called insert on UML/slides
    T remove(const T data);         //uses another remove function to recursively delete specified data
    void clear(BTNode<T>* node);    //empties structure

    // statistics
    bool isEmpty() const;
    int getSize() const;

    //output help
    void outputHelper(std::ostream& out);   //calls inOrder for ostream

    //calculate functions
    int calculateParts();
    int calculateInventory();

    private:
    //private variables
    BTNode<T>* root;    // pointer to the root node of the tree
    BTNode<T>* current; // pointer to the current node of the tree
    int size;           // size of the tree

    //private functions
    //recursive helper functions
    void insert(BTNode<T>* node, const T& targetData);      //recursive helper function for add, inserts the node at the correct place
    BTNode<T>* removeNode(BTNode<T>* currentNode, const T& targetData);    //finds the node to be deleted and deletes/replaces it
    BTNode<T>* leftMostChildOf(BTNode<T>* const node) const;        //finds leftMostChild of node
    void inOrder(BTNode<T>* node, std::ostream& out);   //passes the tree into out, in order 
    //calculate helpers
    int calculateInventoryHelper(BTNode<T>* temp);  //calculates total inventory
	int calculatePartsHelper(BTNode<T>* temp);      //calculates total parts

};

// overloads << to allow BSTree to be printed
template <typename T>
ostream &operator<<(ostream &out, BSTree<T> &tree);

#include "BSTree.hpp"

#endif