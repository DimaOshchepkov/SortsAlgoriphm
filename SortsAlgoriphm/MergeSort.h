#pragma once


#include <vector>
#include <functional>



template<typename T>
void merge(std::vector<T>& list, int lo, int mi, int hi, std::function<bool(const T&, const T&)> comp,
    long long& countCompare, long long& countMove) {
    int n1 = mi - lo + 1; // ������ ������� ����������
    int n2 = hi - mi;     // ������ ������� ����������

    // ������� ��������� ������� ��� �������� ������ � ������� �����������
    std::vector<T> left(n1);
    std::vector<T> right(n2);

    countMove += (n1 + n2);
    // �������� ������ �� ��������� �������
    for (int i = 0; i < n1; i++) 
        left[i] = list[lo + i];
    for (int j = 0; j < n2; j++)
        right[j] = list[mi + 1 + j];

    // ������� ��� ������ ��������� ��������
    int i = 0, j = 0;

    // ������ ��� ������ ��������� �������
    int k = lo;

    countMove += (n1 + n2);
    // ���������� ��������� ������� ������� � �������� ������
    while (i < n1 && j < n2) {
        countCompare++;
        if (comp(left[i], right[j])) {
            list[k] = left[i];
            i++;
        }
        else {
            list[k] = right[j];
            j++;
        }
        k++;
    }

    // �������� ���������� �������� �� left[], ���� ����� ����
    while (i < n1) {
        list[k] = left[i];
        i++;
        k++;
    }

    // �������� ���������� �������� �� right[], ���� ����� ����
    while (j < n2) {
        list[k] = right[j];
        j++;
        k++;
    }
}

template<typename T>
void _mergeSort(std::vector<T>& list, int lo, int hi, std::function<bool(const T&, const T&)> comp,
    long long& countCompare, long long& countMove) {
    if (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        _mergeSort(list, lo, mi, comp, countCompare, countMove);
        _mergeSort(list, mi + 1, hi, comp, countCompare, countMove);
        merge(list, lo, mi, hi, comp, countCompare, countMove);
    }
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="list"></param>
/// <param name="comp"></param>
/// <returns>tuple of soreted list, count comapare and count move</returns>
template<typename T>
std::tuple<std::vector<T>, long long, long long> mergeSort(std::vector<T> list, std::function<bool(const T&, const T&)> comp = std::less<T>()) {
    long long countCompare = 0;
    long long countMove = 0;

    _mergeSort(list, 0, list.size() - 1, comp, countCompare, countMove);
    return { list, countCompare, countMove };
}