//
//  EnterMineAndDigForNugget.h
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#ifndef __test226__EnterMineAndDigForNugget__
#define __test226__EnterMineAndDigForNugget__

#include "../FSM/State.h"
#include "Miner.h"

class EnterMineAndDigForNugget : public State<Miner>
{
public:
    static EnterMineAndDigForNugget* getInstance();
    virtual void onEnter(Miner* pMiner);
    virtual void onExit(Miner* pMiner);
    virtual void execute(Miner* pMiner);
    
    virtual bool onMessage(Miner* pMiner, const Telegram& msg) { return true; }
    
private:
    EnterMineAndDigForNugget() {}
};

#endif /* defined(__test226__EnterMineAndDigForNugget__) */
