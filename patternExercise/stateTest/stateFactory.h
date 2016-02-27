/*
 * stateFactory.h
 *
 *  Created on: Oct 21, 2014
 *      Author: egogyii
 */

#ifndef STATEFACTORY_H_
#define STATEFACTORY_H_

#include "stateBase.h"
#include "contextBase.h"

class iState;
class iContext;

class stateFactory
{
public:

   struct StatesName
   {
      enum stateType
      {
         INITIALSTATE,
         DUMMYSTATE,
         FINALSTATE
      };

      static
      const char* getC_str(stateType type)
      {
         switch(type)
         {
         case INITIALSTATE:
            return "InitialState";
         case DUMMYSTATE:
            return "DummyState";
         case FINALSTATE:
            return "FinalState";
         default:
            return "UnknownState";
         }
      }
   };

   ~stateFactory();

   iState* getState(StatesName::stateType type, iContext* context);

   static stateFactory* getInstance();

private:
   stateFactory();

   std::vector<iState*> states;
   static stateFactory* mFactory;
};


#endif /* STATEFACTORY_H_ */
