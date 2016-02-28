#ifndef BEVERAGEDECORATOR_H
#define BEVERAGEDECORATOR_H
#include<beverage.h>

class condimentDecorator : public beverage
{
protected:
    beverage* b;
public:
    condimentDecorator() : b(nullptr) {}
    condimentDecorator(beverage* p_b) : b(p_b) {}
};

#endif // BEVERAGEDECORATOR_H
