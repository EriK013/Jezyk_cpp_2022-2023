#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string> 

using namespace std;
int main(){
    // a
    vector<int> vec(100);

    // b
    iota(vec.begin(), vec.end(), 1);

    // c
    random_shuffle(vec.begin(), vec.end());
    cout << "Wektor po wymieszaniu: ";
    for (const auto& num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // d
    sort(vec.begin(), vec.end(), greater<int>());
    cout << "Wektor po sortowaniu: ";
    for (const auto& num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // e
    struct Sortowanie {
        bool operator()(int a, int b) const {
            return a > b;
        }
    };
    sort(vec.begin(), vec.end(), Sortowanie());
    cout << "Wejsciowy wektor posortowany malejaco przy uzyciu obiektu funkcyjnego:" << endl;
    for (int i : vec)
        cout << i << ' ';
    cout << endl;

    // f
    auto sortLambda = [](int a, int b) {
        if (a % 10 == 0 && b % 10 != 0) {
            return true;
        }
        if (a % 10 != 0 && b % 10 == 0) {
            return false;
        }
        return a > b;
    };

    sort(vec.begin(), vec.end(), sortLambda);
    cout << "Wektor po sortowaniu (wyrażenie lambda): ";
    for (const auto& num : vec) {
        cout << num << " ";
    }
    cout << endl;


}