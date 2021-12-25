//
//  load.cpp
//  learnPeriodicTable
//
//  Created by German Ivanov on 12/25/21.
//

#include "load.hpp"

#include <iostream>
#include <string>
#include <vector>
#include "Element.hpp"

// load elementsTable's:
#include "elements/elements12.hpp"
#include "elements/elements34.hpp"
#include "elements/elements56.hpp"
#include "elements/elements78.hpp"

std::vector<Element> load(std::string str) {
//    std::cout << "Loading: " << str << std::endl;
    std::vector<Element> res = {};
    if (str == "A") {
        str = "1234";
    }
    if (str.find("1") != -1) {
        res.insert(res.end(), elementsTable12.begin(), elementsTable12.end());
    }
    if (str.find("2") != -1) {
        res.insert(res.end(), elementsTable34.begin(), elementsTable34.end());
    }
    if (str.find("3") != -1) {
        res.insert(res.end(), elementsTable56.begin(), elementsTable56.end());
    }
    if (str.find("4") != -1) {
        res.insert(res.end(), elementsTable78.begin(), elementsTable78.end());
    }
    return res;
}

