//
// Created by Ikak on 29/04/2022.
//

#ifndef DATASTRUCTURES_ITERATOR_H
#define DATASTRUCTURES_ITERATOR_H

template <class T>
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual T& next() = 0;
};

#endif //DATASTRUCTURES_ITERATOR_H
