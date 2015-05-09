//
//  QuenchThirst.cpp
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#include "QuenchThirst.h"
#include "States.h"
#include "../Managers/EntityManager.h"
#include "../Animal/Fly.h"

QuenchThirst* QuenchThirst::getInstance()
{
    static QuenchThirst s_instance;
    return &s_instance;
}

void QuenchThirst::onEnter(Miner* pMiner)
{
    if (pMiner->getLocationType() != Miner::BAR)
    {
        pMiner->setTargetLocationType(Miner::BAR);
        CCLOG("%s: Boy, ah sure is thusty! Walking to the bar.", pMiner->getName());
    }
}

void QuenchThirst::onExit(Miner* pMiner)
{
    if (!pMiner->isThirsty())
    {
        CCLOG("%s: Leaving the bar, feeling good.", pMiner->getName());
    }
    else if (pMiner->isFatigued())
    {
        CCLOG("%s: I'm fatigued.", pMiner->getName());
    }
}

void QuenchThirst::execute(Miner* pMiner)
{
    pMiner->buyADirnk();
    if (pMiner->isThirsty())
    {
        auto fly = static_cast<Fly*>(ENTITYMGR->getEntityByID(fly_id));
        if (fly != nullptr)
        {
            CCLOG("%s: There's a fly.", pMiner->getName());
            pMiner->getFSM()->changeState(HitFly::getInstance());
        }
        return;
    }
    if (pMiner->isFatigued())
    {
        CCLOG("%s: go home.", pMiner->getName());
        pMiner->getFSM()->changeState(GoHomeAndSleepTilRested::getInstance());
        return;
    }
    if (!pMiner->isThirsty())
    {
        CCLOG("%s: That's mighty fine sipping liquer.", pMiner->getName());
        pMiner->getFSM()->changeState(EnterMineAndDigForNugget::getInstance());
        return;
    }
}

