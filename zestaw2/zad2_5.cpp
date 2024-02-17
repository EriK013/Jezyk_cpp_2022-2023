#include <iostream>
#include <string>
using namespace std;

struct RZYM {
    int arab;
    string rzym;
} rz[]={{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},
{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},
{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};

int arabska_na_rzymska(int arab, int max) {
    if (arab == 0){
        return 0;
    }
    // Dopóki liczba kryjąca się pod indeksem max mieści się w arabskiej
    while (arab >= rz[max].arab) {
        cout << rz[max].rzym;
        arab -= rz[max].arab;
    }
    // Wywołujemy rekurencyjnie funkcję z max -= 1
    return arabska_na_rzymska(arab, max-1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: ./zad2_5 {liczba arabska}" << endl;
        exit(1);
    }    
    int liczba_arabska = stoi(argv[1]); //  konwersja parametru wejściowego na liczbę 
    if (!(liczba_arabska > 0 && liczba_arabska <= 3999)){ // sprawdzenie inputu
        cout << "Niepoprawna liczba" << endl;
        return 1;
    }
    else {
        int max = 12; // maksymalny indeks tablicy rz[]
        arabska_na_rzymska(liczba_arabska, max);
    }
    cout << endl;
    return 0;
}