/*
 * contextBase.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: winnie
 */

#include "contextBase.h"
#include "states.h"
#include "stateBase.h"

iContext::iContext() : mState(0) {};

iContext::~iContext() {};


void iContext::setState(iState* state)
{
   if(mState == state)
   {
      puts("set same state, self transit.");
      return;
   }

   if(mState)
      mState->doExitAction();

   mState = state;

   if(mState)
      mState->doEntryAction();
};



void iContext::handleEvent(iEvent* event)
{
   mState->handleEvent(event);
};







