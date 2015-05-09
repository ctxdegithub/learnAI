//
//  EnterMineAndDigForNugget.cpp
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#include "EnterMineAndDigForNugget.h"
#include "States.h"

EnterMineAndDigForNugget* EnterMineAndDigForNugget::getInstance()
{
    static EnterMineAndDigForNugget s_instance;
    return &s_instance;
}

void EnterMineAndDigForNugget::onEnter(Miner *pMiner)
{
    if (pMiner->getLocationType() != Miner::GOLDMINE)
    {
        CCLOG("%s: walkin to the gold mine.", pMiner->getName());
        pMiner->setTargetLocationType(Miner::GOLDMINE);
    }
}

void EnterMineAndDigForNugget::onExit(Miner *pMiner)
{
    CCLOG("%s: Leaving the gold mine.", pMiner->getName());
}

void EnterMineAndDigForNugget::execute(Miner *pMiner)
{
    pMiner->addToGoldCarried(rand() % 8);
    pMiner->increaseFatigue();
    pMiner->increaseThirsty();

    if (pMiner->isThirsty())
    {
        pMiner->getFSM()->changeState(QuenchThirst::getInstance());
    }
    else if (pMiner->isFatigued())
    {
        pMiner->getFSM()->changeState(GoHomeAndSleepTilRested::getInstance());
    }
    else if (pMiner->isPocketsFull())
    {
        pMiner->getFSM()->changeState(VisitBankAndDepositGold::getInstance());
    }
}