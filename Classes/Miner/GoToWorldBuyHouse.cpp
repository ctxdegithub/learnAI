//
//  GoToWorldBuyHouse.cpp
//  Learn36
//
//  Created by DONG on 15/5/8.
//
//

#include "GoToWorldBuyHouse.h"
#include "States.h"
#include "WorldMap.h"

GoToWorldBuyHouse* GoToWorldBuyHouse::getInstance()
{
    static GoToWorldBuyHouse s_instance;
    return &s_instance;
}

void GoToWorldBuyHouse::onEnter(Miner* pMiner)
{
    if (pMiner->getLocationType() != Miner::WORLD)
    {
        CCLOG("%s: goto world.", pMiner->getName());
        pMiner->setTargetLocationType(Miner::WORLD);
    }
}

void GoToWorldBuyHouse::onExit(Miner* pMiner)
{
    CCLOG("%s: maybe buy a house.", pMiner->getName());
}

void GoToWorldBuyHouse::execute(Miner* pMiner)
{
    int money = pMiner->getMoneyInBank();
    WorldMap::HouseType type = WorldMap::getInstance()->whatHouseCanBuy(money);
    if (type != WorldMap::HOUSE_NO_PRICE)
    {
        pMiner->buyHouse(type);
    }
    
    pMiner->getFSM()->changeState(GoHomeAndSleepTilRested::getInstance());
}