//
//  Miner.h
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#ifndef __test226__Miner__
#define __test226__Miner__

#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "WorldMap.h"

class MinerUI;
class Miner : public BaseGameEntity
{
public:
    enum LocationType
    {
        LOCATION_NONE = 0,
        HOME,
        GOLDMINE,
        BAR,
        BANK,
        WORLD,
        ON_THE_WAY,
    };
public:
    static Miner* create(int id);
    Miner(int id);
    ~Miner();
    bool init();
    void update(float dt);
    const char* getName();
    StateMachine<Miner>* getFSM() { return m_pStateMachine; }
    void updatePos(float dt);
    
    void addToGoldCarried(int gold);
    void clearGoldCarried();
    void addToWealth(int gold);
    void increaseFatigue();
    void decreaseFatigue();
    bool isPocketsFull();
    bool isThirsty();
    void buyADirnk();
    bool isFatigued();
    bool isCanSaveToBank();
    bool isCanBuyHouse();
    void buyHouse(WorldMap::HouseType type);
    
    LocationType getLocationType() { return m_locationType; }
    bool setLocationType(LocationType location);
    
private:
    StateMachine<Miner>* m_pStateMachine;
    DrawNode* m_drawNode;
    
    Vec2 m_ptPos;
    float m_speed;
    CC_SYNTHESIZE_READONLY(int, m_iGoldCarried, GoldCarried);
    CC_SYNTHESIZE_READONLY(int, m_iMaxGoldCarried, MaxGoldCarried);
    CC_SYNTHESIZE_READONLY(int, m_iMoneyInBank, MoneyInBank);
    int m_iLastMaxMoney;
    CC_SYNTHESIZE_READONLY(int, m_iMaxMoneyInBank, MaxMoneyInBank);
    CC_SYNTHESIZE_READONLY(int, m_iThirst, Thirst);
    CC_SYNTHESIZE_READONLY(int, m_iMaxThirst, MaxThirst);
    CC_SYNTHESIZE_READONLY(int, m_iFatigue, Fatigue);
    CC_SYNTHESIZE_READONLY(int, m_iMaxFatigue, MaxFatigue);
    
    bool m_bThirst;
    int m_iThirstLow;
    bool m_bFatigue;
    int m_iFatigueLow;
    
    LocationType m_locationType;
    LocationType m_targetLocationType;
    Rect m_nextArea;
    
    CC_SYNTHESIZE(MinerUI*,  m_minerUI, MinerUI);
};


#endif /* defined(__test226__Miner__) */
