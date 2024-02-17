#include <iostream>

using namespace std;

class Klasa
{
private:
    string str;

public:
    // Konstruktor domyślny
    Klasa(){
        str = "HELLO";
        cout << "KONSTRUKTOR DOMYŚLNY " << endl;
    }
    // Konstruktor z argumentem
    Klasa(string s){
        str = s;
        cout << "KONSTRUKTOR DOMYŚLNY " << endl;
    }
    // Konstruktor kopiujący
    Klasa(const Klasa &t){
        str = t.str;
        cout << "KONSTRUKTOR KOPIUJĄCY" << endl;
    }
    // Konstruktor przenoszący
    Klasa(Klasa &&t) noexcept
    {
        str = t.str;
        cout << "KONSTRUKTOR PRZENOSZĄCY" << endl;
    }

    // Destruktor
    ~Klasa(){
        cout << "DESTRUKTOR!" << endl;
    }

    // Operator kopiujący
    Klasa& operator=(const Klasa& t){
        cout << "OPERATOR PRZYPISANIA KOPIUJĄCY" << endl;
        if (this != &t){
            str = t.str;
        }
        return *this;
    }

    // Operator przenoszący
    Klasa& operator=(Klasa&& t) noexcept {
        cout << "OPERATOR PRZYPISANIA PRZENOSZĄCY" << endl;
        if (this != &t){
            str = move(t.str);
        }
        return *this;
    }

    void print(){
        cout << str << endl;
    }
};


int main(){
    Klasa klasa; // konstruktor domyślny
    Klasa klasa2(klasa); // konstruktor kopiujący
    Klasa klasa3(move(klasa2)); // konstruktor przenoszący
    Klasa klasa4; // przypisanie obiektu
    klasa4 = klasa3; 
    Klasa klasa5;
    klasa5 = move(klasa4);
}