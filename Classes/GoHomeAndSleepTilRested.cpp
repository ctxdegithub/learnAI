//
//  GoHomeAndSleepTilRested.cpp
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#include "GoHomeAndSleepTilRested.h"
#include "States.h"

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::getInstance()
{
    static GoHomeAndSleepTilRested s_instance;
    return &s_instance;
}

void GoHomeAndSleepTilRested::onEnter(Miner* pMiner)
{
    if (pMiner->getLocationType() != Miner::HOME)
    {
        CCLOG("%s: walkin home.", pMiner->getName());
        pMiner->setLocationType(Miner::HOME);
    }
}

void GoHomeAndSleepTilRested::onExit(Miner* pMiner)
{
    CCLOG("%s: leaving the home.", pMiner->getName());
}

void GoHomeAndSleepTilRested::execute(Miner* pMiner)
{
    if (pMiner->isFatigued())
    {
        pMiner->decreaseFatigue();
        CCLOG("%s: ZZZZ....", pMiner->getName());
    }
    else if (pMiner->isThirsty())
    {
        pMiner->getFSM()->changeState(QuenchThirst::getInstance());
    }
    else if (!pMiner->isFatigued())
    {
        CCLOG("%s: time to find more gold.", pMiner->getName());
        pMiner->getFSM()->changeState(EnterMineAndDigForNugget::getInstance());
    }
}

