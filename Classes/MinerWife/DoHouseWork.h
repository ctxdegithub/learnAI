//
//  DoHouseWork.h
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#ifndef __Learn36__DoHouseWork__
#define __Learn36__DoHouseWork__

#include "../FSM/State.h"
#include "MinerWife.h"

class DoHouseWork : public State<MinerWife>
{
public:
    static DoHouseWork* getInstance();
    virtual void onEnter(MinerWife* pMinerWife);
    virtual void onExit(MinerWife* pMinerWife);
    virtual void execute(MinerWife* pMinerWife);
    
    virtual bool onMessage(MinerWife* pMinerWife, const Telegram& msg);
    
private:
    DoHouseWork() {}
    
};

#endif /* defined(__Learn36__DoHouseWork__) */
