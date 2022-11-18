// BSTree.hpp
// -----------------------------------------------
// BSTree functions
// Templatised BSTree
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-10-13
// -----------------------------------------------

#include "BTNode.h"
#include "BSTree.h"
using namespace std;

// Constructor of BSTree
template <typename T>
BSTree<T>::BSTree(){
    root = NULL;
    current = NULL;
    size = 0;
}

// Destructor of BSTree
template <typename T>
BSTree<T>::~BSTree(){
    clear(root);
}

// recursive deleting function
template <typename T>
void BSTree<T>::clear(BTNode<T>* node){
    // recursively deletes all left, then all right
	if (node == NULL) {
        return; 
    }
    clear(node->getLeft());
	clear(node->getRight());
	// delete the node
	delete node;
	size--;
}
// entry add function
template <typename T>
void BSTree<T>::add(const T& newData){
    if (isEmpty()){
        root = new BTNode<T>(newData);  //makes newData the root if no root
    }   else{
            insert(root, newData);      //recursive function to insert to the next NULL position that is appropriate
    }
    size++;
    return;
}

// recursive insert helper
template <typename T>
void BSTree<T>::insert(BTNode<T>* node, const T& newData){
    if (newData == node->getData()){
        node->setData(newData);                         //replaces the existing node if it's equal
    }
    else if (newData > node->getData()){                //inserting to right side
        if (node->getRight() == NULL){
            node->setRight(new BTNode<T>(newData));     //node is set if getRight is empty
        }   else {
                insert(node->getRight(), newData);      //recursion to go further down the tree
        }
    }
    
    else {                                              //inserting to left side
        if (node->getLeft() == NULL){
            node->setLeft(new BTNode<T>(newData));      //node is set if getLeft is empty
        }   else{
                insert(node->getLeft(), newData);       //recursion to go further down the tree
        }

    }

}

// Getters
// get size of the tree
template <typename T>
int BSTree<T>::getSize() const {
    return size;
}

// Statistics
template <typename T>
bool BSTree<T>::isEmpty() const {
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Removes
//entry point for removeNode
template <typename T>
T BSTree<T>::remove(const T data) {
    BTNode<T>* rootNode = root;
    if (isEmpty()){
        return data;
    }

    else {
        removeNode(rootNode, data);
    }
    return data;
}


//recursive private remove function, adapted from lab example
template <typename T>
BTNode<T>* BSTree<T>::removeNode(BTNode<T>* currentNode, const T& targetData){
    if (currentNode == NULL){
        return NULL;
    }
    //finding the node in the tree
    // if the currentNode is greater than the targetData, go left
        if(targetData < currentNode->getData()){
            currentNode->setLeft(removeNode(currentNode->getLeft(), targetData));

            if (currentNode->getLeft()){
                currentNode->getLeft()->setParent(currentNode);
            }
        }
        // if the currentNode is less than the targetData, go right
        else if (targetData > currentNode->getData()){
            currentNode->setRight(removeNode(currentNode->getRight(), targetData));

            if (currentNode->getRight()){
                currentNode->getRight()->setParent(currentNode);
            }
        }
        //if the currentNode has 2 children, replace current with leftMost of getRight
        else {
            BTNode<T>* temp;
            if (currentNode->getLeft() && currentNode->getRight()){
                temp = leftMostChildOf(currentNode->getRight());
                currentNode->setData(temp->getData());
                currentNode->setRight(removeNode(currentNode->getRight(), currentNode->getData()));
            }
            else{   //if the currentNode has 1 child, replace it with that child
                temp = currentNode;
                if (currentNode->getLeft() == NULL){
                    currentNode = currentNode->getRight();
                } else if (currentNode->getRight() == NULL){
                    currentNode = currentNode->getLeft();
                }
                delete temp;
                size--;
            }
        }
    if (!currentNode){
        return currentNode;
    }
    return currentNode;

}

//recursive function to find the left most child of a node
template <typename T>
BTNode<T>* BSTree<T>::leftMostChildOf(BTNode<T>* const node) const {
    if (node == NULL){
        return NULL;    //return NULL if node is empty
    }
    if (node->getLeft() == NULL){
        return node;    //if get left is NULL, current node is the left most node
    }
    else {
        leftMostChildOf(node->getLeft());   //recursion to find left most child
    }
    return node;
}

//calculate inventory initial function
template <typename T>
int BSTree<T>::calculateInventory() {	
	int count = 0;
	count = calculateInventoryHelper(root);
	return count;
}

// recursive private helper for calculateInventory, adapted from lab examples
template <typename T>
int BSTree<T>::calculateInventoryHelper(BTNode<T>* temp) {
	int count = 0;
	if (temp != NULL) {
        //traverses the tree and adds to count with recursion
		count += calculateInventoryHelper(temp->getLeft());
		count += temp->getData().get_quantity();
		count += calculateInventoryHelper(temp->getRight());
	}
	return count;
}

//calculate parts initial function
template <typename T>
int BSTree<T>::calculateParts() {
	int count = 0;
	count = calculatePartsHelper(root);
	return count;
}

// recursive private helper for calculateParts, adapted from lab examples
template <typename T>
int BSTree<T>::calculatePartsHelper(BTNode<T>* temp) {
	int count = 0;
	if (temp != NULL) {
        //traverses the tree and adds to count with recursion
		count += calculatePartsHelper(temp->getLeft());
		count += 1;
		count += calculatePartsHelper(temp->getRight());
	}
	return count;
}

//ostream functions
//passes the tree into out, in order 
template <typename T>
void BSTree<T>::inOrder(BTNode<T>* node, std::ostream& out) {
    if (node != NULL){
        inOrder(node->getLeft(), out);  //left sub-tree
        out << node->getData() << " ";  //prints out or adds to stream
        inOrder(node->getRight(), out); //right sub-tree
    }
}

//passes root and out to help the ostream
template <typename T>
void BSTree<T>::outputHelper(std::ostream& out) {
    inOrder(root, out);
}

//ostream << operator
template <typename T>
std::ostream& operator << (std::ostream& out, BSTree<T>& tree) {
    tree.outputHelper(out); //gets tree in-order
    return out;
}