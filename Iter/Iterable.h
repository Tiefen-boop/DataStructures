//
// Created by Ikak on 29/04/2022.
//

#ifndef DATASTRUCTURES_ITERABLE_H
#define DATASTRUCTURES_ITERABLE_H

#include "Iterator.h"

template <class T>
class Iterable{
public:
    virtual Iterator<T> iterator() = 0;
};

#endif //DATASTRUCTURES_ITERABLE_H
