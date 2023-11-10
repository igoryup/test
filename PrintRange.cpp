#include <iostream>
#include <string>
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

using namespace std;

template <typename IteratorType>
void PrintRange(IteratorType it1, IteratorType it2){
    bool first = true;
    for (auto it = it1; it != it2; ++it){
        if (!first){
            std::cout << ' ';
        }
        first = false;
        std::cout << *it;
    }
    std::cout << std::endl;
}

template <typename Container, typename ContainerElement>
void FindAndPrint(const Container& container, const ContainerElement& element){
    auto new_end_it = find(container.begin(), container.end(), element);
    PrintRange(container.begin(), new_end_it);
    PrintRange(new_end_it, container.end());
}

template <typename IteratorType>
auto MakeVector(IteratorType it1, IteratorType it2){
    return std::vector(it1, it2);
}

int main() {
    set<string> unique_langs = {"Python"s, "Java"s, "C#"s, "Ruby"s, "C++"s};
    vector<string> langs = MakeVector(unique_langs.begin(), unique_langs.end());
    PrintRange(langs.begin(), langs.end()); 
}