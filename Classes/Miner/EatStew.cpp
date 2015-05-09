//
//  EatStew.cpp
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#include "EatStew.h"
#include "States.h"

EatStew* EatStew::getInstance()
{
    static EatStew s_instance;
    return &s_instance;
}

void EatStew::onEnter(Miner* pMiner)
{
    CCLOG("%s: start to eat stew.", pMiner->getName());
}

void EatStew::onExit(Miner* pMiner)
{
    CCLOG("%s: I'm full.", pMiner->getName());
}

void EatStew::execute(Miner* pMiner)
{
    CCLOG("%s: The stew is so delicious.", pMiner->getName());
    pMiner->getFSM()->revertToPreviousState();
}
