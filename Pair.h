//
// Created by Ikak on 29/04/2022.
//

#ifndef DATASTRUCTURES_PAIR_H
#define DATASTRUCTURES_PAIR_H

template<class T, class U>
class Pair {
private:
    T left;
    U right;
public:
    Pair() = default;
    Pair(T left, U right);
    void setLeft(T left);
    void setRight(U right) ;
    T getLeft();
    U getRight();
};


template<class T, class U>
Pair<T, U>::Pair(T left, U right) : left(left), right(right){

}

template<class T, class U>
void Pair<T, U>::setLeft(T left) {
    this->left = left;
}

template<class T, class U>
void Pair<T, U>::setRight(U right) {
    this->right = right;
}

template<class T, class U>
T Pair<T, U>::getLeft() {
    return left;
}

template<class T, class U>
U Pair<T, U>::getRight() {
    return right;
}

#endif //DATASTRUCTURES_PAIR_H
