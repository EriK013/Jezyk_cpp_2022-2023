#include <iostream>
#include <string>

using namespace std;
const unsigned long long K = 80;
unsigned long long fib(unsigned long long n);

int main()
{
    //Pobieranie od użytkownika metody oblicznia ciągu Fibonacciego 
    string metoda;
    cout << "Podaj metodę wyliczenia ciągu Fibonacciego ('rekurencja' bądź 'iteracja')" << endl;
    cin >> metoda;
    if (metoda == "rekurencja")
    {
        for (unsigned long long i = 1; i <= K; ++i)
        {
            cout << fib(i) << endl;
        }
    }
    else if (metoda == "iteracja")
    {
          unsigned long long a = 1;
          unsigned long long b = 1;
          unsigned long long c;
          for (unsigned long long i = 1; i <= K; ++i)
          {
            cout << a << endl;
            cout << b << endl;
            c = a + b;
            a = b;
            b = c;
            cout << c << endl;
          }
    }
    else {
        cout << "Niepoprawna metoda \n";
        return 1;
    }

}
unsigned long long fib(unsigned long long n){
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}