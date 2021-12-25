//
//  Element.hpp
//  learnPeriodicTable
//
//  Created by German Ivanov on 12/22/21.
//

#ifndef Element_hpp
#define Element_hpp

#include <stdio.h>
#include <string>

class Element {
private:
    std::string name;
    std::string symbol;
    std::string nameEnglish;
public:
    Element(std::string name, std::string symbol, std::string nameEnglish = "");
    std::string getName();
    std::string getSymbol();
};


#endif /* Element_hpp */
