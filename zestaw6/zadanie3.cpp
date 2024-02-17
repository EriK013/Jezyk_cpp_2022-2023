#include <iostream>
#include <map>
#include <vector>
#include <iterator>

int main() {
    // Tworzenie obiektu map 'mis'
    std::map<int, std::string> mis = {{0, "zero"}, {1, "jeden"}, {2, "dwa"}, {3, "trzy"}, {4, "cztery"},
                                      {5, "piec"}, {6, "szesc"}, {7, "siedem"}, {8, "osiem"}, {9, "dziewiec"}};

    // Tworzenie wektora liczb całkowitych
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::transform(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, "\n"),
                   [&](int i) {
                       return mis[i];
                   });

    return 0;
}