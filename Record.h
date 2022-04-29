//
// Created by Ikak on 30/04/2022.
//

#ifndef DATASTRUCTURES_RECORD_H
#define DATASTRUCTURES_RECORD_H

#include "Pair.h"

template <class K, class V>
class Record : private Pair<K, V> {
public:
    Record() = default;
    Record(K key, V value) : Pair<K, V>(key, value){}
    void setKey(K key) { this->setLeft(key);}
    void setValue(V value) { this->setRight(value);}
    void getKey() { this->getLeft();}
    void getValue() { this->getRight();}
};


#endif //DATASTRUCTURES_RECORD_H
