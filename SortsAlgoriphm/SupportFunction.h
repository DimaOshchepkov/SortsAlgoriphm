#pragma once

#include <vector>
#include <string>

template <typename T>
bool vectorsEqual(const std::vector<T>& v1, const std::vector<T>& v2) {
    if (v1.size() != v2.size()) {
        return false; // Если размеры векторов разные, они не равны
    }
    return std::equal(v1.begin(), v1.end(), v2.begin()); // Сравниваем значения элементов
}

std::vector<int> readIntegersFromFile(const std::string& filename);