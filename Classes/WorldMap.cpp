//
//  WorldMap.cpp
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#include "WorldMap.h"

WorldMap* WorldMap::s_instance = nullptr;

WorldMap* WorldMap::getInstance()
{
    if (s_instance == nullptr)
    {
        s_instance = WorldMap::create();
    }
    return s_instance;
}

bool WorldMap::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    
    m_drawNode = CCDrawNode::create();
    addChild(m_drawNode);
    
    auto label = CCLabelTTF::create("Home", "", 24);
    addChild(label);
    label->setPosition(HOME_POS);
    m_drawNode->drawSegment(HOME_POS, MINE_POS, 2.f, Color4F(1.f, 1.f, 0, 1.f));
    
    label = CCLabelTTF::create("Mine", "", 24);
    addChild(label);
    label->setPosition(MINE_POS);
    m_drawNode->drawSegment(MINE_POS, BANK_POS, 2.f, Color4F(1.f, 1.f, 0, 1.f));
    label = CCLabelTTF::create("Bank", "", 24);
    addChild(label);
    label->setPosition(BANK_POS);
    m_drawNode->drawSegment(BANK_POS, BAR_POS, 2.f, Color4F(1.f, 1.f, 0, 1.f));
    label = CCLabelTTF::create("Bar", "", 24);
    addChild(label);
    label->setPosition(BAR_POS);
    m_drawNode->drawSegment(BAR_POS, HOME_POS, 2.f, Color4F(1.f, 1.f, 0, 1.f));
    
    m_drawNode->drawRect(WORLD_AREA.origin, Vec2(WORLD_AREA.getMaxX(), WORLD_AREA.getMaxY()), Color4F(1.f, 0.f, 0.f, 1.f));
    
    m_iSellHouseCount = 0;
    return true;
}

void WorldMap::buyHouse(HouseType type)
{
    Vec2 pos = WORLD_AREA.origin + Vec2((m_iSellHouseCount % 5) * (WORLD_AREA.size.width / 5),
                                        m_iSellHouseCount / 5 * (WORLD_AREA.size.height / 5));
    m_iSellHouseCount++;
    Color4F color;
    switch (type)
    {
        case NORMAL:
            color = Color4F(0.2f, 0.5, 0.2f, 1.f);
            break;
        case GOOD:
            color = Color4F(0.2f, 1.f, 0.2f, 1.f);
            break;
        case PRETTY:
            color = Color4F(1.f, 0.5, 1.f, 1.f);
            break;
        default:
            break;
    }
    m_drawNode->drawDot(pos, 16, color);
}

int WorldMap::getMoneyByHouse(HouseType type)
{
    switch (type)
    {
        case NORMAL:
            return 500;
            break;
        case GOOD:
            return 800;
            break;
        case PRETTY:
            return 1200;
            break;
        default:
            break;
    }
    
    return INT_MAX;
}

WorldMap::HouseType WorldMap::whatHouseCanBuy(int money)
{
    if (money >= WorldMap::getInstance()->getMoneyByHouse(WorldMap::PRETTY))
    {
        return PRETTY;
    }
    else if (money >= WorldMap::getInstance()->getMoneyByHouse(WorldMap::GOOD))
    {
        return GOOD;
    }
    else if (money >= WorldMap::getInstance()->getMoneyByHouse(WorldMap::NORMAL))
    {
        return NORMAL;
    }
    
    return HOUSE_NO_PRICE;
}