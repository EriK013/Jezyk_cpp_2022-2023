#include <iostream>
#include <initializer_list>

using namespace std;
template <class T>
auto fun(const initializer_list<T>& arg){
    T suma = 0; //Suma jest tego samego typu co arg
    for (auto i = arg.begin(); i != arg.end(); ++i){
        suma += *i;
    }
    return suma;
}

int main() {
    auto arg = {1, 2, 3};
    auto arg2 = {2.3, 5.2, 1.2};
    cout << "Dla int: " << fun(arg) << endl;
    cout << "Dla zmiennoprzecinkowych: " << fun(arg2) << endl;
}