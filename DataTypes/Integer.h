//
// Created by Ikak on 29/04/2022.
//

#ifndef DATASTRUCTURES_INTEGER_H
#define DATASTRUCTURES_INTEGER_H

#include <iostream>

class Integer {
private:
    int val;
public:
    Integer() = default;
    Integer(int val);
    Integer(const Integer &o);
    Integer(Integer&& o) noexcept ;
    Integer& operator=(const Integer& o);
    Integer& operator=(const int& o);
    friend std::ostream & operator<<(std::ostream& os, const Integer& dt);
    bool operator==(const Integer& o) const {return val == o.val;}
};


#endif //DATASTRUCTURES_INTEGER_H
