#ifndef SINGLETON_H
#define SINGLETON_H


class singleton
{
private:
    singleton();
    singleton(singleton const& copy);
    singleton& operator=(singleton const& rhs);
    ~singleton();

public:
    static singleton& getInstance();

};

#endif // SINGLETON_H
