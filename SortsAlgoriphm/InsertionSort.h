#pragma once

#include <vector>
#include <functional>
#include <tuple>

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="list"></param>
/// <param name="comp"></param>
/// <returns>tuple of sorted vector, count compares, count swaps, count moves</returns>
template<typename T>
std::tuple<std::vector<T>, long long, long long, long long>
insertionSort(std::vector<T> list, std::function<bool(const T&, const T&)> comp = std::less<T>()) {

    long long countCompare = 0;
    long long countSwap = 0;
    long long countMove = 0;
    // Iterate through the list
    for (unsigned int i = 1; i < list.size(); i++) {
        T elem = list[i];
        auto it = std::lower_bound(list.begin(), list.begin() + i, elem, comp);
        size_t j = std::distance(list.begin(), it);
        countCompare += static_cast<long long>(log2(i)) + 1;

        if (j < i) {
            T temp = list[i];
            for (size_t k = i; k > j; --k) {
                list[k] = list[k - 1];
                countMove++;
            }
            countSwap++;
            list[j] = temp;
        }
    }
    return { list, countCompare, countSwap, countMove };
}