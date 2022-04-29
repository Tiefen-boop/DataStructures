//
// Created by Ikak on 29/04/2022.
//

#ifndef DATASTRUCTURES_LIST_H
#define DATASTRUCTURES_LIST_H

#include "../Iter/Iterable.h"

template < class T>
class List : public Iterable<T>{
public:
    //Returns the number of elements in this list.
    virtual int size() = 0;
    //Adds element to the list
    virtual void add(T element) = 0;
    //Adds element to the list at index index if such index is possible
    virtual void add(int index, T element) = 0;
    //Sets element at index index and returns the previous element at index
    virtual T set(int index, T element) = 0;
    //Returns the element at the specified position in this list.
    virtual T get(int index) = 0;
    //Removes the first occurrence of the specified element from this list, if it is present
    virtual bool remove(T element) = 0;
    //Removes the element at position i and returns it
    virtual T remove(int index) = 0;
    //Returns true if this list contains the specified element.
    virtual bool contains(T element) = 0;
    //Returns true if this list contains no elements.
    virtual bool isEmpty() = 0;
};

#endif //DATASTRUCTURES_LIST_H
