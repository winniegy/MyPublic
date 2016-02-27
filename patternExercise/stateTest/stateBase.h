/*
 * stateBase.h
 *
 *  Created on: Oct 10, 2014
 *      Author: winnie
 */

#ifndef STATEBASE_H_
#define STATEBASE_H_

#include <stdio.h>
#include <stdlib.h>
#include "contextBase.h"
#include "eventBase.h"
#include "stateFactory.h"

class iContext;
class iEvent;
class stateFactory;


class iState {
   friend class stateFactory;
   friend class iContext;
public:
   virtual ~iState();

   virtual void handleEvent(iEvent* event) = 0;

   virtual unsigned int getStateType() = 0;

protected:
   iState(iContext* context, stateFactory* factory);

   virtual void doEntryAction();
   virtual void doExitAction();

   inline iContext* getContext() {return mContext;}
   inline stateFactory* getFactory() {return mStateFactory;}

private:
   iContext* mContext;
   stateFactory* mStateFactory;
};


#endif /* STATEBASE_H_ */
