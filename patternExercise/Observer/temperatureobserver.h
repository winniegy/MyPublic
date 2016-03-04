#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "observer.h"
#include <iostream>
class temperatureObserver : public observer
{
    void notify(int data[3])
    {
        std::cout << "Temperature: " << data[1] << std::endl;
    }
};

#endif // TEMPERATURE_H
