#include "singleton.h"
#include <iostream>

singleton::singleton()
{
    std::cout << "singleton constructor called" << std::endl;
}

singleton::singleton(singleton const& copy){}

singleton& singleton::operator=(singleton const& rhs){}

singleton::~singleton(){}

singleton&
singleton::getInstance()
{
    static singleton instance;
    return instance;
}
