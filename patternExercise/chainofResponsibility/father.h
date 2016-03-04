#ifndef FATHER_H
#define FATHER_H

#include "handler.h"

class father : public handler
{
public:
    father() : handler(nullptr) {}
    father(handler* hdl) : handler(hdl) {}
    void handleRequest(client& cli)
    {
        std::cout << "Father handling..." << std::endl;
        if (cli.getRequest().compare("play") == 0)
        {
            std::cout << "Father plays with the child. Happy" << std::endl;
        }
        else if (successor != nullptr)
        {
            std::cout << "Not play, handover to the successor" << std::endl;
            successor->handleRequest(cli);
        }
        else
        {
            std::cout << "Not play, no successor. The child is crying..." << std::endl;
        }
    }
};

#endif // FATHER_H
