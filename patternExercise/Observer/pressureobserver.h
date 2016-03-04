#ifndef PRESSURE_H
#define PRESSURE_H

#include "observer.h"
#include <iostream>
class pressureObserver : public observer
{
    void notify(int data[3])
    {
        std::cout << "Pressure: " << data[2] << std::endl;
    }
};


#endif // PRESSURE_H
