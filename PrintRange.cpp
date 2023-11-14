#include <iostream>
#include <string>
#include <sstream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

template <typename IteratorType>
void PrintRange(IteratorType it1, IteratorType it2) {
    bool first = true;
    for (auto it = it1; it != it2; ++it) {
        if (!first) {
            std::cout << ' ';
        }
        first = false;
        std::cout << *it;
    }
    std::cout << std::endl;
}

template <typename Container, typename ContainerElement>
void FindAndPrint(const Container& container, const ContainerElement& element) {
    auto new_end_it = find(container.begin(), container.end(), element);
    PrintRange(container.begin(), new_end_it);
    PrintRange(new_end_it, container.end());
}

template <typename IteratorType>
auto MakeVector(IteratorType it1, IteratorType it2) {
    return std::vector(it1, it2);
}

// функция, записывающая элементы диапазона в строку
template <typename It>
string PrintRangeToString(It range_begin, It range_end) {
    // удобный тип ostringstream -> https://ru.cppreference.com/w/cpp/io/basic_ostringstream
    ostringstream out;
    for (auto it = range_begin; it != range_end; ++it) {
        out << *it << " "s;
    }
    out << endl;
    // получаем доступ к строке с помощью метода str для ostringstream
    return out.str();
}

// функция сортировки слиянием
template <typename It>
void SwapVal(It it1, It it2) {
    auto buf = *it1;
    *it1 = *it2;
    *it2 = buf;
}
template <typename It>
void MergeSortedRanges(It first_begin, It first_end, It second_begin, It second_end) {
    // Итератор для первого поддиапазона
    It i = first_begin;
    
    // Итератор для второго поддиапазона
    It j = second_begin;

    while (i < first_end && j < second_end) {
        if (*i < *j) {
            ++i;
        } else {
            auto buf = *j;
            for (auto k = j; k != i; --k) {
                *(k) = *(k - 1);
            }
            *(i) = buf;
            ++i;
            ++j;
            ++first_end;
        }
    }
}

// функция сортировки слиянием
template <typename It>
void MergeSort(It range_begin, It range_end) {
    int size = range_end - range_begin;
    if (size == 2){
         if (*(range_begin + 1) < *(range_begin)) {
            SwapVal(range_begin, (range_begin + 1));
        }
    }
    if (size > 2) {
        It range_mid = range_begin + size / 2;
        MergeSort(range_begin, range_mid);
        MergeSort(range_mid, range_end);
        MergeSortedRanges(range_begin, range_mid, range_mid, range_end);
    }
}


template <typename It>
vector<string> GetPermutations(It container_begin, It container_end) {
    sort(container_begin, container_end);
    reverse(container_begin, container_end);
    vector<string> result;
    do {
        result.push_back(PrintRangeToString(container_begin, container_end));
    } while (prev_permutation(container_begin, container_end));
    return result;
}

int main() {
    vector<int> test_vector(11);
    // iota             -> http://ru.cppreference.com/w/cpp/algorithm/iota
    // Заполняет диапазон последовательно возрастающими значениями
    iota(test_vector.begin(), test_vector.end(), 1);

    // shuffle   -> https://ru.cppreference.com/w/cpp/algorithm/random_shuffle
    // Перемешивает элементы в случайном порядке
    random_device rd;
    mt19937 g(rd());
    shuffle(test_vector.begin(), test_vector.end(), g);

    // Выводим вектор до сортировки
    PrintRange(test_vector.begin(), test_vector.end());
    // Сортируем вектор с помощью сортировки слиянием
    MergeSort(test_vector.begin(), test_vector.end());
    // Выводим результат
    PrintRange(test_vector.begin(), test_vector.end());
    return 0;
}
