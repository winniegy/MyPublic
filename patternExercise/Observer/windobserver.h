#ifndef WINDOBSERVER_H
#define WINDOBSERVER_H

#include "observer.h"
#include <iostream>
class windObserver : public observer
{
    void notify(int data[3])
    {
        std::cout << "Wind: " << data[0] << std::endl;
    }
};

#endif // WINDOBSERVER_H
