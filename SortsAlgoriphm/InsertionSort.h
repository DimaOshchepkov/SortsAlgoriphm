#pragma once

#include <vector>
#include <functional>
#include <tuple>

/// <summary>
/// In this case count move equals count compare - 1
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="list"></param>
/// <param name="comp"></param>
/// <returns>tuple of sorted vector, count compare and count swap</returns>
template<typename T>
std::tuple<std::vector<T>, long long, long long> insertionSort(std::vector<T> list, std::function<bool(const T&, const T&)> comp = std::less<T>()) {

    long long countCompare = 0;
    long long countSwap = 0;
    // Iterate through the list
    for (unsigned int i = 1; i < list.size(); i++) {
        T elem = list[i];
        int j = i - 1;


        
        countCompare++;
        // Compare elem with the elements before it, and swap if necessary. 
        // Swapping is done by repeatedly moving the elements one unit back.
        while (j >= 0 && !comp(list[j], elem)) {
            countCompare++;
            list[j + 1] = list[j];
            j--;
        }

        countSwap++;
        list[j + 1] = elem;
    }
    return { list, countCompare, countSwap };
}