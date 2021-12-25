//
//  main.cpp
//  learnPeriodicTable
//
//  Created by German Ivanov on 12/22/21.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "Element.hpp"
#include "load.hpp"
#include "settings.hpp"


enum modes {
    m1,
    m2,
    m3,
    S,
    Q,
    incorrect
};

modes getMode(std::string str) {
    if (str == "1") return m1;
    if (str == "2") return m2;
    if (str == "3") return m3;
    if (str == "S" || str == "s") return S;
    if (str == "Q" || str == "q") return Q;
    return incorrect;
}


int getRandom(int end, int start=0) {
    srand((unsigned) time(NULL));
    int random = rand();
    return (int)start + random % end;
}

int learnElements(std::vector<Element> elementsTable) {
    std::string input;
    std::vector<Element> toLearn = elementsTable;
    for (int i = 0; i < elementsTable.size(); i++) {
        int el = getRandom((int) toLearn.size());
        std::cout << toLearn[el].getName() << " -> " << toLearn[el].getSymbol();
        input = std::cin.get();
        if (input == "q") {
            return 1;
        }
        toLearn.erase(toLearn.begin() + el);
    }
    std::cout << "You've learned " << elementsTable.size() << " elements." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    input = std::cin.get();
    return 0;
}

int testElements(std::vector<Element> elementsTable, bool testSymbol=true) {
    std::string input;
    std::vector<Element> toLearn = elementsTable;
    int res = 0;
    for (int i = 0; i < elementsTable.size(); i++) {
        int el = getRandom((int)toLearn.size());
        if (testSymbol){
            std::cout << toLearn[el].getName() << " -> ";
            std::cin >> input;
        }
        else {
            std::cout << toLearn[el].getSymbol() << " -> ";
            std::cin >> input;
        }
        if (input == "q") {
            return 1;
        }
        else if (testSymbol && input != toLearn[el].getSymbol()) {
            std::cout << "Incorrect! It should be \"" << toLearn[el].getSymbol() << "\"." << std::endl;
        }
        else if (!testSymbol && input != toLearn[el].getName()) {
            std::cout << "Incorrect! It should be \"" << toLearn[el].getName() << "\"." << std::endl;
        }
        else
            res++;
        toLearn.erase(std::next(toLearn.begin(), el));
    }
    std::cout << "Done!" << std::endl;
    std::cout << "Your result: " << res << "/" << elementsTable.size() << " (" << std::ceil((float)res/elementsTable.size()*10000) / 100 << "%)" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    input = std::cin.get();
    return 0;
}

int main(int argc, const char * argv[]) {
    std::cout << "Welcome!" << std::endl;
    while (true) {
        auto elementsTable = load(loadSettings());
        std::cout << "1 - Learn Elements" << std::endl << "2 - Test name -> symbol" << std::endl << "3 - Test symbol -> name" << std::endl << "S - Settings" << std::endl << "Q - Quit" << std::endl;
        std::cout << "Choose one: ";
        std::string mode;
        std::cin >> mode;
        std::cout << std::endl << std::flush;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        switch (getMode(mode)) {
            case m1:
                learnElements(elementsTable);
                break;
            case m2:
                testElements(elementsTable, false);
                break;
            case m3:
                testElements(elementsTable);
                break;
            case S:
                initializeSettings();
                break;
            case Q:
                return 0;
                break;
            case incorrect:
                std::cout << "Incorrect mode!" << std::endl;
                break;
        }
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << std::endl << std::flush;
    }
    
    return 0;
}
