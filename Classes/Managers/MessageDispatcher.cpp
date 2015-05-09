//
//  MessageDispatcher.cpp
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#include "MessageDispatcher.h"
#include "../Entity/BaseGameEntity.h"
#include "EntityManager.h"

MessageDispatcher* MessageDispatcher::getInstance()
{
    static MessageDispatcher msg;
    return &msg;
}

void MessageDispatcher::dispatchMessage(int sender, int receiver, MessageType msgType, void *extraInfo, int priority, float delay)
{
    Telegram msg(sender, receiver, msgType, extraInfo);
    dispatchMessage(msg, priority, delay);
}

void MessageDispatcher::dispatchMessage(const Telegram& msg, int priority, float delay)
{
    if (delay <= 0.f)
    {
        ENTITYMGR->getEntityByID(msg.receiver)->handleMessage(msg);
    }
    else
    {
        MessageData msgData;
        msgData.msgInfo = msg;
        msgData.delay = delay;
        msgData.priority = priority;
        msgData.endTime = m_curTime + delay;
        m_msgQueue.insert(msgData);
    }
}
    
void MessageDispatcher::update(float dt)
{
    m_curTime += dt;
    while (!m_msgQueue.empty() && m_msgQueue.begin()->endTime >= m_curTime)
    {
        this->dispatchMessage(ENTITYMGR->getEntityByID(m_msgQueue.begin()->msgInfo.receiver), m_msgQueue.begin()->msgInfo);
        m_msgQueue.erase(m_msgQueue.begin());
    }
    
}

void MessageDispatcher::dispatchMessage(BaseGameEntity* receiver, const Telegram& msg)
{
    receiver->handleMessage(msg);
}