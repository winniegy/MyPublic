#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H

#include "subject.h"
#include <stdlib.h>

class weatherStation : public subject
{
protected:
    int data[3];
public:
    weatherStation() {}
    void registerObserver(observer* obs)
    {
        observerCollection.push_back(obs);
    }

    void unregisterobserver(observer* obs){}
    void notifyObservers()
    {
        for (std::list<observer*>::iterator iter = observerCollection.begin();
             iter != observerCollection.end(); ++iter)
        {
            (*iter)->notify(data);
        }
    }

    void setData(int inData[3])
    {
        data[0] = inData[0];
        data[1] = inData[1];
        data[2] = inData[2];
    }

};

#endif // WEATHERSTATION_H
