#include <Benchmark/benchmark.h>
#include <memory>
#include <numeric>
#include <string>
#include <random>


#include <stdexcept>

#include "../SortsAlgoriphm/BubbleSort.h"
#include "../SortsAlgoriphm/InsertionSort.h"
#include "../SortsAlgoriphm/MergeSort.h"
#include "../SortsAlgoriphm/SupportFunction.h"
#include "../SortsAlgoriphm/CountingSort.h"
#include "../SortsAlgoriphm/TimSort.h"

using namespace std;


static void BM_MergeSort(benchmark::State& state, int N) {
    std::vector<int> vec(N);
    std::iota(vec.begin(), vec.end(), 0);

    for (auto _ : state) {
        auto arr = mergeSort(vec);
        benchmark::DoNotOptimize(arr);
    }
}


static void BM_InsertionSort(benchmark::State& state, int N) {
    std::vector<int> vec(N);
    std::iota(vec.rbegin(), vec.rend(), 0);

    for (auto _ : state) {
        auto arr = insertionSort(vec);
        benchmark::DoNotOptimize(arr);
    }
}

static void BM_BubbleSort(benchmark::State& state, int N) {
    std::vector<int> vec(N);
    std::iota(vec.rbegin(), vec.rend(), 0);

    for (auto _ : state) {
        auto arr = bubbleSort(vec);
        benchmark::DoNotOptimize(arr);
    }
}



static void BM_CountingSort(benchmark::State& state, int N) {
    std::vector<int> vec(N);
    std::iota(vec.rbegin(), vec.rend(), 2'000'000'000 - N);


    for (auto _ : state) {
        auto arr = countingSort<int>(vec, [](auto p) { return p; });
        benchmark::DoNotOptimize(arr);
    }
}

std::vector<int> generateRandomArray(int a, int b, int size) {
    // Создаем генератор случайных чисел
    std::random_device rd;
    std::mt19937 generator(rd());

    // Создаем равномерное распределение в диапазоне [a, b]
    std::uniform_int_distribution<> distribution(a, b);

    // Создаем пустой вектор для хранения случайных чисел
    std::vector<int> randomArray;

    // Заполняем вектор случайными числами
    for (int i = 0; i < size; ++i) {
        randomArray.push_back(distribution(generator));
    }

    // Возвращаем сгенерированный массив
    return randomArray;
}

static void BM_TimSort(benchmark::State& state, int N) {

    std::vector<int> vec(N);
    std::iota(vec.rbegin(), vec.rend(), 0);

    vec = generateRandomArray(0, N / 100, N);

    for (auto _ : state) {
        auto arr = timSort<int>(vec);
        benchmark::DoNotOptimize(arr);
    }
}


int main(int argc, char** argv) {

    for (int i = 5'000'000; i <= 41'000'000; i += 3'000'000) {
        benchmark::RegisterBenchmark("BM_MergeSort/" + std::to_string(i), BM_MergeSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_TimSort/" + std::to_string(i), BM_TimSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_CountingSort/" + std::to_string(i), BM_CountingSort, i)->Unit(benchmark::kMillisecond);
    }

    for (int i = 20'000; i <= 300'000; i += 20'000) {
        benchmark::RegisterBenchmark("BM_MergeSort/" + std::to_string(i), BM_MergeSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_CountingSort/" + std::to_string(i), BM_CountingSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_InsertionSort/" + std::to_string(i), BM_InsertionSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_BubbleSort/" + std::to_string(i), BM_BubbleSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_TimSort/" + std::to_string(i), BM_TimSort, i)->Unit(benchmark::kMillisecond);
    }

    for (int i = 1'000; i <= 10'000; i += 1'000) {
        benchmark::RegisterBenchmark("BM_MergeSort/" + std::to_string(i), BM_MergeSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_CountingSort/" + std::to_string(i), BM_CountingSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_InsertionSort/" + std::to_string(i), BM_InsertionSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_BubbleSort/" + std::to_string(i), BM_BubbleSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_TimSort/" + std::to_string(i), BM_TimSort, i)->Unit(benchmark::kMillisecond);
    }

    for (int i = 50; i <= 500; i += 50) {
        benchmark::RegisterBenchmark("BM_MergeSort/" + std::to_string(i), BM_MergeSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_CountingSort/" + std::to_string(i), BM_CountingSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_InsertionSort/" + std::to_string(i), BM_InsertionSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_BubbleSort/" + std::to_string(i), BM_BubbleSort, i)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_TimSort/" + std::to_string(i), BM_TimSort, i)->Unit(benchmark::kMillisecond);
    }



    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();

    return 0;
}