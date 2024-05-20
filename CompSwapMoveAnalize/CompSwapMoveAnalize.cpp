// CompSwapMoveAnalize.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <format>
#include <fstream>

#include <stdexcept>

#include "../SortsAlgoriphm/BubbleSort.h"
#include "../SortsAlgoriphm/InsertionSort.h"
#include "../SortsAlgoriphm/MergeSort.h"
#include "../SortsAlgoriphm/SupportFunction.h"
#include "../SortsAlgoriphm/CountingSort.h"
#include "../SortsAlgoriphm/TimSort.h"

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

int main()
{
    std::ofstream bubbleFileSwap(getSolutionDir() + "\\CountsSwapsMoves\\bubble_swap.txt",
        std::ios_base::app);
    std::ofstream bubbleFileCompare(getSolutionDir() + "\\CountsSwapsMoves\\bubble_compare.txt",
        std::ios_base::app);

    std::ofstream insertionFileSwap(getSolutionDir() + "\\CountsSwapsMoves\\insertion_swap.txt",
        std::ios_base::app);
    std::ofstream insertionFileCompare(getSolutionDir() + "\\CountsSwapsMoves\\insertion_compare.txt",
        std::ios_base::app);
    std::ofstream insertionFileMove(getSolutionDir() + "\\CountsSwapsMoves\\insertion_move.txt",
        std::ios_base::app);

    std::ofstream mergeFileCompare(getSolutionDir() + "\\CountsComparesMoves\\merge_compare.txt",
        std::ios_base::app);
    std::ofstream mergeFileMove(getSolutionDir() + "\\CountsSwapsMoves\\merge_move.txt",
        std::ios_base::app);

    std::ofstream timFileSwap(getSolutionDir() + "\\CountsSwapsMoves\\tim_swap.txt",
        std::ios_base::app);
    std::ofstream timFileCompare(getSolutionDir() + "\\CountsSwapsMoves\\tim_compare.txt",
        std::ios_base::app);
    std::ofstream timFileMove(getSolutionDir() + "\\CountsSwapsMoves\\tim_move.txt",
        std::ios_base::app);

    for (int i = 20'000; i <= 300'000; i += 20'000) {
        auto intUniformFileName = std::format("arrays\\int_uniform_{}.txt", i);
        auto intUniformName = std::format("int_uniform_{}.txt.txt", i);
        auto vec = readIntegersFromFile(getSolutionDir() + "\\" + intUniformFileName);

        auto [soredBubble, comapareBubble, swapBubble] = bubbleSort(vec);
        bubbleFileSwap << i << " " << swapBubble << "\n";
        bubbleFileCompare << i << " " << comapareBubble << "\n";

        auto [soredIsertion, comapareIsertion, swapIsertion, moveIsertion] = insertionSort(vec);
        insertionFileSwap << i << " " << swapIsertion << "\n";
        insertionFileCompare << i << " " << comapareIsertion << "\n";
        insertionFileMove << i << " " << moveIsertion << "\n";

        auto [soredMerge, compareMerge, moveMerge] = mergeSort(vec);
        mergeFileCompare << i << " " << compareMerge << "\n"; // Assuming mergeFileSwap is intended for move counts
        mergeFileMove << i << " " << moveMerge << "\n";

        auto [soredTim, comapareTim, swapTim, moveTim] = timSort(vec);
        timFileSwap << i << " " << swapTim << "\n";
        timFileCompare << i << " " << comapareTim << "\n";
        timFileMove << i << " " << moveTim << "\n";

        std::cout << i << " size arrays completed\n";
    }

    // Закрытие файлов
    bubbleFileSwap.close();
    bubbleFileCompare.close();

    insertionFileSwap.close();
    insertionFileCompare.close();
    insertionFileMove.close();

    mergeFileCompare.close();
    mergeFileMove.close();

    timFileSwap.close();
    timFileCompare.close();
    timFileMove.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
