//
//  QuenchThirst.cpp
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#include "QuenchThirst.h"
#include "States.h"

QuenchThirst* QuenchThirst::getInstance()
{
    static QuenchThirst s_instance;
    return &s_instance;
}

void QuenchThirst::onEnter(Miner* pMiner)
{
    if (pMiner->getLocationType() != Miner::BAR)
    {
        pMiner->setLocationType(Miner::BAR);
        CCLOG("%s: Boy, ah sure is thusty! Walking to the bar.", pMiner->getName());
    }
}

void QuenchThirst::onExit(Miner* pMiner)
{
    CCLOG("%s: Leaving the bar, feeling good", pMiner->getName());
}

void QuenchThirst::execute(Miner* pMiner)
{
    if (pMiner->isThirsty())
    {
        pMiner->buyADirnk();
        if (!pMiner->isThirsty())
        {
            CCLOG("%s: That's mighty fine sipping liquer", pMiner->getName());
            pMiner->getFSM()->changeState(EnterMineAndDigForNugget::getInstance());
        }
    }
    else
    {
        CCLOG("Thirst ERROR!!!!!!!");
    }
}

