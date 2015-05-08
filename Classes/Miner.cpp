//
//  Miner.cpp
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#include "Miner.h"
#include "States.h"
#include "WorldMap.h"
#include "MinerUI.h"

Rect getArea(Vec2 pos)
{
    return Rect(pos.x - 10, pos.y - 10, 20, 20);
}

Miner* Miner::create(int id)
{
    Miner* pMiner = new Miner(id);
    if (pMiner && pMiner->init())
    {
        pMiner->autorelease();
        return pMiner;
    }
    delete pMiner;
    return nullptr;
}

Miner::Miner(int id) :
    BaseGameEntity(id),
    m_iFatigue(0),
    m_iFatigueLow(10),
    m_iMaxFatigue(100),
    m_iThirst(0),
    m_iThirstLow(5),
    m_iMaxThirst(100),
    m_iGoldCarried(0),
    m_iMaxGoldCarried(100),
    m_iMoneyInBank(0),
    m_iMaxMoneyInBank(600),
    m_iLastMaxMoney(600),
    m_speed(400),
    m_ptPos(HOME_POS),
    m_locationType(HOME),
    m_bFatigue(false),
    m_bThirst(false)
{
    
    m_pStateMachine = new StateMachine<Miner>(this);
    m_pStateMachine->setCurrentState(GoHomeAndSleepTilRested::getInstance());
    m_pStateMachine->setGlobalState(EnterMineAndDigForNugget::getInstance());
    m_strName = StringUtils::format("Mine%d", m_iID);
}

Miner::~Miner()
{
    delete m_pStateMachine;
    m_pStateMachine = nullptr;
}

bool Miner::init()
{
    if (!BaseGameEntity::init())
    {
        return false;
    }
    m_nextArea = getArea(HOME_POS);
    setPosition(m_ptPos);
    m_drawNode = DrawNode::create();
    addChild(m_drawNode);
    m_drawNode->drawDot(Vec2(0, 0), 15.f, Color4F(1.f, 0.f, 0.f, 1.f));
    
    m_minerUI = nullptr;
    return true;
}

const char* Miner::getName()
{
    return m_strName.c_str();
}

void Miner::update(float dt)
{
    updatePos(dt);
    if (m_locationType == ON_THE_WAY)
    {
        m_iThirst += rand() % 200 < 20 ? 1 : 0;
        if (m_iThirst >= m_iMaxThirst)
        {
            m_bThirst = true;
        }
        m_minerUI->updateUI();
        return;
    }
    
    m_pStateMachine->update(dt);
    CCLOG("%s: thirst:(%d/%d), fatigue:(%d/%d), gold:(%d/%d), money:%d", getName(),
          m_iThirst, m_iMaxThirst, m_iFatigue, m_iMaxFatigue, m_iGoldCarried, m_iMaxGoldCarried, m_iMoneyInBank);
}

void Miner::updatePos(float dt)
{
    Vec2 curPos = getPosition();
    
    if (m_nextArea.containsPoint(curPos))
    {
        m_locationType = m_targetLocationType;
        return;
    }

    Vec2 dir = (m_ptPos - curPos).getNormalized();
    Vec2 move = dir * (m_speed * dt);
    setPosition(curPos + move);

}

void Miner::addToGoldCarried(int gold)
{
    m_iGoldCarried += gold;
    if (m_iGoldCarried < 0)
    {
        m_iGoldCarried = 0;
    }
    m_minerUI->updateUI();
}

void Miner::clearGoldCarried()
{
    m_iGoldCarried = 0;
    m_minerUI->updateUI();
}

bool Miner::isCanSaveToBank()
{
    return m_iMoneyInBank >= m_iLastMaxMoney;
}

bool Miner::isCanBuyHouse()
{
    return m_iMoneyInBank >= (int)WorldMap::NORMAL;
}

void Miner::buyHouse(WorldMap::HouseType type)
{
    WorldMap::getInstance()->buyHouse(type);
    m_iLastMaxMoney = m_iMaxMoneyInBank;
    m_iMaxMoneyInBank += m_iMaxMoneyInBank / 4;
    m_iMoneyInBank -= WorldMap::getInstance()->getMoneyByHouse(type);
}

void Miner::addToWealth(int gold)
{
    m_iMoneyInBank += gold;
    m_minerUI->updateUI();
}

void Miner::increaseFatigue()
{
    m_iFatigue += rand() % 5;
    if (m_iFatigue > m_iMaxFatigue)
    {
        m_iFatigue = m_iMaxFatigue;
    }
    if (m_iFatigue >= m_iMaxFatigue)
    {
        m_bFatigue = true;
    }
    m_minerUI->updateUI();
}

void Miner::decreaseFatigue()
{
    m_iFatigue -= rand() % 5;
    if (m_iFatigue < 0)
    {
        m_iFatigue = 0;
    }
    if (m_bFatigue && m_iFatigue < m_iFatigueLow) {
        m_bFatigue = false;
    }
    m_minerUI->updateUI();
}

bool Miner::isPocketsFull()
{
    return m_iGoldCarried >= m_iMaxGoldCarried;
}

bool Miner::isThirsty()
{
    return m_bThirst;
}

void Miner::buyADirnk()
{
    int drinkCost = rand() % 5;
    if (drinkCost > m_iMoneyInBank)
    {
        drinkCost = m_iMoneyInBank;
    }
    if (drinkCost > m_iThirst)
    {
        drinkCost = m_iThirst;
    }
    m_iMoneyInBank -= drinkCost;
    if (drinkCost == 0)
    {
        drinkCost++;
    }

    m_iThirst -= drinkCost;
    if (m_iThirst < 0)
    {
        m_iThirst = 0;
    }
    if (m_bThirst && m_iThirst < m_iThirstLow)
    {
        m_bThirst = false;
    }
    
    m_minerUI->updateUI();
}

bool Miner::isFatigued()
{
    return m_bFatigue;
}

bool Miner::setLocationType(LocationType location)
{
    if (m_locationType == ON_THE_WAY)
    {
        return false;
    }
    
    switch (location)
    {
        case HOME:
            m_ptPos = HOME_POS;
            break;
        case BANK:
            m_ptPos = BANK_POS;
            break;
        case BAR:
            m_ptPos = BAR_POS;
            break;
        case GOLDMINE:
            m_ptPos = MINE_POS;
            break;
        default:
            break;
    }
    m_locationType = ON_THE_WAY;
    m_targetLocationType = location;
    m_nextArea = getArea(m_ptPos);
    return true;
}

