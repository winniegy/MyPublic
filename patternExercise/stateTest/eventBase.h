/*
 * eventBase.h
 *
 *  Created on: Oct 16, 2014
 *      Author: winnie
 */

#ifndef EVENTBASE_H_
#define EVENTBASE_H_

#include <stdio.h>
#include <stdlib.h>

class iEvent {
public:
   enum iEventType
   {
      STARTEVENT,
      STOPEVENT
   };

   iEvent()
   {
      puts("iEvent constructor.");

   }

   virtual ~iEvent() {puts("iEvent destructor.");}

   virtual iEventType getEventType() = 0;

};


#endif /* EVENTBASE_H_ */
