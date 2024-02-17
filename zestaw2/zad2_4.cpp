#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
int main(){
    //  Przekazanie ścieżki do katalogu
    string sciezka;
    cout << "Podaj ścieżkę do katalogu" << endl;
    cin >> sciezka;
    //  Sprawdzenie czy podana scieżka odnosi się do istniejącego katalogu
    if(!fs::exists(sciezka) || !fs::is_directory(sciezka)){
        cerr << sciezka << " jest nieprawidłową ścieżką do katalogu" << endl;
    }
    else {
        //  iteracja po wszystkich plikach katalogu
        fs::directory_iterator iter(sciezka);
        for (const auto& entry : iter){
            cout << "Nazwa pliku: " << fs::path(entry).filename() << " Rozmiar (B): " << fs::file_size(entry) << endl;
        }
    }
}