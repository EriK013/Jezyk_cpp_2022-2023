#include <iostream>
#include <string>

using namespace std;
const unsigned long long K = 80;
unsigned long long memory[K];
unsigned long long fib(unsigned long long n);

int main(){
    memory[0] = 1;
    memory[1] = 1;
    string metoda;
    cout << "Podaj metodę wyliczenia ciągu Fibonacciego ('rekurencja' bądź 'iteracja')" << endl;
    cin >> metoda;
    if (metoda == "rekurencja")
    {
        cout << memory[0] << endl << memory[1] << endl;
        for (unsigned long long i = 2; i < K; ++i)
        {
            memory[i] = fib(i);
            cout << memory[i] << endl;
        }
    }
    else if (metoda == "iteracja")
    {
          for (unsigned long long i = 2; i <= K; ++i)
          {
            if (i == 2){
                cout << memory[0] << endl;
                cout << memory[1] << endl;
            }
            memory[i] = memory[i - 1] + memory[i - 2];
            cout << memory[i] << endl;
          }
    }
    else {
        cout << "Niepoprawna metoda \n";
        return 1;
    }
}

unsigned long long fib(unsigned long long n){
    if (memory[n] != 0){
        return memory[n];
    }
    else
        return fib(n - 1) + fib(n - 2);
}



