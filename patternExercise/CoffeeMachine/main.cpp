#include <iostream>
#include "beverage.h"
#include "espresso.h"
#include "milk.h"
#include "sugar.h"
using namespace std;

int main(void)
{
    cout << "Hello Coffee Machine!" << endl;

    beverage* a = new espresso();
    beverage* b = new milk(a);
    beverage* c = new sugar(b);
    beverage* d = new milk(c);

    cout << d->name() << endl;
    cout << d->price() << endl;

    delete a;
    delete b;
    delete c;
    delete d;

    return 0;
}
