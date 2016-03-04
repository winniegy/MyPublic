#ifndef OBSERVER_H
#define OBSERVER_H
#include <stdlib.h>

class observer
{
public:
    virtual void notify(int[]) = 0;
    virtual ~observer(){}
};

#endif // OBSERVER_H
