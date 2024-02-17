#include <iostream>

using namespace std;

class MozeWykBadania{
    bool mozliwosc;
public:
    MozeWykBadania(bool mozliwosc) : mozliwosc(mozliwosc) {}
    virtual ~MozeWykBadania() {}
    virtual void m_badania()
    {
        if (mozliwosc){
            cout << "Może wykonywać badania" << endl;
        }
        else{
            cout << "Nie może wykonywać badania" << endl;
        }
    }
};

class MozeNauczac{
    bool m_nauczac_;
public:
    MozeNauczac(bool m_nauczac_) : m_nauczac_(m_nauczac_) {}
    virtual ~MozeNauczac() {}
    virtual void m_nauczac(){
        if (m_nauczac_){
            cout << "Może nauczać" << endl;
        }
        else{
            cout << "Nie może nauczać" << endl;
        }
    }
};

class TOsoba{
    string imie;
public:
    TOsoba(const string& imie) : imie(imie) {}
    virtual ~TOsoba() {}
    virtual void jak_imie() {cout << "Ma na imię " << imie << endl;}
};

class MozeBycStudentem{
    bool m_studentem_;
public:
    MozeBycStudentem(bool m_studentem_) : m_studentem_(m_studentem_) {}
    virtual ~MozeBycStudentem() {}
    virtual void m_studentem(){
        if (m_studentem_){
            cout << "Może być studentem" << endl;
        }
        else{
            cout << "Nie może być studentem" << endl;
        }
    }
};

class TStudent : virtual public TOsoba, virtual public MozeBycStudentem{
    string student_kierunek;
public:
    TStudent(const string& imie, const string& student_kierunek) : TOsoba(imie), MozeBycStudentem(true), student_kierunek(student_kierunek) {}
    virtual ~TStudent() override {}
    virtual void czy_student() {
        cout << "Jest studentem na kierunku " << student_kierunek << endl;
    }
};

class TAsystentBadan : virtual public MozeWykBadania, virtual public TOsoba
{
    bool asystent_status;
public:
    TAsystentBadan(const string& imie, bool asystent_status) : MozeWykBadania(false), TOsoba(imie), asystent_status(asystent_status) {}
    virtual ~TAsystentBadan() override {}
    virtual void czy_asystent(){
        if (asystent_status){
            cout << "Jest asystentem" << endl;
        }
        else{
            cout << "Nie jest asystentem" << endl;
        }
    }
};

class TDoktorant : virtual public TStudent
{
    bool doktorant_status;
public:
    TDoktorant(const string& imie, const string& student_kierunek, bool doktorant_status) : TStudent(imie, student_kierunek), TOsoba(imie), MozeBycStudentem(true), doktorant_status(doktorant_status) {}
    virtual ~TDoktorant() override {}
    virtual void czy_doktorant(){
        if (doktorant_status){
            cout << "Jest doktorantem" << endl;
        }
        else{
            cout << "Nie jest doktorantem" << endl;
        }
    }
};

class TDoktorantBadacz : virtual public TAsystentBadan, virtual public TDoktorant
{
    bool doktbadacz_status;
public:
    TDoktorantBadacz(const string& imie, const string& student_kierunek, bool doktorant_status, bool doktbadacz_status) : TAsystentBadan(imie, true), TDoktorant(imie, student_kierunek, doktorant_status), MozeWykBadania(true), TOsoba(imie), TStudent(imie, student_kierunek), MozeBycStudentem(true), doktbadacz_status(doktbadacz_status) {}
    virtual ~TDoktorantBadacz() override {}
    void czy_doktbadacz(){
        if (doktbadacz_status){
            cout << "Jest doktorantem badaczem" << endl;
        }
        else{
            cout << "Nie jest doktorantem badaczem" << endl;
        }
    }
};

class TDoktorantNaucz : virtual public MozeNauczac, virtual public TDoktorant{
    bool naucz_status;
public:
    TDoktorantNaucz(const string& imie, const string& student_kierunek, bool doktorant_status, bool naucz_status) : TDoktorant(imie, student_kierunek, doktorant_status), TOsoba(imie), MozeNauczac(true), MozeBycStudentem(true), TStudent(imie, student_kierunek), naucz_status(naucz_status) {}
    virtual ~TDoktorantNaucz() override{}
    void czy_naucz(){
        if (naucz_status){
            cout << "Jest nauczycielem" << endl;
        }
        else{
            cout << "Nie jest nauczycielem" << endl;
        }
    }
};

int main(){
    TDoktorantBadacz doktorant_badacz("Jan", "Informatyka", true, true);
    doktorant_badacz.jak_imie();
    doktorant_badacz.czy_doktbadacz();
    doktorant_badacz.czy_student();
    doktorant_badacz.m_badania();

    cout << endl;
    TDoktorantNaucz doktorant_naucz("Paweł", "Fizyka", true, true);
    doktorant_naucz.jak_imie();
    doktorant_naucz.czy_doktorant();
    doktorant_naucz.czy_naucz();
    doktorant_naucz.czy_student();
    doktorant_naucz.m_studentem();

    cout << endl;
    TStudent t_student("Michał", "Informatyka Stosowana");
    t_student.jak_imie();
    t_student.czy_student();
    t_student.m_studentem();

    cout << endl;
    TAsystentBadan t_asystent_badan("Piotr", true);
    t_asystent_badan.jak_imie();
    t_asystent_badan.czy_asystent();
    t_asystent_badan.m_badania();

    cout << endl;
    TDoktorant doktorant("Jakub", "Filologia Klasyczna", true);
    doktorant.jak_imie();
    doktorant.czy_doktorant();
    doktorant.czy_student();
    doktorant.m_studentem();
}