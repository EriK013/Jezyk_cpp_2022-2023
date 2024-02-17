#include <iostream>
#include <functional>

using namespace std;

int main() {
    // Definiowanie wyrażenia lambda
    auto fibo = [](int n) {
        function<int(int, const function<int(int)>&)> inner_fibo =
                [](int n, const function<int(int)>& impl) -> int {
                    if (n <= 1)  
                        return n;
                    else
                        return impl(n - 1) + impl(n - 2);
                };

        function<int(int)> Y = [&](int n) {
            return inner_fibo(n, Y); 
        };

        return Y(n);  
    };
    for (int i = 0; i < 15; i++) {
        cout << fibo(i) << ' ';
    }
    cout << endl;
}