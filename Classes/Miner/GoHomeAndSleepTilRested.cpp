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
        pMiner->setTargetLocationType(Miner::HOME);
        m_bSendToEat = false;
        m_bWaitingStew = false;
        CCLOG("%s: walkin home.", pMiner->getName());
    }
}

void GoHomeAndSleepTilRested::onExit(Miner* pMiner)
{
    CCLOG("%s: leaving the home.", pMiner->getName());
}

void GoHomeAndSleepTilRested::execute(Miner* pMiner)
{
    if (!m_bSendToEat)
    {
        if (pMiner->getLocationType() == Miner::HOME)
        {
            m_bSendToEat = true;
            m_bWaitingStew = true;
            MSGMANAGER->dispatchMessage(miner_id, wife_id, Msg_ImHome);
        }
    }
    else if (pMiner->isFatigued())
    {
        pMiner->decreaseFatigue();
        CCLOG("%s: ZZZZ....", pMiner->getName());
        return;
    }

    if (!m_bWaitingStew)
    {
        if (pMiner->isThirsty())
        {
            pMiner->justDrink();
            CCLOG("%s: drink water~~~~~", pMiner->getName());
//            pMiner->getFSM()->changeState(QuenchThirst::getInstance());
        }
        else if (!pMiner->isFatigued())
        {
            CCLOG("%s: time to find more gold.", pMiner->getName());
            pMiner->getFSM()->changeState(EnterMineAndDigForNugget::getInstance());
        }
    }
}

bool GoHomeAndSleepTilRested::onMessage(Miner *pMiner, const Telegram &msg)
{
    time_t cutTime = time(nullptr);
    switch (msg.msgType) {
        case Msg_StewReady:
            if (pMiner->getLocationType() == Miner::HOME)
            {
                CCLOG("%s: receive message at time: %s", pMiner->getName(), ctime(&cutTime));
                m_bWaitingStew = false;
                pMiner->getFSM()->changeState(EatStew::getInstance());
            }
            break;
            
        default:
            break;
    }
    return true;
}
