/*
 * events.h
 *
 *  Created on: Oct 16, 2014
 *      Author: winnie
 */

#ifndef EVENTS_H_
#define EVENTS_H_


#include <stdio.h>
#include <stdlib.h>
#include "eventBase.h"

class startEvent : public iEvent
{
public:
   startEvent()
   {
       puts("startEvent constructor.");
   }
   ~startEvent()
   {
       puts("startEvent destructor.");
   }
   iEvent::iEventType getEventType()
   {
      return iEvent::STARTEVENT;
   }
};

class stopEvent : public iEvent
{
public:
   stopEvent()
   {
       puts("stopEvent constructor.");
   }
   ~stopEvent()
   {
       puts("stopEvent destructor.");
   }
   iEvent::iEventType getEventType()
   {
      return iEvent::STOPEVENT;
   }
};

#endif /* EVENTS_H_ */
