//
//  HitFly.cpp
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#include "HitFly.h"
#include "States.h"
#include "../Managers/EntityManager.h"
#include "../Message/Message.h"
#include "../Animal/Fly.h"

HitFly* HitFly::getInstance()
{
    static HitFly s_instance;
    return &s_instance;
}

void HitFly::onEnter(Miner* pMiner)
{
    CCLOG("%s: start to hit fly.", pMiner->getName());
}

void HitFly::onExit(Miner* pMiner)
{
    CCLOG("%s: I'm fatigued.", pMiner->getName());
}

void HitFly::execute(Miner* pMiner)
{
    auto fly = static_cast<Fly*>(ENTITYMGR->getEntityByID(fly_id));
    if (fly != nullptr && fly->getCanHit())
    {
        CCLOG("%s: I'm hitting the fly.", pMiner->getName());
        pMiner->hitFly();
        Telegram msg(pMiner->getID(), fly_id, Msg_BeHit);
        msg.extraInt = rand() % 20 + 45;
        MSGMANAGER->dispatchMessage(msg);
    }
    else
    {
        pMiner->getFSM()->revertToPreviousState();
        return;
    }
    if (pMiner->isFatigued())
    {
        pMiner->getFSM()->changeState(GoHomeAndSleepTilRested::getInstance());
    }
}
