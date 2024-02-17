#include <iostream>
#include <string>
#include <string_view>
#include <format>
using namespace std;

class Kwadrat {
    public:
        int z;
        int w;
    void rysuj() {
        for (int i = 1; i <= z + 2; i++){
            //wnętrze
            if (i > 2 && i <= z) {
                //lewy bok
                for (int l_bok = 1; l_bok <= (z - w)/2; l_bok++){
                    cout << format("{}", "*");
                }
                //pusty środek
                for (int srodek = 1; srodek <= w; srodek++){
                    cout << format("{}", " ");
                }
                //prawy bok
                for (int p_bok = 1; p_bok <= (z - w)/2; p_bok++){
                    cout << format("{}", "*");
                }
                cout << "\n";
            }
            else {  //stopki górna i dolna
                for (int stopka = 0; stopka < z; stopka ++){
                    cout << format("{}", "*");
                }
                cout << "\n";
            }
        }
        
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