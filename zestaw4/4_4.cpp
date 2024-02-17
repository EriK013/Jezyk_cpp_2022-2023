#include <iostream>

using namespace std;

template <typename T>
class TSmartPtr{
public:
    TSmartPtr(T* ptr) : ptr_(ptr) {}
    ~TSmartPtr() { delete ptr_; }

    T* operator->() const { return ptr_; }
    T& operator*() const { return *ptr_; }

private:
    T* ptr_;
};

class Klasa{
public:
    void say() {cout << "Hello world" << endl; }
};

int main(){
    TSmartPtr<Klasa> prt(new Klasa);
    prt->say();
    (*prt).say();
    return 0;
}