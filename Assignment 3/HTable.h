// HTable.h
// -----------------------------------------------
// A HTable header file for HTable.hpp
// Templatised HTable for Mechpart
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-10-22
// -----------------------------------------------
#ifndef HTable_H
#define HTable_H

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class HTable
{
    public:
    HTable();   //constructor
    ~HTable();  //destructor

    //mutators
    void add(const T& newData);    //inserts new data to the table; called put on slides
    T remove (const T& removalData);  //finds and removes the data, returns the data that is being removed

    //calculate/statistic functions
    int calculateParts() const;
    int calculateInventory() const;
    int getMaxSize() const;     //get max size of tree (HTSIZE)
    int getSize() const;     //size of the tree

    void outputHelper(std::ostream& out) const;   //calls inOrder for ostream
    private:
    //private variables
    const static int HTSIZE = 5000; //HTable size
    T data[HTSIZE];
    int size;
    //private functions
    int hashFunc(const T& value);   //hash function provided by assignment spec
};

// overloads << to allow HTable to be printed
template <typename T>
ostream &operator<<(ostream &out, HTable<T> &table);

#include "HTable.hpp"

#endif