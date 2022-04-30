//
// Created by Ikak on 29/04/2022.
//

#ifndef DATASTRUCTURES_PAIR_H
#define DATASTRUCTURES_PAIR_H

template<class T, class U>
class Pair {
private:
    T _left;
    U _right;
public:
    Pair() = default;
    Pair(T left, U right);
    void setLeft(T left);
    void setRight(U right) ;
    const T& getLeft() const;
    const U& getRight() const;
};


template<class T, class U>
Pair<T, U>::Pair(T left, U right) : _left(left), _right(right){

}

template<class T, class U>
void Pair<T, U>::setLeft(T left) {
    _left = left;
}

template<class T, class U>
void Pair<T, U>::setRight(U right) {
    _right = right;
}

template<class T, class U>
const T& Pair<T, U>::getLeft() const {
    return _left;
}

template<class T, class U>
const U& Pair<T, U>::getRight() const {
    return _right;
}

#endif //DATASTRUCTURES_PAIR_H
