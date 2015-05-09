//
//  GoHomeAndSleepTilRested.h
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#ifndef __test226__GoHomeAndSleepTilRested__
#define __test226__GoHomeAndSleepTilRested__

#include "../FSM/State.h"
#include "Miner.h"

class GoHomeAndSleepTilRested : public State<Miner>
{
public:
    static GoHomeAndSleepTilRested* getInstance();
    virtual void onEnter(Miner* pMiner);
    virtual void onExit(Miner* pMiner);
    virtual void execute(Miner* pMiner);
    virtual bool onMessage(Miner* pMiner, const Telegram& msg);
    
private:
    GoHomeAndSleepTilRested() {}
    
private:
    bool m_bWaitingStew;
    bool m_bSendToEat;
};


#endif /* defined(__test226__GoHomeAndSleepTilRested__) */
