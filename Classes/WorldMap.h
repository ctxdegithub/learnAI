//
//  WorldMap.h
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#ifndef __test226__WorldMap__
#define __test226__WorldMap__

#include "cocos2d.h"
USING_NS_CC;

const Vec2 HOME_POS = Vec2(100, 80);
const Vec2 BAR_POS = Vec2(120, 550);
const Vec2 BANK_POS = Vec2(900, 540);
const Vec2 MINE_POS = Vec2(900, 100);

const Rect WORLD_AREA = Rect(150, 150, 700, 350);

class WorldMap :  public Node
{
public:
    enum HouseType
    {
        NORMAL = 0,
        GOOD,
        PRETTY,
        HOUSE_NO_PRICE,
    };
public:
    static WorldMap* getInstance();
    CREATE_FUNC(WorldMap);
    bool init();
    void buyHouse(HouseType type);
    int getMoneyByHouse(HouseType type);
    HouseType whatHouseCanBuy(int money);
    
private:
    static WorldMap* s_instance;
    DrawNode* m_drawNode;
    int m_iMoney;
    int m_iSellHouseCount;
};

#endif /* defined(__test226__WorldMap__) */
