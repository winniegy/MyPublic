//============================================================================
// Name        : stateTest.cpp
// Author      : yi gong
// Version     :
// Copyright   : You know you can copy it
// Description : Hello World in C, Ansi-style
//============================================================================

#include "stateTest.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "states.h"
#include "contextBase.h"
#include "stateBase.h"
#include "states.h"
#include "stateFactory.h"
#include "myContext.h"
#include <iostream>

int main(void) {

   puts("Dummy state transfer. States could only go Init -> Dummy -> Final");

   iContext* mContext = new myContext();
   stateFactory* sFactory = stateFactory::getInstance();

   iState* initState = sFactory->getState(stateFactory::StatesName::INITIALSTATE, mContext);
   iState* sameState = sFactory->getState(stateFactory::StatesName::INITIALSTATE, mContext);

   //The 2 pointers should point to the same state
   assert(initState == sameState);

   mContext->setState(initState);

   iEvent* firstEvent = new startEvent();
   iEvent* secondEvent = new stopEvent();
   //no transit
   mContext->handleEvent(secondEvent);
   //transit from init to dummy
   mContext->handleEvent(firstEvent);
   //no transit
   mContext->handleEvent(firstEvent);
   //transit from dummy to final
   mContext->handleEvent(secondEvent);
   //no transit
   mContext->handleEvent(secondEvent);

   delete secondEvent;
   delete firstEvent;
   delete sFactory;
   delete mContext;

   return EXIT_SUCCESS;
}
