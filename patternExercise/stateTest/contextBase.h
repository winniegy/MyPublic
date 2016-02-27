/*
 * contextBase.h
 *
 *  Created on: Oct 10, 2014
 *      Author: winnie
 */

#ifndef CONTEXTBASE_H_
#define CONTEXTBASE_H_

#include <vector>
#include "stateBase.h"
#include "eventBase.h"

class iEvent;
class iState;

class iContext
{
public:
   iContext();
   virtual ~iContext();

   void setState(iState* state);

   void handleEvent(iEvent* event);

private:
   std::vector<iState*> states;
   iState* mState;
};


#endif /*CONTEXTBASE_H_ */
