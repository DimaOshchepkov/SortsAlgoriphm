// Examples.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

#include "../SortsAlgoriphm/BubbleSort.h"
#include "../SortsAlgoriphm/InsertionSort.h"
#include "../SortsAlgoriphm/MergeSort.h"
#include "../SortsAlgoriphm/SupportFunction.h"
#include "../SortsAlgoriphm/CountingSort.h"
#include "../SortsAlgoriphm/TimSort.h"
#include "../SortsAlgoriphm/LibrarySort.h"


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int main()
{
    std::vector<int> vec{ 5, 2, 6, 5, 1, 2, 8 };

    std::cout << "Sorce vector: " << vec << '\n';

    auto bubble_sorted = std::get<0>(bubbleSort(vec));
    std::cout << "Vector sorted by BubbleSort " << bubble_sorted << '\n';

    auto counting_sorted = countingSort<int>(vec, [](int x) {return x; });
    std::cout << "Vector sorted by CountingSort " << counting_sorted << '\n';

    auto insertion_sorted = std::get<0>(insertionSort(vec));
    std::cout << "Vector sorted by InsertionSort " << insertion_sorted << '\n';

    auto merge_sorted = std::get<0>(mergeSort(vec));
    std::cout << "Vector sorted by MergeSort " << merge_sorted << '\n';

    auto library_sorted = std::get<0>(librarySort(vec));
    std::cout << "Vector sorted by LibrarySort " << library_sorted << '\n';

    auto tim_sorted = std::get<0>(timSort(vec));
    std::cout << "Vector sorted by TimSort " << tim_sorted << '\n';
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
