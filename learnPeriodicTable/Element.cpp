//
//  Element.cpp
//  learnPeriodicTable
//
//  Created by German Ivanov on 12/22/21.
//

#include "Element.hpp"
#include <string>



Element::Element(std::string name, std::string symbol, std::string nameEnglish) {
    this->name = name;
    this->symbol = symbol;
    this->nameEnglish = nameEnglish;
}

std::string Element::getName() {
    return this->name;
}

std::string Element::getSymbol() {
    return this->symbol;
}

