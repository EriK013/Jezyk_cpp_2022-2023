#include <iostream>
#include <vector>
#include <random>

using namespace std;
const int N = 10000;

void wypelnij_liczbami(vector<int> &v) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, N);
    for (int i = 0; i < v.size(); i++){
        v[i] = (distrib(gen));
    }
}
void wypisz(vector<int> &v){
    for (auto i = begin(v); i != end(v); ++i) { cout << *i << endl; }
}

void quicksort(vector<int> &v, int l, int r){
    int pivot = v[(l + r) / 2];
    int i = l - 1;
    int j = r + 1;
    while(true){
        while(pivot>v[++i]);
        while(pivot<v[--j]);
        if( i <= j)
			swap(v[i],v[j]);
		else
			break;
    }
    if(j > l)
	quicksort(v, l, j);
	if(i < r)
	quicksort(v, i, r);
}

int main(){
    string czy_nieposortowane;
    vector<int> liczby(N);
    //  Wypełnianie wektora losowymi liczbami
    wypelnij_liczbami(liczby);
    cout << "Wpisz 'nieposortowane', aby wyświetlić nieposortowane liczby :" << endl;
    cin >> czy_nieposortowane; // Zapytanie użytkownika czy program powinien wyświetlić nieposortowane czy posortowane liczby
    if (czy_nieposortowane == "nieposortowane") { // Wypisanie liczb nieposortowanych
        wypisz(liczby);
    }
    else { // Posortowanie liczb quicksortem a następnie ich wyświetlenie
    quicksort(liczby, 0, liczby.size() - 1);
    wypisz(liczby);
    }
}