#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class client
{
public:
    client() {}
    void setRequest(const std::string req)
    {
        this->request = req;
    }

    std::string getRequest()
    {
        return this->request;
    }

    std::string request;
};
#endif // CLIENT_H
