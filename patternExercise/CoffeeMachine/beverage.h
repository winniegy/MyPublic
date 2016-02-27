#ifndef BEVERAGE_H
#define BEVERAGE_H
#include <iostream>
#include <string>

class beverage
{
public:
    virtual std::string name() = 0;
    virtual int price() = 0;
    virtual ~beverage(){}
};

#endif // BEVERAGE_H
