#ifndef ESPRESSO_H
#define ESPRESSO_H
#include "beverage.h"

class espresso : public beverage
{

public:
    espresso() {}
    ~espresso() {}
    std::string name()
    {
        return "espresso";
    }
    int price()
    {
        return 10;
    }

};

#endif // ESPRESSO_H
