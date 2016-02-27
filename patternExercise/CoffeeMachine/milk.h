#ifndef MILK_H
#define MILK_H
#include "beveragedecorator.h"

class milk : public beverageDecorator
{
public:
    milk(){}
    milk(beverage* p_b) : beverageDecorator(p_b) {}
    std::string name()
    {
        return b->name() + ", milk";
    }
    int price()
    {
        return b->price() + 2;
    }
};

#endif // MILK_H
