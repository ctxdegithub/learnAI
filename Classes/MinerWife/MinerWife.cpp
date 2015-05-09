//
//  MinerWife.cpp
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#include "MinerWife.h"
#include "States.h"

MinerWife* MinerWife::create(int id)
{
    auto pMinerWife = new MinerWife(id);
    if (pMinerWife && pMinerWife->init())
    {
        pMinerWife->autorelease();
        return pMinerWife;
    }
    delete pMinerWife;
    return nullptr;
}

MinerWife::MinerWife(int id) :
    BaseGameEntity(id),
    m_bCooking(false),
    m_bHouseWork(false)
{
    m_strName = StringUtils::format("wife%d", id);
    m_stateMachine = new StateMachine<MinerWife>(this);
    m_stateMachine->setCurrentState(DoHouseWork::getInstance());
}

MinerWife::~MinerWife()
{
    delete m_stateMachine;
    m_stateMachine = nullptr;
}

bool MinerWife::init()
{
    if (!BaseGameEntity::init())
    {
        return false;
    }
    
    return true;
}

void MinerWife::update(float dt)
{
    m_stateMachine->update(dt);
}

void MinerWife::handleMessage(const Telegram& msg)
{
    m_stateMachine->handleMessage(msg);
}

const char* MinerWife::getName()
{
    return m_strName.c_str();
}