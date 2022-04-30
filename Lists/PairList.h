//
// Created by Ikak on 30/04/2022.
//

#ifndef DATASTRUCTURES_PAIRLIST_H
#define DATASTRUCTURES_PAIRLIST_H

#include "List.h"
#include "../Pair.h"

template <class T>
class PairList;

template <class T>
std::ostream & operator<<(std::ostream& os, const PairList<T>& pairList);

/*
template <class T>
class PairListIterator;
*/

template <class T>
class PairList : public List<T>, private Pair<T, PairList<T>*>{
public:
    PairList() : Pair<T, PairList<T>*>(T(), nullptr){};
    const T& getFirst() const { this->getLeft();}
    const PairList<T>* getRest() const { this->getRight();}
    void setFirst(T element) { this->setLeft(element);}
    void setRest(PairList<T>* element) { this->setRight(element);}
    int size() const;
    void add(T element);
    void add(int index, T element);
    T set(int index, T element);
    const T& get(int index) const;
    bool remove(T element);
    T remove(int index);
    bool contains(T element) const;
    bool isEmpty() const { return getRest() == nullptr;}
    //Iterator<T>* iterator() {return new PairListIterator<T>(this);};
    PairList<T>& operator=(const PairList<T>& o);
    friend std::ostream & operator<< <>(std::ostream& os, const PairList<T>& pairList);
    virtual ~PairList();
};

template<class T>
int PairList<T>::size() const {
    if(isEmpty())
        return 0;
    return 1 + getRest()->size();
}

template <class T>
void PairList<T>::add(T element) {
    if (isEmpty()){
        setFirst(element);
        setRest(new PairList<T>());
        return;
    }
    getRest()->add(element);
}

template<class T>
void PairList<T>::add(int index, T element) {
    if (isEmpty()){
        if (index == 0){
            add(element);
            return;
        }
        throw std::length_error("can't add at given index since the list doesn't reach such length");
    }
    if (index == 0){
        getRest()->add(0, getFirst());
        setFirst(element);
        return;
    }
    getRest()->add(index - 1, element);
}

template<class T>
T PairList<T>::set(int index, T element) {
    if (isEmpty()){
        throw std::length_error("can't set at given index since the list doesn't reach such length");
    }
    if (index == 0){
        T oldElement = this->getFirst();
        setFirst(element);
        return oldElement;
    }
    return getRest()->add(index - 1, element);
}

template<class T>
const T& PairList<T>::get(int index) const {
    if (isEmpty()){
        throw std::length_error("can't get at given index since the list doesn't reach such length");
    }
    if (index == 0){
        return getFirst();
    }
    return getRest()->get(index - 1);
}

template<class T>
bool PairList<T>::remove(T element) {
    if (isEmpty()){
        return false;
    }
    if (getFirst() == element){
        if (getRest()->isEmpty()) {
            delete getRest();
            setRest(nullptr);
        }
        else {
            setFirst(getRest()->getFirst());
            getRest()->remove(getFirst());
        }
        return true;
    }
    return getRest()->remove(element);
}

template<class T>
T PairList<T>::remove(int index) {
    if (isEmpty()){
        throw std::length_error("can't remove at given index since the list doesn't reach such length");
    }
    if (index == 0){
        if (getRest()->isEmpty()) {
            delete getRest();
            setRest(nullptr);
            return getFirst();
        }
        else {
            T removed = getFirst();
            setFirst(getRest()->getFirst());
            getRest()->remove(0);
            return removed;
        }
    }
    return getRest()->remove(index - 1);
}

template<class T>
bool PairList<T>::contains(T element) const {
    if (isEmpty()){
        return false;
    }
    if (getFirst() == element){
        return true;
    }
    return getRest()->contains(element);
}

template<class T>
PairList<T> &PairList<T>::operator=(const PairList<T> &o) {
    setFirst(o.getFirst());
    setRest(o.getRest());
    return *this;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const PairList<T> &pairList) {
    const T& val = pairList.getFirst();
    os << "[";
    if (pairList.isEmpty()){
        os << "]";
        return os;
    }
    os << val << ", ";
    os << *(pairList.getRest()) << "]";
    return os;
//    return pairList.isEmpty() ? os << "[]" : os << "[" << pairList.getFirst()  << ", "<< *pairList.getRest() << "]";
}

template<class T>
PairList<T>::~PairList() {
    if (getRest() != nullptr)
        delete getRest();
}

/*
template<class T>
class PairListIterator : public Iterator<T> {
private:
        PairList<T>* _pairList;
public:
    explicit PairListIterator(PairList<T>* pairList) : _pairList(pairList){}
    bool hasNext() {return _pairList->isEmpty();}
    T& next() {
        if (!hasNext())
            throw std::out_of_range("No more elements");
        T& next = _pairList->getFirst();
        _pairList = _pairList->getRest();
        return next;
    }
};
 */

#endif //DATASTRUCTURES_PAIRLIST_H
