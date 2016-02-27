#ifndef BEVERAGEDECORATOR_H
#define BEVERAGEDECORATOR_H
#include<beverage.h>

class beverageDecorator : public beverage
{
protected:
    beverage* b;
public:
    beverageDecorator() : b(nullptr) {}
    beverageDecorator(beverage* p_b) : b(p_b) {}
};

#endif // BEVERAGEDECORATOR_H
