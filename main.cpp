#include <iostream>
#include "Pair.h"
#include "DataTypes/Integer.h"
#include "Lists/PairList.h"

int main() {
    auto* list = new PairList<Integer>();
    list->add(5);
    std::cout << *list << std::endl;
    list->add(6);
    std::cout << *list << std::endl;
    list->add(1, 7);
    std::cout << *list << std::endl;
    delete list;
}
