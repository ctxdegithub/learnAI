//
//  GoHomeAndSleepTilRested.h
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#ifndef __test226__GoHomeAndSleepTilRested__
#define __test226__GoHomeAndSleepTilRested__

#include "State.h"
#include "Miner.h"

class GoHomeAndSleepTilRested : public State<Miner>
{
public:
    static GoHomeAndSleepTilRested* getInstance();
    virtual void onEnter(Miner* pMiner);
    virtual void onExit(Miner* pMiner);
    virtual void execute(Miner* pMiner);
    
private:
    GoHomeAndSleepTilRested() {}
};


#endif /* defined(__test226__GoHomeAndSleepTilRested__) */
