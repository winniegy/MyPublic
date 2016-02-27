#include <iostream>
#include "singleton.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    singleton& mySingleton = singleton::getInstance();
    singleton& mySingleton2 = singleton::getInstance();
    return 0;
}
