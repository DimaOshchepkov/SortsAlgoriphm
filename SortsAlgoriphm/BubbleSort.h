#pragma once

#include <vector>
#include <functional>
#include <tuple>

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr"></param>
/// <param name="comp"></param>
/// <returns>tuple of soreted array, count comapare and count swap</returns>
template<typename T>
std::tuple<std::vector<T>, long long, long long> bubbleSort(std::vector<T> arr, std::function<bool(const T&, const T&)> comp = std::less<T>()) {

    int n = arr.size();
    bool swapped;

    long long count_swap = 0;
    long long count_compare = 0;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            count_compare++;
            if (!comp(arr[j], arr[j + 1])) {
                count_swap++;
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Если внутренний цикл не произвел обмена, выходим
        if (!swapped)
            break;
    }
    return { arr, count_compare, count_swap };
}

