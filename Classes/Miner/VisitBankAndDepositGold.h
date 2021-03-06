//
//  VisitBankAndDepositGold.h
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#ifndef __test226__VisitBankAndDepositGold__
#define __test226__VisitBankAndDepositGold__

#include "../FSM/State.h"
#include "Miner.h"

class VisitBankAndDepositGold : public State<Miner>
{
public:
    static VisitBankAndDepositGold* getInstance();
    virtual void onEnter(Miner* pMiner);
    virtual void onExit(Miner* pMiner);
    virtual void execute(Miner* pMiner);
    virtual bool onMessage(Miner* pMiner, const Telegram& msg) { return true; }
    
private:
    VisitBankAndDepositGold() {}
};

#endif /* defined(__test226__VisitBankAndDepositGold__) */
