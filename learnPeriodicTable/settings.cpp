//
//  settings.cpp
//  learnPeriodicTable
//
//  Created by German Ivanov on 12/25/21.
//

#include "settings.hpp"
#include <string>
#include <iostream>
#include <fstream>

std::string loadSettings() {
    std::string settings;
    bool first_try = true;
    while (true) {
        std::ifstream f ("settings.txt");
        if (!f.is_open() && !first_try) {
            std::cout << "Couldn't open the file with settings! Try moving to another directory." << std::endl;
            exit(0);
        }
        std::getline(f, settings);
        f.close();
        if (settings == "" || settings.find('s') != -1 || settings.find('S') != -1)
            initializeSettings();
        else {
            std::cout << std::endl;
            return settings;
        }
        first_try = false;
    }
    return settings;
}


void initializeSettings () {
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::ofstream f ("settings.txt", std::ios::trunc);
    std::string gr = "";
    std::cout << "Select group(s) of elements:" << std::endl;
    std::cout << "1 - 1&2\t\t3 - 5&6" << std::endl;
    std::cout << "2 - 3&4\t\t4 - 7&8" << std::endl;
    std::cout << "Enter a sequence of numbers or 'A' to select all: " << std::flush;
    std::cin >> gr;
    if (gr == "A" || gr == "a")
        gr = "1234";
    
    f << gr;
    f.close();
}
