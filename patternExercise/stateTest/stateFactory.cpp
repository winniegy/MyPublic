/*
 * stateFactory.cpp
 *
 *  Created on: Oct 21, 2014
 *      Author: egogyii
 */

#include <iostream>
#include <string>

#include "stateFactory.h"
#include "states.h"

using namespace std;

stateFactory* stateFactory::mFactory = 0;

stateFactory::stateFactory() : states() {};

stateFactory::~stateFactory()
{
   std::vector<iState*>::iterator it;
   for(it = states.begin() ; it != states.end() ;)
   {
      delete *(it++);
   }
};

stateFactory* stateFactory::getInstance()
{
   // does not guarantee singleton for multi-threads
   if (!mFactory)
      mFactory = new stateFactory();
   return mFactory;
}

iState* stateFactory::getState(StatesName::stateType type, iContext* context)
{
   std::vector<iState*>::iterator it;
   for(it = states.begin() ; it != states.end(); it++)
   {
      if((*it)->getStateType() == type)
      {
         cout << StatesName::getC_str(type) << " has been initialized before." << endl;
         return *it;
      }
   }

   iState* newState;

   switch(type) {
   case StatesName::INITIALSTATE:
      newState = new initialState(context, this);
      states.push_back(newState);
      break;
   case StatesName::DUMMYSTATE:
      newState =  new dummyState(context, this);
      states.push_back(newState);
      break;
   case StatesName::FINALSTATE:
      newState =  new finalState(context, this);
      states.push_back(newState);
      break;
   }
   return newState;
};


