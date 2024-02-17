#include <iostream>
#include <cassert>
#include <compare>
#include <set>
#include <string>

using namespace std;

class TKlasa {
public:
    TKlasa(const char* c) : str(c) {} // zmień to na definicję z inicjalizacją
    // a
    const char* operator[](const char* s) const {
        size_t found = str.find(s); // szukanie podciągu znaków, found jest pozycją pierwszego dopasowania
        if (found != string::npos) { // jeśli znaleziono
            return str.c_str() + found; // c_str() zwraca wskaźnik do tablicy zawierającej ciąg znaków, przesuwamy to do found
        }
        return nullptr;
    }

    // b
    std::strong_ordering operator<=>(const TKlasa& other) const {
         return str <=> other.str;
    }

private:
    string str;
};

int main(){
    TKlasa k1("Hello world!");
    TKlasa k2("Hello");
    TKlasa k3("Hello world!!!");
    TKlasa k4("Hello world!");

    const char* s1 = k1["world"];
    const char* s2 = k1["witaj"];
    // Sprawdzamy czy "world" znajduje się w klasie
    if (s1 != nullptr) {
        cout << "Znaleziono podciąg znaków w k1: " << s1 << endl;   
    }
    else {
        cout << "Nie znaleziono podciągu znaków w k1" << endl;
    }
    if (s2 != nullptr) {
        cout << "Znaleziono podciąg znaków w k2:" << s2 << endl;
    }    
    else {
        cout << "Nie znaleziono podciągu znaków w k2" << endl;
    }
    
    // b
    // Wyraz mniejszy
    if (k1 < k2){
        cout << "Tekst w k1 jest mniejszy od tekstu w k2" << endl;
    }
    else if (k1 > k2){
        cout << "Tekst w k1 jest większy od tekstu w k2" << endl;
    }
    else {
        cout << "Teksty są równe" << endl;
    }

    // Wyraz większy
    if (k1 < k3){
        cout << "Tekst w k1 jest mniejszy od tekstu w k3" << endl;
    }
    else if (k1 > k3){
        cout << "Tekst w k1 jest większy od tekstu w k3" << endl;
    }
    else {
        cout << "Teksty są równe" << endl;
    }

    // Wyraz równy
    if (k1 < k4){
        cout << "Tekst w k1 jest mniejszy od tekstu w k4" << endl;
    }
    else if (k1 > k4){
        cout << "Tekst w k1 jest większy od tekstu w k4" << endl;
    }
    else {
        cout << "Teksty są równe" << endl;
    }
    
}

