#ifndef HANDLER_H
#define HANDLER_H
#include "client.h"
#include <string>
#include <stdlib.h>
#include <iostream>
class handler
{
public:
    handler() : successor(nullptr)
    {}
    handler(handler* hdl) : successor(nullptr)
    {
        this->successor = hdl;
    }
    virtual ~handler() {}
    virtual void handleRequest(client& cli) = 0;
    virtual void setSuccessor(handler* hdl)
    {
        successor = hdl;
    }
protected:
    handler* successor;
};

#endif // HANDLER_H
