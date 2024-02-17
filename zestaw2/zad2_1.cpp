#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
const int MAX = 21; // maksymalna długość linii

//  Czytanie pliku słowo po słowie i zapisywanie ich w wektorze
void czytaj(const string& nazwa_pliku, vector<string>& slowa){
    ifstream plik(nazwa_pliku);
    string slowo;
    while (plik >> slowo) {
    slowa.push_back(slowo);
    }
    plik.close();
}

void wydrukuj (vector<string> tmp){
    for(int i = 0; i < tmp.size(); i++){
        cout << tmp[i];
    }
    cout << endl;
}

void rozszerz(vector<string> tmp, int liczba_slow){
    //  Sprawdzamy jaka jest różnica międzi długością naszych słów a docelową długością linni
    int l_znakow = 0;
    int roznica;
    for (int i = 0; i < liczba_slow; i++){
        l_znakow += tmp[i].size();
    }
    roznica = MAX - l_znakow;
    while (roznica > 0){ // Dopóki w naszej linijce mamy mniej niż MAX znaków to dodajemy do kożdego z wyrazów poza ostatnim spacje
        for (int i = 0; i < liczba_slow - 1; i++){
            tmp[i] += ' ';
            roznica -= 1;
            if (roznica <= 0){ 
                break;
            }
        }    
    }
    wydrukuj(tmp);
}


void wyjustuj(vector<string>& slowa){
    // bierz po kolei słowa i sprawdzaj ich długość czy jest równa MAX
    int il_znakow_w_linni = 0;
    vector<string> tmp;
    int i = 0;
    while (i < slowa.size()){ //   Iterujemy po wszystkich słowach tekstu
        il_znakow_w_linni += slowa[i].size();
        if (il_znakow_w_linni <= MAX){ // Dopóki nasze słowa mieszczą się w linni 
            tmp.push_back(slowa[i]); 
            if (il_znakow_w_linni + slowa[i + 1].size() < MAX){ //  Jesli następne słowo będzie nadal mieściło się w linni to do liczby znaków doliczamy spacje
                il_znakow_w_linni += 1;
            }
            i++;
        }
        else {
            il_znakow_w_linni = 0;
            rozszerz(tmp, tmp.size());
            tmp.clear();
        }
    }
    rozszerz(tmp, tmp.size());
}


int main(){
    //Czytanie tekstu z pliku słowo po słowie
    vector<string> slowa;
    czytaj("tekst.txt", slowa);
    wyjustuj(slowa);
}