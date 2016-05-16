#include <iostream>
#include <utility>
#include <string>

using namespace std;

class A
{
public:
    explicit A(const string name) :
        name(name)
    {
        cout << this << " single argument constructor called. Name: " << this->name << endl;
    }

    A(const A& rhs) :
        name(rhs.name)
    {
        cout << this << " copy constructor called. Name: " << this->name << endl;
    }

    ~A()
    {
        cout << this << " default destructor called. Name: " << this->name << endl;
    }

    A& operator=(const A& rhs)
    {
        name = rhs.name;
        cout << this << " operator assignment called. Name: " << this->name << endl;
        return *this;
    }


    /*
    //C++ 11
    A(A&& rhs) :
        name(std::move(rhs.name))
    {
        cout << this << " moving copy constructor called. Name: " << this->name << endl;
    }

    A& operator=(A&& rhs)
    {
        name = std::move(rhs.name);
        cout << this << " moving operator assignment called. Name: " << this->name << endl;
        return *this;
    }
    */


    const string getName()
    {
        return this->name;
    }

private:
    A(){cout << "A default constructor called." << endl;}

    string name;
};

A f(A a)
{
    cout << "f function called" << endl;
    return a;
}

int main()
{

    A a1("a1");
    A a2("a2");
    cout << "=========" << endl;
    A a11(a1);
    cout << "=========" << endl;
    a1 = a11;
    cout << "=========" << endl;
    A a22 = a2;

    /*
    // different?
    cout << "=========" << endl;
    A a3(A("temp A1"));
    cout << "=========" << endl;
    A a4(f(A("temp A1")));
    cout << "=========" << endl;
    a1 = A("temp A2");
    cout << "=========" << endl;
    a2 = f(A("temp A3"));
    cout << "=========" << endl;
    */

    return 0;
}
