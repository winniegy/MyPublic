/*
 * stateBase.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: winnie
 */

#include "stateBase.h"


iState::iState(iContext* context, stateFactory* factory) : mContext(0), mStateFactory(0)
{
   puts("iState constructor.");
   mContext = context;
   mStateFactory = factory;
};

iState::~iState()
{
   puts("iState destructor.");
};

void iState::doEntryAction()
{
   puts("iState::doEntryAction()");
};

void iState::doExitAction()
{
   puts("iState::doExitAction()");
};
