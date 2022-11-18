// HTable.hpp
// -----------------------------------------------
// HTable functions
// Templatised HTable for Mechpart
// -----------------------------------------------
// Written by Lena Dahlin c3391146: 2022-10-22
// -----------------------------------------------

#include "HTable.h"
#include <string>
using namespace std;

// Constructor of HTable
template <typename T>
HTable<T>::HTable(){
    size = 0;
    for (int i = 0; i < HTSIZE; i++){
        data[i] = T();  //filling data with empty mechparts
    }
}

// HTable destructor
template <typename T>
HTable<T>::~HTable(){
    for (int i = 0; i < HTSIZE; i++){
        data[i] = T();  //filling data with empty mechparts
    }
    size = 0;
}

//Mutators
//add to table
template <typename T>
void HTable<T>::add(const T& newData){
    int location = hashFunc(newData);
    data[location] = newData;
    size++;
}

//remove the data provided
template <typename T>
T HTable<T>::remove(const T& removalData){
    int location = hashFunc(removalData);
    T removedData = data[location];
    data[location] = T();   //reassigning location to a default mechpart
    size--;
    return removedData;
}

//hash function provided by assignment spec
template <typename T> 
int HTable<T>::hashFunc(const T& value){ 
    int position = 0; 
    string temp = value.get_code(); 
    for (int i=0; i<(int)temp.length(); i++) { 
        position += (i+1) * (i+1) * temp.at(i); 
    } 
    return position % HTSIZE; 
} 

// get max size of the table
template <typename T>
int HTable<T>::getMaxSize() const {
    return HTSIZE;
}

// get size of the table
template <typename T>
int HTable<T>::getSize() const {
    return size;
}

//prints table for ostream
template <typename T>
void HTable<T>::outputHelper(std::ostream& out) const {
    for (int i = 0; i < getMaxSize(); i++){
        if(data[i].get_code() != "" && data[i].get_quantity() != 0){    //only add to out if part is not default
            out << "(" << data[i].get_code() << "," << data[i].get_quantity() << ") " ;
        }
    }
}

//ostream << operator
template <typename T>
std::ostream& operator << (std::ostream& out, HTable<T>& table){
    table.outputHelper(out);
    return out;
}


//Calculate functions for mechpart
//calculate parts
template <typename T>
int HTable<T>::calculateParts() const {
	int count = 0;
	    for (int i = 0; i < getMaxSize(); i++){
        if(data[i].get_quantity() != 0 && data[i].get_code() != ""){   //only add to count if code is not default
            count++;
        }
    }
	return count;
}

//calculate inventory
template <typename T>
int HTable<T>::calculateInventory() const {	
	int count = 0;
	    for (int i = 0; i < getMaxSize(); i++){
        if(data[i].get_quantity() != 0 && data[i].get_code() != ""){    //only add to count if quantity is not default
            count+= data[i].get_quantity();
        }
    }
	return count;
}


