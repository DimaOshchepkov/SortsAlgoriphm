#include "pch.h"
#include "SupportFunction.h"

#include <fstream>
#include <iostream>

std::vector<int> readIntegersFromFile(const std::string& filename) {
    std::vector<int> integers;
    std::ifstream file(filename);
    int number;

    if (file.is_open()) {
        while (file >> number) {
            integers.push_back(number);
        }
        file.close();
    }
    else {
        std::cout << "Unable to open file " << filename << std::endl;
    }

    return integers;
}