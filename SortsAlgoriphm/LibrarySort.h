#pragma once

#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <functional>

double log2(int x) {
    return log(x) / log(2);
}

template <typename T>
std::tuple<std::vector<T>, long long, long long> librarySort(std::vector<T>& vec,
    std::function<bool(const T&, const T&)> comp = std::less<T>()) {

    if (vec.size() <= 1) {
        return { vec, 0, 0 };
    }
    long long countComapare = 0, countMove = 0;
    auto index = vec;
    int n = index.size();
    std::vector<std::vector<T>> library(2, std::vector<T>(n));
    std::vector<T> gaps(n + 1, false);
    std::vector<bool> numbered(n + 1, false);

    int lib_size = 1;
    int index_pos = 1;
    bool target_lib = 0;
    library[target_lib][0]= index[0];
    int index_last_el_in_gaps = 0;

    while (index_pos < n) {
        // binary search
        countComapare += static_cast<long long>(log2(lib_size)) + 1;
        int insert = std::distance(
            std::begin(library[target_lib]),
            std::lower_bound(std::begin(library[target_lib]),
                std::next(std::begin(library[target_lib]), lib_size), index[index_pos], comp));

        // if there is no gap to insert a new index ...

        if (numbered[insert] == true) {
            int prov_size = 0, next_target_lib = !target_lib;

            // update library and clear gaps

            for (int i = 0; i <= std::max(index_last_el_in_gaps, lib_size); i++) {
                if (numbered[i] == true) {
                    countMove++; 

                    library[next_target_lib][prov_size] = gaps[i];
                    prov_size++;
                    numbered[i] = false;
                }

                if (i <= lib_size) {
                    countMove++;
                    library[next_target_lib][prov_size] =
                        library[target_lib][i];
                    prov_size++;
                }
            }

            target_lib = next_target_lib;
            lib_size = prov_size - 1;
        }
        else {
            countMove++;
            numbered[insert] = true;
            gaps[insert] = index[index_pos];
            index_last_el_in_gaps = insert;
            index_pos++;
        }
    }
    

    int index_pos_for_output = 0;
    for (int i = 0; index_pos_for_output < n; i++) {
        if (numbered[i] == true) {
            countMove++;
            // std::cout << gaps[i] << std::endl;
            index[index_pos_for_output] = gaps[i];
            index_pos_for_output++;
        }

        if (i < lib_size) {
            countMove++;
            // std::cout << library[target_lib][i] << std::endl;
            index[index_pos_for_output] = library[target_lib][i];
            index_pos_for_output++;
        }
    }

    return { index, countComapare, countMove };
}