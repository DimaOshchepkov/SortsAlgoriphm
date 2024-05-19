
#include "pch.h"
#include "../SortsAlgoriphm/BubbleSort.h"
#include "../SortsAlgoriphm/InsertionSort.h"
#include "../SortsAlgoriphm/MergeSort.h"
#include "../SortsAlgoriphm/SupportFunction.h"
#include "../SortsAlgoriphm/CountingSort.h"

#include <functional>
#include <utility>
#include <tuple>

// Тест на пустом векторе
template <typename SortFunction>
void testTupleVector(SortFunction sortFunction) {
    std::vector<std::pair<int, int>> x = {
        {1, 2},
        {2, 3},
        {2, 4},
        {1, 7}
    };

    auto y = std::get<0>(sortFunction(x, [](const auto& t1, const auto& t2) {return t1.first < t2.first; }));
    EXPECT_TRUE(vectorsEqual(y, {
        {1, 2},
        {1, 7},
        {2, 3},
        {2, 4},
        }));
}

// Тест на пустом векторе
template <typename SortFunction>
void testEmptyVector(SortFunction sortFunction) {
    std::vector<int> x;
    auto y = std::get<0>(sortFunction(x, std::less<int>()));
    EXPECT_TRUE(vectorsEqual(y, {}));
}

// Тест на отсортированном векторе
template <typename SortFunction>
void testSortedVector(SortFunction sortFunction) {
    std::vector<int> x{ 1, 2, 3, 4, 5 };
    auto y = std::get<0>(sortFunction(x, std::less<int>()));
    EXPECT_TRUE(vectorsEqual(y, { 1, 2, 3, 4, 5 }));
}

// Тест на обратно отсортированном векторе
template <typename SortFunction>
void testReverseSortedVector(SortFunction sortFunction) {
    std::vector<int> x{ 5, 4, 3, 2, 1 };
    auto y = std::get<0>(sortFunction(x, std::less<int>()));
    EXPECT_TRUE(vectorsEqual(y, { 1, 2, 3, 4, 5 }));
}

// Тест на векторе с дубликатами
template <typename SortFunction>
void testVectorWithDuplicates(SortFunction sortFunction) {
    std::vector<int> x{ 3, 2, 5, 2, 3, 1 };
    auto y = std::get<0>(sortFunction(x, std::less<int>()));
    EXPECT_TRUE(vectorsEqual(y, { 1, 2, 2, 3, 3, 5 }));
}

// Тест на большом векторе
template <typename SortFunction>
void testLargeVector(SortFunction sortFunction) {
    std::vector<int> x;
    const int size = 1000;
    for (int i = size; i > 0; --i) {
        x.push_back(i);
    }
    std::vector<int> y = std::get<0>(sortFunction(x, std::less<int>()));
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(y[i], i + 1);
    }
}

template <typename SortFunction>
void testVectorCommon(SortFunction sortFunction) {
    std::vector<int> x{ 1, 5, 2, 5, 2, 3 };
    auto y = std::get<0>(sortFunction(x, std::less<int>()));
    EXPECT_TRUE(vectorsEqual(y, { 1, 2, 2, 3, 5, 5 }));
}




TEST(bubbleSort, SimpleTest) {
    testVectorCommon(bubbleSort<int>);
}
TEST(bubbleSort, EmptyVector) {
    testEmptyVector(bubbleSort<int>);
}
TEST(bubbleSort, SortedVector) {
    testSortedVector(bubbleSort<int>);
}
TEST(bubbleSort, ReverseSortedVector) {
    testReverseSortedVector(bubbleSort<int>);
}
TEST(bubbleSort, DuplicateElements) {
    testVectorWithDuplicates(bubbleSort<int>);
}
TEST(bubbleSort, LargeVector) {
    testLargeVector(bubbleSort<int>);
}


TEST(insertionSort, SimpleTest) {
    testVectorCommon(insertionSort<int>);
}
TEST(insertionSort, EmptyVector) {
    testEmptyVector(insertionSort<int>);
}
TEST(insertionSort, SortedVector) {
    testSortedVector(insertionSort<int>);
}
TEST(insertionSort, ReverseSortedVector) {
    testReverseSortedVector(insertionSort<int>);
}
TEST(insertionSort, DuplicateElements) {
    testVectorWithDuplicates(insertionSort<int>);
}
TEST(insertionSort, LargeVector) {
    testLargeVector(insertionSort<int>);
}


TEST(mergeSort, SimpleTest) {
    testVectorCommon(mergeSort<int>);
}
TEST(mergeSort, EmptyVector) {
    testEmptyVector(mergeSort<int>);
}
TEST(mergeSort, SortedVector) {
    testSortedVector(mergeSort<int>);
}
TEST(mergeSort, ReverseSortedVector) {
    testReverseSortedVector(mergeSort<int>);
}
TEST(mergeSort, DuplicateElements) {
    testVectorWithDuplicates(mergeSort<int>);
}
TEST(mergeSort, LargeVector) {
    testLargeVector(mergeSort<int>);
}




