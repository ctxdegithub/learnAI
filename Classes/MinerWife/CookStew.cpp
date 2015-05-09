//
//  CookStew.cpp
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#include "CookStew.h"
#include "States.h"

CookStew* CookStew::getInstance()
{
    static CookStew s_intance;
    return &s_intance;
}

void CookStew::onEnter(MinerWife *pMinerWife)
{
    if (!pMinerWife->getCooking())
    {
        CCLOG("%s: Puttin' the stew in the overn.", pMinerWife->getName());
        MSGMANAGER->dispatchMessage(pMinerWife->getID(), pMinerWife->getID(), Msg_StewReady, nullptr, 0, 1.5f);
        pMinerWife->setCooking(true);
        m_bStewReady = false;
    }
}

bool CookStew::onMessage(MinerWife *pMinerWife, const Telegram &msg)
{
    time_t curtime = time(nullptr);
    switch (msg.msgType) {
        case Msg_StewReady:
            CCLOG("%s: receive message at time: %s. Stew Ready, Let's eat it.",
                    pMinerWife->getName(), ctime(&curtime));
            pMinerWife->setCooking(false);
            m_bStewReady = true;
            return true;
            break;
        default:
            break;
    }
    
    return false;
}

void CookStew::onExit(MinerWife *pMinerWife)
{
//    CCLOG("%s: Stew Readdy.", pMinerWife->getName());
}

void CookStew::execute(MinerWife *pMinerWife)
{
    if (pMinerWife->getCooking())
    {
        CCLOG("%s: I'm waiting for stew.", pMinerWife->getName());
    }
    else if (m_bStewReady)
    {
        CCLOG("%s: Stew Readdy.", pMinerWife->getName());
        MSGMANAGER->dispatchMessage(pMinerWife->getID(), miner_id, Msg_StewReady);
        pMinerWife->getFSM()->changeState(DoHouseWork::getInstance());
        m_bStewReady = false;
    }
}