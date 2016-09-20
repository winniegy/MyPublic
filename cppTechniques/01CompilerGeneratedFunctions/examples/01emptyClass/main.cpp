#include <iostream>
#include <utility>
#include <string>

using namespace std;

class E
{
public:
    E()
    {
        cout << this << " default constructor called." << endl;
    }

    E(const E& rhs)
    {
        cout << this << " copy constructor called." << endl;
    }

    ~E()
    {
        cout << this << " default destructor called." << endl;
    }

    E& operator=(const E& rhs)
    {
        cout << this << " operator assignment called." << endl;
        return *this;
    }


    //C++ 11
    E(E&& rhs)
    {
        cout << this << " moving copy constructor called." << endl;
    }

    E& operator=(E&& rhs)
    {
        cout << this << " moving operator assignment called" << endl;
        return *this;
    }

};

E f(E e)
{
    cout << "f function called" << endl;
    return e;
}

int main()
{
    E e1;
    cout << "=========" << endl;
    E e2(e1);
    cout << "=========" << endl;
    E e3 = e1;
    cout << "=========" << endl;
    E e4;
    e4 = e1;

    cout << "=========" << endl;
    E e5(f(E()));
    cout << "=========" << endl;
    e1 = E();
    cout << "=========" << endl;

    return 0;
}
