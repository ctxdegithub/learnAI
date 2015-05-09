//
//  HitFly.h
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#ifndef __Learn36__HitFly__
#define __Learn36__HitFly__

#include "../FSM/State.h"
#include "Miner.h"

class HitFly : public State<Miner>
{
public:
    static HitFly* getInstance();
    virtual void onEnter(Miner* pMiner);
    virtual void onExit(Miner* pMiner);
    virtual void execute(Miner* pMiner);
    virtual bool onMessage(Miner* pMiner, const Telegram& msg) { return true; }
    
private:
    HitFly() {}
};

#endif /* defined(__Learn36__HitFly__) */
