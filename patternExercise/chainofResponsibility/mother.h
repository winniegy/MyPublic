#ifndef MOTHER_H
#define MOTHER_H

#include "handler.h"

class mother : public handler
{
public:
    mother() : handler(nullptr) {}
    mother(handler* hdl) : handler(hdl) {}
    void handleRequest(client& cli)
    {
        std::cout << "Mother handling..." << std::endl;
        if (cli.getRequest().compare("eat") == 0)
        {
            std::cout << "Mother plays with the child. Happy" << std::endl;
        }
        else if (successor != nullptr)
        {
            std::cout << "Not eat, handover to the successor" << std::endl;
            successor->handleRequest(cli);
        }
        else
        {
            std::cout << "Not eat, no successor. The child is crying..." << std::endl;
        }
    }
};

#endif // MOTHER_H
