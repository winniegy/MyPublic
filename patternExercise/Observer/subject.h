#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
#include <list>

class subject
{
public:
    virtual ~subject()
    {
        observerCollection.clear();
    }

    virtual void registerObserver(observer* obs) = 0;
    virtual void unregisterobserver(observer* obs) = 0;
    virtual void notifyObservers() = 0;

    std::list<observer*> observerCollection;
};

#endif // SUBJECT_H
