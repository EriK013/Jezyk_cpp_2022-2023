#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <random>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

class Obserwator {
public:
    Obserwator(const char* s) : nazwa{s ? s : "nienazwany"} { /* nic nie robi */ }
    virtual ~Obserwator() { } // klasa bazowa
    virtual void update() = 0; // metoda czysto wirtualna
    const char* id() const { return nazwa.c_str(); }
private:
    string nazwa;
};

class Manager {
public:
    void dodaj(unique_ptr<Obserwator> p);
    void usun(Obserwator* p);
    void powiadom();
    void obserwatorzy() const;
private:
    list<unique_ptr<Obserwator>> klient;
};

void Manager::obserwatorzy() const {
    if (klient.empty())
        cout << "Brak obserwatorow\n";
    for (const auto& p : klient)
        cout << "Obserwator " << p->id() << endl;
}

void Manager::powiadom() {
    for (const auto& p : klient)
        p->update();
}

void Manager::dodaj(unique_ptr<Obserwator> p) {
    auto it = find_if(klient.begin(), klient.end(),
                      [&](const unique_ptr<Obserwator>& obj) { return obj.get() == p.get(); });
    if (it == klient.end()) {
        klient.push_back(move(p));
    } else {
        cout << "Obserwator " << (*it)->id() << " jest juz na liscie\n";
    }
}

void Manager::usun(Obserwator* p) {
    klient.remove_if([p](const unique_ptr<Obserwator>& obj) { return obj.get() == p; });
}

class Meteo : public Manager {
public:
    double getT() const { return t; }
    void operator()(size_t n);
private:
    double t {0.};
    double losuj(double a, double b);
    random_device rd;
};

double Meteo::losuj(double a, double b) {
    mt19937 gen(rd());
    uniform_real_distribution<> dis(a, b);
    return dis(gen);
}

void Meteo::operator()(size_t n) {
    while (n--) {
        t = losuj(5, 25);
        powiadom();
    }
}

class Monitor : public Obserwator {
public:
    Monitor(const char* s, const Meteo& r) : Obserwator(s), ref(r) { }
    virtual void update() override final {
        t = ref.getT();
        cout << "Obserwator " << id() << " t = " << t << endl;
    }
private:
    double t {0.};
    const Meteo& ref;
};

class MonitorSredni : public Obserwator {
public:
    MonitorSredni(const char* s, const Meteo& r) : Obserwator(s), ref(r) { }
    void update() override {
        vec.push_back(ref.getT());
        tsr = 0.;
        for (const auto& d : vec)
            tsr += d;
        tsr /= vec.size();
        cout << "Obserwator " << id() << " t srednia = " << tsr << endl;
    }
private:
    double tsr {0.};
    vector<double> vec;
    const Meteo& ref;
};

auto main() -> int {
    Meteo stacja;
    unique_ptr<Obserwator> p1(new Monitor("Monitor 1",stacja));
    unique_ptr<Obserwator> p2(new Monitor("Monitor 2",stacja));
    unique_ptr<Obserwator> p3(new MonitorSredni("Monitor Sredni 1",stacja));
    unique_ptr<Obserwator> p4(new MonitorSredni("Monitor Sredni 2",stacja));
    stacja.obserwatorzy(); // pusta lista
	stacja.dodaj(move(p1));
    stacja.dodaj(move(p2));
    stacja.dodaj(move(p3));
    stacja.dodaj(move(p4));
    stacja.obserwatorzy(); // lista nazw wszystkich podlaczonych obserwatorow
    stacja(2); // dwa losowania, stacja.operator()(2);
    p1 = make_unique<Monitor>("Monitor 1", stacja);
    stacja.dodaj(move(p1)); // sprawdzenie, czy p1 jest juz na liscie
    stacja.usun(p3.get()); // od teraz p3 nie jest obserwatorem
    stacja(10000);
}