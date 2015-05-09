//
//  MinerWife.h
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#ifndef __Learn36__MinerWife__
#define __Learn36__MinerWife__

#include "../Entity/BaseGameEntity.h"
#include "../FSM/StateMachine.h"
#include "../Managers/MessageDispatcher.h"
#include "../Entity/EntityNames.h"
#include "WorldMap.h"

class MinerWife : public BaseGameEntity
{
public:
    static MinerWife* create(int id);
    MinerWife(int id);
    ~MinerWife();
    
    StateMachine<MinerWife>* getFSM() { return m_stateMachine; }
    virtual bool init();
    virtual void update(float dt);
    virtual void handleMessage(const Telegram& msg);
    virtual const char* getName();
    
private:
    StateMachine<MinerWife>* m_stateMachine;
    CC_SYNTHESIZE(bool, m_bCooking, Cooking);
    CC_SYNTHESIZE(bool, m_bHouseWork, HouseWork);
};

#endif /* defined(__Learn36__MinerWife__) */
