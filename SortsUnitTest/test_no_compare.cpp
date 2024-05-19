
#include "pch.h"
#include "../SortsAlgoriphm/CountingSort.h"
#include "../SortsAlgoriphm/SupportFunction.h"

#include <functional>


// Тест на пустом векторе
template <typename SortFunction>
void testEmptyVector(SortFunction sortFunction) {
    std::vector<int> x;
    x = sortFunction(x, [](auto p){return p;});
    EXPECT_TRUE(vectorsEqual(x, {}));
}

// Тест на отсортированном векторе
template <typename SortFunction>
void testSortedVector(SortFunction sortFunction) {
    std::vector<int> x{ 1, 2, 3, 4, 5 };
    x = sortFunction(x, [](auto p){return p;});
    EXPECT_TRUE(vectorsEqual(x, { 1, 2, 3, 4, 5 }));
}

// Тест на обратно отсортированном векторе
template <typename SortFunction>
void testReverseSortedVector(SortFunction sortFunction) {
    std::vector<int> x{ 5, 4, 3, 2, 1 };
    x = sortFunction(x, [](auto p){return p;});
    EXPECT_TRUE(vectorsEqual(x, { 1, 2, 3, 4, 5 }));
}

// Тест на векторе с дубликатами
template <typename SortFunction>
void testVectorWithDuplicates(SortFunction sortFunction) {
    std::vector<int> x{ 3, 2, 5, 2, 3, 1 };
    x = sortFunction(x, [](auto p){return p;});
    EXPECT_TRUE(vectorsEqual(x, { 1, 2, 2, 3, 3, 5 }));
}

// Тест на большом векторе
template <typename SortFunction>
void testLargeVector(SortFunction sortFunction) {
    std::vector<int> x;
    const int size = 1000;
    for (int i = size; i > 0; --i) {
        x.push_back(i);
    }
    x = sortFunction(x, [](auto p){return p;});
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(x[i], i + 1);
    }
}

template <typename SortFunction>
void testVectorCommon(SortFunction sortFunction) {
    std::vector<int> x{ 1, 5, 2, 5, 2, 3 };
    x = sortFunction(x, [](int x) {return x; });
    EXPECT_TRUE(vectorsEqual(x, { 1, 2, 2, 3, 5, 5 }));
}


TEST(countingSort, SimpleTest) {
    testVectorCommon(countingSort<int>);
}
TEST(countingSort, EmptyVector) {
    testEmptyVector(countingSort<int>);
}
TEST(countingSort, SortedVector) {
    testSortedVector(countingSort<int>);
}
TEST(countingSort, ReverseSortedVector) {
    testReverseSortedVector(countingSort<int>);
}
TEST(countingSort, DuplicateElements) {
    testVectorWithDuplicates(countingSort<int>);
}
TEST(countingSort, LargeVector) {
    testLargeVector(countingSort<int>);
}