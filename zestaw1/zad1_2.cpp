#include <iostream>
#include <cstring>
#include <string>

using namespace std;
const unsigned int N = 100;

int main(){
    char s1[N];
    char s2[N];
    cout << "Podaj pierwszy ciąg znaków: ";
    cin.getline(s1, N);
    cout << "Podaj drugi ciąg znaków: ";
    cin.getline(s2, N);
    if (strlen(s1) != strlen(s2)) { //Wstępne sprawdzenie. Jeśli ciągi znaków są różnej długości to nie mogą być sobie równe
        cout << "Ciągi znaków są różne" << endl;
        return 0;
    }
    else{
        for(unsigned int i = 0; i < strlen(s1); i++){ //Iterowanie po wszystkich znakach obu ciągów. Ciągi są różne jeśli dana para znaków będzie różna
            if (tolower(s1[i])!= tolower(s2[i])) {
                cout << "Ciągi znaków są różne" << endl;
                return 0;
            }
        }
    }
    cout << "Ciągi znaków są sobie równe" << endl;
    return 0;
}
