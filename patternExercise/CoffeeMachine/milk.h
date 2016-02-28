#ifndef MILK_H
#define MILK_H
#include "condimentDecorator.h"

class milk : public condimentDecorator
{
public:
    milk(){}
    milk(beverage* p_b) : condimentDecorator(p_b) {}
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
