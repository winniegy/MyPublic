#ifndef SUGAR_H
#define SUGAR_H

#include "CondimentDecorator.h"

class sugar : public condimentDecorator
{
public:
    sugar(){}
    sugar(beverage* p_b) : condimentDecorator(p_b) {}
    std::string name()
    {
        return b->name() + ", sugar";
    }
    int price()
    {
        return b->price() + 3;
    }
};


#endif // SUGAR_H
