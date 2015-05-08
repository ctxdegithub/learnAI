//
//  VisitBankAndDepositGold.cpp
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#include "VisitBankAndDepositGold.h"
#include "States.h"

VisitBankAndDepositGold* VisitBankAndDepositGold::getInstance()
{
    static VisitBankAndDepositGold s_instance;
    return &s_instance;
}

void VisitBankAndDepositGold::onEnter(Miner* pMiner)
{
    if (pMiner->getLocationType() != Miner::BANK)
    {
        CCLOG("%s: leavein the bank.", pMiner->getName());
        pMiner->setLocationType(Miner::BANK);
    }
}

void VisitBankAndDepositGold::onExit(Miner* pMiner)
{
    CCLOG("%s: the gold is empty.", pMiner->getName());
}

void VisitBankAndDepositGold::execute(Miner* pMiner)
{
    pMiner->addToWealth(pMiner->getGoldCarried());
    pMiner->clearGoldCarried();
    
    CCLOG("%s: Depositing gold. Total saving now: %d.", pMiner->getName(), pMiner->getMoneyInBank());
    
    if (pMiner->isCanSaveToBank())
    {
        if (pMiner->isCanBuyHouse())
        {
            CCLOG("%s: Rich enough for now. To buy a house.", pMiner->getName());
            pMiner->getFSM()->changeState(GoToWorldBuyHouse::getInstance());
        }
        else
        {
            CCLOG("%s: Rich enough for now. back home to meet lady.", pMiner->getName());
            pMiner->getFSM()->changeState(GoHomeAndSleepTilRested::getInstance());
        }
    }
    else if (pMiner->isThirsty())
    {
        pMiner->getFSM()->changeState(QuenchThirst::getInstance());
    }
    else if (pMiner->isFatigued())
    {
        pMiner->getFSM()->changeState(GoHomeAndSleepTilRested::getInstance());
    }
    else
    {
        pMiner->getFSM()->changeState(EnterMineAndDigForNugget::getInstance());
    }
    
}
