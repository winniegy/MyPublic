#include <iostream>
#include "client.h"
#include "father.h"
#include "mother.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    client child;
    child.setRequest("play");

    handler* dad = new father();
    mother mom(dad);
    mom.handleRequest(child);

    delete dad;

    return 0;
}
