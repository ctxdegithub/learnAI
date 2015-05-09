//
//  CookStew.h
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#ifndef __Learn36__CookStew__
#define __Learn36__CookStew__

#include "../FSM/State.h"
#include "MinerWife.h"

class CookStew : public State<MinerWife>
{
public:
    static CookStew* getInstance();
    virtual void onEnter(MinerWife* pMinerWife);
    virtual void onExit(MinerWife* pMinerWife);
    virtual void execute(MinerWife* pMinerWife);
    
    virtual bool onMessage(MinerWife* pMinerWife, const Telegram& msg);
    
private:
    CookStew() {}
    
private:
    bool m_bStewReady;
};

#endif /* defined(__Learn36__CookStew__) */
