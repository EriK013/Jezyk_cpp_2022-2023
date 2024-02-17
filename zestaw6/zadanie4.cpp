#include <iostream>
#include <vector>
#include <numeric>
#include <string>

int main() {
    // a
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    // b
    auto concat = [](std::string a, int b) {
        return a + "-" + std::to_string(b);  // Zwracanie sklejonego stringa
    };

    // c
    auto s = std::accumulate(std::next(vec.begin()), vec.end(), std::to_string(vec[0]), concat);

    std::cout << s << std::endl;

    return 0;
}