//
//  EatStew.h
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#ifndef __Learn36__EatStew__
#define __Learn36__EatStew__

#include "../FSM/State.h"
#include "Miner.h"

class EatStew : public State<Miner>
{
public:
    static EatStew* getInstance();
    virtual void onEnter(Miner* pMiner);
    virtual void onExit(Miner* pMiner);
    virtual void execute(Miner* pMiner);
    virtual bool onMessage(Miner* pMiner, const Telegram& msg) { return true; }
    
private:
    EatStew() {}
};

#endif /* defined(__Learn36__EatStew__) */
