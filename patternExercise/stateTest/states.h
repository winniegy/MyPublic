/*
 * state.h
 *
 *  Created on: Oct 10, 2014
 *      Author: winnie
 */

#ifndef STATES_H_
#define STATES_H_

#include <stdio.h>
#include <stdlib.h>
#include "contextBase.h"
#include "stateBase.h"
#include "events.h"
#include "stateFactory.h"

class iContext;

class initialState : public iState
{
   friend class stateFactory;
private:
   initialState(iContext* context, stateFactory* factory) :
      iState(context, factory)
{
      puts("initialState constructor.");
}

public:
   /* virtual */
   ~initialState()
   {
      puts("initialState destructor.");
   }

   /* virtual */
   unsigned int getStateType()
   {
      return stateFactory::StatesName::INITIALSTATE;
   }

   /* virtual */
   void handleEvent(iEvent* event)
   {
      puts("initialState::handleEvent");
      if(event->getEventType() == iEvent::STARTEVENT)
      {
         puts("initialState to dummyState");
         getContext()->setState(getFactory()->getState(stateFactory::StatesName::DUMMYSTATE, getContext()));
      }
      else
      {
         puts("initialState no transit");
      }
   }

protected:
   void doEntryAction()
   {
      puts("initialState::doEntryAction()");
   }

   void doExitAction()
   {
      puts("initialState::doExitAction()");
   }
};


class dummyState : public iState
{
   friend class stateFactory;
private:
   dummyState(iContext* context, stateFactory* factory) :
      iState(context, factory)
   {
      puts("dummyState constructor.");
   }

public:
   /* virtual */
   ~dummyState()
   {
      puts("dummyState destructor.");
   }

   /* virtual */
   unsigned int getStateType()
   {
      return stateFactory::StatesName::DUMMYSTATE;
   }

   /* virtual */
   void handleEvent(iEvent* event)
   {
      puts("dummyState::handleEvent");
      if(event->getEventType() == iEvent::STOPEVENT)
      {
         puts("dummyState to finalState");
         getContext()->setState(getFactory()->getState(stateFactory::StatesName::FINALSTATE, getContext()));
      }
      else
      {
         puts("dummyState no transit");
      }
   }

protected:
   void doEntryAction()
   {
      puts("dummyState::doEntryAction()");
   }

   void doExitAction()
   {
      puts("dummyState::doExitAction()");
   }
};



class finalState : public iState
{
   friend class stateFactory;
private:
   finalState(iContext* context, stateFactory* factory) :
      iState(context, factory)
   {
      puts("finalState constructor.");
   }

public:
   /* virtual */
   ~finalState()
   {
      puts("finalState destructor.");
   }

   /* virtual */
   unsigned int getStateType()
   {
      return stateFactory::StatesName::FINALSTATE;
   }

   /* virtual */
   void handleEvent(iEvent* event)
   {
      puts("finalState::handleEvent, not possible to transit to other states");
   }

protected:
   void doEntryAction()
   {
      puts("finalState::doEntryAction()");
   }

   void doExitAction()
   {
      puts("finalState::doExitAction()");
   }
};
#endif /* STATES_H_ */
