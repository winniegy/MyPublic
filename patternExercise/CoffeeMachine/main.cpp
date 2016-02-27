#include <iostream>
#include "beverage.h"
#include "espresso.h"
#include "milk.h"
#include "sugar.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello Coffee Machine!" << endl;

    beverage* a = new espresso();
    beverage* b = new milk(a);
    beverage* c = new sugar(b);
    beverage* d = new milk(c);

    cout << d->name() << endl;
    cout << d->price() << endl;

    delete a, b, c, d;

    return 0;
}
