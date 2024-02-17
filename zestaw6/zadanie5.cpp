#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

int main()
{
    std::list<char> lista = {'a', 'c', 'b', 'd', 'f', 'e', 'h', 'g'};
    auto lambda = [&](const auto& a, const auto& b) -> bool
    {
        auto indeks_a = find(lista.begin(), lista.end(), a);
        auto indeks_b = find(lista.begin(), lista.end(), b);
        if (indeks_a == lista.end() || indeks_b == lista.end()){
            cout << "brak znaku w liście" << endl;
            return false;
        }
        return (distance(lista.begin(), indeks_a) < distance(lista.begin(), indeks_b));
    };
    set<char, decltype(lambda)> kontener({'a', 'a', 'a', 'g', 'c', 'b', 'f', 'h', 'c', 'e', 'd', 'e'}, lambda);
    for (char c : kontener) cout << c;
    cout << endl;
}

