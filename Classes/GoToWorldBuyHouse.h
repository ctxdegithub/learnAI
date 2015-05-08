//
//  GoToWorldBuyHouse.h
//  Learn36
//
//  Created by DONG on 15/5/8.
//
//

#ifndef __Learn36__GoToWorldBuyHouse__
#define __Learn36__GoToWorldBuyHouse__

#include "State.h"
#include "Miner.h"

class GoToWorldBuyHouse : public State<Miner>
{
public:
    static GoToWorldBuyHouse* getInstance();
    virtual void onEnter(Miner* pMiner);
    virtual void onExit(Miner* pMiner);
    virtual void execute(Miner* pMiner);
    
private:
    GoToWorldBuyHouse() {}
};


#endif /* defined(__Learn36__GoToWorldBuyHouse__) */
