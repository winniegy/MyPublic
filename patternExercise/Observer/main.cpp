#include <iostream>
#include "weatherstation.h"
#include "windobserver.h"
#include "temperatureobserver.h"
#include "pressureobserver.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    windObserver wo;
    temperatureObserver to;
    pressureObserver po;
    weatherStation ws;

    int initialData[3] = {0,1,2};
    ws.setData(initialData);
    ws.registerObserver(&to);
    ws.registerObserver(&po);
    ws.registerObserver(&wo);


    ws.notifyObservers();
    return 0;
}
