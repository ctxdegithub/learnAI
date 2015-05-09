//
//  DoHouseWork.cpp
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#include "DoHouseWork.h"
#include "States.h"

DoHouseWork* DoHouseWork::getInstance()
{
    static DoHouseWork s_intance;
    return &s_intance;
}

void DoHouseWork::onEnter(MinerWife *pMinerWife)
{
    if (!pMinerWife->getHouseWork())
    {
        CCLOG("%s: Start to do housework.", pMinerWife->getName());
        pMinerWife->setHouseWork(true);
    }
}

bool DoHouseWork::onMessage(MinerWife *pMinerWife, const Telegram &msg)
{
    time_t curtime = time(nullptr);
    switch (msg.msgType) {
        case Msg_ImHome:
            CCLOG("%s: receive message at time: %s. start to cook skew.",
                  pMinerWife->getName(), ctime(&curtime));
            pMinerWife->getFSM()->changeState(CookStew::getInstance());
            return true;
            break;
        default:
            break;
    }
    
    return false;
}

void DoHouseWork::onExit(MinerWife *pMinerWife)
{
    CCLOG("%s: Housework is done.", pMinerWife->getName());
}

void DoHouseWork::execute(MinerWife *pMinerWife)
{
//    CCLOG("%s: I'm doing housework.", pMinerWife->getName());
}