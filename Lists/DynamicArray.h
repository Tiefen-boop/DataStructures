//
// Created by Ikak on 29/04/2022.
//

#ifndef DATASTRUCTURES_DYNAMICARRAY_H
#define DATASTRUCTURES_DYNAMICARRAY_H

#include "List.h"

template <class T>
class DynamicArray : public List<T> {
private:
    int arrSize;
    int elementCount;
    int expansionRate;
    T* arr;
public:
    DynamicArray();
    DynamicArray(int initSize);
    DynamicArray(int initSize, int expansionRate);
    DynamicArray(List<T> list);
};

template <class T>
DynamicArray<T> ::DynamicArray(int initSize, int expansionRate) : expansionRate(expansionRate), arrSize(initSize), arr(new T[arrSize]), elementCount(0) {}

template <class T>
DynamicArray<T> ::DynamicArray(int initSize) : DynamicArray(initSize, 16) {}

template <class T>
DynamicArray<T> ::DynamicArray() : DynamicArray(16, 16) {}

template<class T>
DynamicArray<T>::DynamicArray(List<T> list) : DynamicArray(list.size(), 16){
    Iterator<T> iter = list.iterator();
    while (iter.hasNext()){
        (*arr)[elementCount++] = iter.next();
    }
}

#endif //DATASTRUCTURES_DYNAMICARRAY_H
