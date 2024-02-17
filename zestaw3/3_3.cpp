#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n, m, p, i, j, k, s; // Macierz Anxm Bmxp Cnxp
    cout << "Podaj wymiary macierzy n m p ";
    cin >> n >> m >> p;
    // tworzenie matryc
    int a[n][m];
    int b[m][p];
    int c[n][p];
    // podaj wejście dla macierzy A
    cout << "Podaj wejście dla macierzy A" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }    
    }
    // podaj wejście dla macierzy B
    cout << "Podaj wejście dla macierzy B" << endl;
    for (i = 0; i < m; i++){
        for (j = 0; j < p; j++){
            cin >> b[i][j];
        }
    }
    // Mnożymy macierz A x B i wynik zapisujemy w C
    for (i = 0; i < n; i++){
        for (j = 0; j < p; j++){
            s = 0;
            for (k = 0; k < m; k++){
                s += a[i][k] * b[k][j];
            }
            c[i][j] = s;
        }
    }
    // Wyświetl wynik mnożenia macierzy
    cout << "C = A x B: \n";
    for (i = 0; i < n; i++){
        for(j = 0; j < p; j++){
            cout << setw(6) << c[i][j];
        }
        cout << endl;
    }
}