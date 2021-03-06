//
//  State.h
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#ifndef __test226__State__
#define __test226__State__

#include "../Message/Message.h"
#include "../Managers/MessageDispatcher.h"

template<class entity_type>
class State
{
public:
    State()
    {
        
    }
    virtual ~State()
    {
        
    }
    
    virtual void onEnter(entity_type*) = 0;
    virtual void onExit(entity_type*) = 0;
    virtual void execute(entity_type*) = 0;
    virtual bool onMessage(entity_type*, const Telegram&) = 0;
    
};

#endif /* defined(__test226__State__) */
