#pragma once

#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>



// Функция сортировки вставками для части вектора
template <typename T>
void insertionSortTim(std::vector<T>& arr, int left, int right,
    std::function<bool(const T&, const T&)> comp, long long& comparisons, long long& swaps, long long& moves) {
    for (int i = left + 1; i <= right; ++i) {
        T temp = arr[i];
        int j = i - 1;
        while (j >= left && !comp(arr[j], temp)) {
            ++comparisons;
            ++moves;
            arr[j + 1] = arr[j];
            --j;
            
        }
        ++swaps;
        arr[j + 1] = temp;
        if (j >= left) ++comparisons;
    }
}

// Функция слияния двух отсортированных частей вектора
template <typename T>
void mergeTim(std::vector<T>& arr, int l, int m, int r,
    std::function<bool(const T&, const T&)> comp, long long& comparisons, long long& moves) {
    int len1 = m - l + 1;
    int len2 = r - m;

    std::vector<T> left(len1);
    std::vector<T> right(len2);

    moves += (len1 + len2);
    for (int i = 0; i < len1; ++i) {
        left[i] = arr[l + i];
    }

    for (int i = 0; i < len2; ++i) {
        right[i] = arr[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    moves += (len1 + len2);
    while (i < len1 && j < len2) {
        ++comparisons;
        if (comp(left[i], right[j])) {
            arr[k] = left[i];
            ++i;
        }
        else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }

    while (i < len1) {
        arr[k] = left[i];
        ++k;
        ++i;
    }

    while (j < len2) {
        arr[k] = right[j];
        ++k;
        ++j;
    }
}

// Timsort для вектора
template <typename T>
std::tuple<std::vector<T>, long long, long long, long long>
timSort(std::vector<T> arr, std::function<bool(const T&, const T&)> comp = std::less<T>()) {

    const int RUN = 32;

    long long comparisons = 0;
    long long swaps = 0;
    long long moves = 0;
    int n = arr.size();

    // Сортировка подмассивов размером RUN
    for (int i = 0; i < n; i += RUN) {
        insertionSortTim(arr, i, std::min(i + RUN - 1, n - 1), comp, comparisons, swaps, moves);
    }

    // Слияние отсортированных подмассивов
    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min(left + 2 * size - 1, n - 1);

            if (mid < right) {
                mergeTim(arr, left, mid, right, comp, comparisons, moves);
            }
        }
    }

    return { arr, comparisons, swaps, moves };
}
