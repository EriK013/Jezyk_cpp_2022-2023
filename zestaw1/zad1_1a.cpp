#include <iostream>
#include <iomanip>
using namespace std;

class Kwadrat {
    public:
        int z;
        int w;
    void rysuj() {
        cout << setw(z) << setfill('*') << '*' << endl; //górna stopka kwadratu x2
        cout << setw(z) << setfill('*') << '*' << endl;
        for (int i = 0; i < z - 2; i++) { //wnętrze
            cout << setw((z - w)/2) << setfill('*') << '*' << setw(w) << setfill (' ') << ' ' << setw((z-w)/2) << setfill('*') << '*' << endl; 
        }
        cout << setw(z) << setfill('*') << '*' << endl; //dolna stopka kwadratu x2
        cout << setw(z) << setfill('*') << '*' << endl; 
        
    }
};

int main() {
    int z, w;
    cout << "Podaj wymiary zewnętrzne kwadratu: ";
    cin >> z;
    cout << "Podaj wymiary wewnętrzne kwadratu: ";
    cin >> w;
    if (z <= 0 || w <= 0 || z <= w){
        cout << "Nieprawidłowe wymiary" << endl;
        return 1;
    }
    Kwadrat obj;
    obj.z = z;
    obj.w = w;
    obj.rysuj();
    return 0;
}