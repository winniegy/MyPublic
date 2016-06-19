#include <iostream>
#include <string>

using namespace std;

class Base {
public:
    explicit Base(const string str) : bStr(str) {
        cout << "Base class constructor called, bStr: " << bStr << endl;
    }
    /*virtual*/ ~Base() {
        cout << "Base class destructor called, bStr: " << bStr << endl;
    }
private:
    string bStr;
};

class Derived : public Base {
public:
    Derived(const string str1, const string str2) :
        Base(str1),
        dStr(str2){
        cout << "Derived class constructor called, dStr: " << dStr << endl;
    }
    ~Derived() {
        cout << "Derived class destructor called, dStr: " << dStr << endl;
    }
private:
    string dStr;
};

void f1() {
    cout << "=====f1() starts=====" << endl;
    Base b("base1");
    Base* pb = new Base("base2");
    delete pb;
    cout << "=====f1() ends=====" << endl;
}

void f2() {
    cout << "=====f2() starts=====" << endl;
    Derived d("base1", "derived1");
    Derived* pd = new Derived("base2", "derived2");
    delete pd;
    cout << "=====f2() ends=====" << endl;
}

void f3() {
    cout << "=====f3() starts=====" << endl;
    Base* pb = new Derived("base", "derived");
    delete pb;
    cout << "=====f3() ends=====" << endl;
}

int main()
{
    cout << "=====calling f1()=====" << endl;
    f1();
    cout << "=====calling f2()=====" << endl;
    f2();
    cout << "=====calling f3()=====" << endl;
    f3();
    return 0;
}
