#pragma once
#include <vector>
#include <functional>

using namespace std;

template <typename T>
vector<T> countingSort(vector<T>& inputArray, std::function<int (const T&)> intExtractor)
{

    int N = inputArray.size();

    // Finding the maximum element of array inputArray[].
    int M = 0;

    for (int i = 0; i < N; i++)
        M = max(M, intExtractor(inputArray[i]));

    // Initializing countArray[] with 0
    vector<T> countArray(M + 1, 0);

    // Mapping each element of inputArray[] as an index
    // of countArray[] array

    for (int i = 0; i < N; i++)
        countArray[intExtractor(inputArray[i])]++;

    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    // Creating outputArray[] from countArray[] array
    vector<T> outputArray(N);

    for (int i = N - 1; i >= 0; i--)
    {

        outputArray[countArray[intExtractor(inputArray[i])] - 1] = inputArray[i];


        countArray[intExtractor(inputArray[i])]--;
    }

    return outputArray;
}