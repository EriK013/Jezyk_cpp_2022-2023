#include <iostream>
#include <cmath>

using namespace std;

class TComplex {
public:
    TComplex(double re = 0, double im = 0) : re{re}, im{im} {} // zamień na definicję z inicjalizacją
    // a
    TComplex operator() (double re, double im) const {
        return TComplex(re, im);
    }
    // b
    TComplex operator+ (const TComplex& z) const {
        return TComplex(re + z.re, im + z.im);
    }

    TComplex operator- (const TComplex& z) const {
        return TComplex(re - z.re, im - z.im);
    }
    // c
    TComplex conj() const {
        return TComplex(re, -im);
    }

    double abs() const {
        return sqrt(re * re + im * im);
    }

    // d
    TComplex operator* (const TComplex& z){
        return TComplex(re * z.re - im * z.im, re * z.im + im * z.re);
    }

    TComplex operator/ (const TComplex& z) const {
        double x = z.re * z.re + z.im * z.im;
        return TComplex((re * z.re + im * z.im) / x, (im * z.re - re * z.im) / x);
    }

    friend ostream& operator<< (ostream& COUT, const TComplex& x);

private:
    double re{0}, im{0};
};

// e
ostream& operator<< (ostream& COUT, const TComplex& x){
    COUT << '(' << x.re << ',' << x.im << ')';
    return COUT;
}


int main(){
    TComplex z1(4.0, 3.0);
    TComplex z2(2.0, 1.0);
    TComplex suma = z1 + z2;
    TComplex roznica = z1 - z2;
    TComplex iloczyn = z1 * z2;
    TComplex iloraz = z1 / z2;
    TComplex sprzezenie_z1 = z1.conj();
    double abs_z1 = z1.abs(); // moduł

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << "z1 + z2 = " << suma << endl;
    cout << "z1 - z2 = " << roznica << endl;
    cout << "z1 * z2 = " << iloczyn << endl;
    cout << "z1 / z2 = " << iloraz << endl;
    cout << "Sprzężenie z1 = " << sprzezenie_z1 << endl;
    cout << "Moduł z1 = " << abs_z1 << endl;
}
