#ifndef SUGAR_H
#define SUGAR_H

#include "beveragedecorator.h"

class sugar : public beverageDecorator
{
public:
    sugar(){}
    sugar(beverage* p_b) : beverageDecorator(p_b) {}
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
