//
// Created by Ikak on 29/04/2022.
//

#include "Integer.h"

Integer::Integer(int val) : val(val){

}

Integer &Integer::operator=(const Integer& o) {
    val = o.val;
    return *this;
}

Integer &Integer::operator=(const int& o) {
    val = o;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Integer &integer) {
    return os << integer.val;
}

Integer::Integer(const Integer &o) : val(o.val){

}

Integer::Integer(Integer &&o) noexcept {
    val = o.val;
}

