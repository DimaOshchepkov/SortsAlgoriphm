#include <Benchmark/benchmark.h>
#include <memory>
#include <iostream>
#include <string>
#include <format>

#include <stdexcept>

#include "../SortsAlgoriphm/BubbleSort.h"
#include "../SortsAlgoriphm/InsertionSort.h"
#include "../SortsAlgoriphm/MergeSort.h"
#include "../SortsAlgoriphm/SupportFunction.h"
#include "../SortsAlgoriphm/CountingSort.h"

using namespace std;

#define STRINGIFY(x) #x

#define EXPAND(x) STRINGIFY(x)

string solutionDir;
string getSolutionDir() {
    if (!solutionDir.empty())
        return solutionDir;
    string s = EXPAND(SOLDIR);
    s.erase(0, 1); // erase the first quote
    s.erase(s.size() - 2); // erase the last quote and the dot

    size_t found = s.find_last_of('\\');

    if (found != std::string::npos) {
        s = s.substr(0, found);
    }

    solutionDir = s;
    return solutionDir;
}


static void BM_MergeSort(benchmark::State& state, const std::string& arrayFileName) {
    auto fullPath = getSolutionDir() + "\\" + arrayFileName;
    std::vector<int> array = readIntegersFromFile(fullPath);

    for (auto _ : state) {
        auto arr = mergeSort(array);
        benchmark::DoNotOptimize(arr);
    }
}


static void BM_InsertionSort(benchmark::State& state, const std::string& arrayFileName) {
    auto fullPath = getSolutionDir() + "\\" + arrayFileName;
    std::vector<int> array = readIntegersFromFile(fullPath);

    for (auto _ : state) {
        auto arr = insertionSort(array);
        benchmark::DoNotOptimize(arr);
    }
}

static void BM_BubbleSort(benchmark::State& state, const std::string& arrayFileName) {
    auto fullPath = getSolutionDir() + "\\" + arrayFileName;
    std::vector<int> array = readIntegersFromFile(fullPath);

    for (auto _ : state) {
        auto arr = bubbleSort(array);
        benchmark::DoNotOptimize(arr);
    }
}



static void BM_CountingSort(benchmark::State& state, const std::string& arrayFileName) {
    auto fullPath = getSolutionDir() + "\\" + arrayFileName;
    std::vector<int> array = readIntegersFromFile(fullPath);

    for (auto _ : state) {
        auto arr = countingSort<int>(array, [](auto p) { return p; });
        benchmark::DoNotOptimize(arr);
    }
}


int main(int argc, char** argv) {

    for (int i = 1'000'000; i <= 20'000'000; i += 1'000'000) {

        auto intNormalFileName = std::format("arrays\\int_normal_{}.txt", i);
        auto intNormalName = std::format("int_normal_{}.txt", i);
        benchmark::RegisterBenchmark("BM_MergeSort/" + intNormalName, BM_MergeSort, intNormalFileName)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_CountingSort/" + intNormalName, BM_CountingSort, intNormalFileName)->Unit(benchmark::kMillisecond);

        auto intUniformFileName = std::format("arrays\\int_uniform_{}.txt", i);
        auto intUniformName = std::format("int_uniform_{}.txt.txt", i);
        benchmark::RegisterBenchmark("BM_MergeSort/" + intUniformName, BM_MergeSort, intUniformFileName)->Unit(benchmark::kMillisecond);
       
        benchmark::RegisterBenchmark("BM_CountingSort/" + intUniformName, BM_CountingSort, intUniformFileName)->Unit(benchmark::kMillisecond);
    }
    /*
    
    for (int i = 10'000; i <= 300'000; i += 10'000) {
        auto intNormalFileName = std::format("arrays\\int_normal_{}.txt", i);
        auto intNormalName = std::format("int_normal_{}.txt", i);
        benchmark::RegisterBenchmark("BM_MergeSort/" + intNormalName, BM_MergeSort, intNormalFileName)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_InsertionSort/" + intNormalName, BM_InsertionSort, intNormalFileName)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_BubbleSort/" + intNormalName, BM_BubbleSort, intNormalFileName)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_CountingSort/" + intNormalName, BM_CountingSort, intNormalFileName)->Unit(benchmark::kMillisecond);

        auto intUniformFileName = std::format("arrays\\int_uniform_{}.txt", i);
        auto intUniformName = std::format("int_uniform_{}.txt", i);
        benchmark::RegisterBenchmark("BM_MergeSort/" + intUniformName, BM_MergeSort, intUniformFileName)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_InsertionSort/" + intUniformName, BM_InsertionSort, intUniformFileName)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_BubbleSort/" + intUniformName, BM_BubbleSort, intUniformFileName)->Unit(benchmark::kMillisecond);
        benchmark::RegisterBenchmark("BM_CountingSort/" + intUniformName, BM_CountingSort, intUniformFileName)->Unit(benchmark::kMillisecond);
    }*/
    /*
    for (int i = 500; i <= 10'000; i += 500) {
        auto intNormalFileName = std::format("arrays\\int_normal_{}.txt", i);
        auto intNormalName = std::format("int_normal_{}.txt", i);
        benchmark::RegisterBenchmark("BM_MergeSort/" + intNormalName, BM_MergeSort, intNormalFileName)
            ->Unit(benchmark::kMillisecond)
            ->Iterations(100);
        

        auto intUniformFileName = std::format("arrays\\int_uniform_{}.txt", i);
        auto intUniformName = std::format("int_uniform_{}.txt", i);
        benchmark::RegisterBenchmark("BM_MergeSort/" + intUniformName, BM_MergeSort, intUniformFileName)
            ->Unit(benchmark::kMillisecond)
            ->Iterations(100);
     
    }

    for (int i = 50; i <= 500; i += 50) {
        auto intNormalFileName = std::format("arrays\\int_normal_{}.txt", i);
        auto intNormalName = std::format("int_normal_{}.txt", i);
        benchmark::RegisterBenchmark("BM_MergeSort/" + intNormalName, BM_MergeSort, intNormalFileName)
            ->Unit(benchmark::kMillisecond)
            ->Iterations(100);


        auto intUniformFileName = std::format("arrays\\int_uniform_{}.txt", i);
        auto intUniformName = std::format("int_uniform_{}.txt", i);
        benchmark::RegisterBenchmark("BM_MergeSort/" + intUniformName, BM_MergeSort, intUniformFileName)
            ->Unit(benchmark::kMillisecond)
            ->Iterations(100);

    }*/

    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();

    return 0;
}