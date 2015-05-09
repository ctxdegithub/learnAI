//
//  Fly.cpp
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#include "Fly.h"
#include "../Message/Message.h"
#include "../Managers/EntityManager.h"

Fly* Fly::create(int id)
{
    auto fly = new Fly(id);
    if (fly && fly->init())
    {
        fly->autorelease();
        return fly;
    }
    delete fly;
    return nullptr;
}

Fly::Fly(int id) :
    BaseGameEntity(id),
    m_hp(200 + rand() % 100),
    m_maxHp(m_hp),
    m_eludeRate(60 + rand() % 10)
{
    m_strName = StringUtils::format("Fly%d", id);
}

bool Fly::init()
{
    if (!BaseGameEntity::init())
    {
        return false;
    }
    m_bCanHit = false;
    m_hitDelay = 0.f;
    m_drawNode->drawDot(Vec2::ZERO, 10, Color4F(0.f, 0.f, 1.f, 1.f));
    
    return true;
}

void Fly::setOriginPos(const cocos2d::Vec2 &pos)
{
    m_originPos = pos;
    this->stopAllActions();
    this->runAction(Sequence::create(
                                MoveTo::create(0.5f, m_originPos + Vec2(50 * CCRANDOM_MINUS1_1(), 50 * CCRANDOM_MINUS1_1())),
                                CallFunc::create([=]() {
                                    this->setOriginPos(m_originPos);
                                }), nullptr));
}

void Fly::update(float dt)
{
    if (!m_bCanHit)
    {
        m_hitDelay += dt;
        if (m_hitDelay > 1.7f)
        {
            m_hitDelay -= 1.7f;
            m_bCanHit = true;
            this->setOriginPos(m_originPos);
        }
    }
}

void Fly::handleMessage(const Telegram& msg)
{
    switch (msg.msgType) {
        case Msg_BeHit:
            this->hurt(msg.extraInt);
            break;
            
        default:
            break;
    }
}

const char* Fly::getName()
{
    return m_strName.c_str();
}

void Fly::hurt(int attack)
{
    if (m_eludeRate < rand() % 100)
    {
        this->stopAllActions();
        m_hp -= attack;
        m_bCanHit = false;
        if (m_hp <= 0)
        {
            ENTITYMGR->registerEntity(this);
            removeFromParent();
            return;
        }
    }
}