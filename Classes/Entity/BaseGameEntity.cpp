//
//  BaseGameEntity.cpp
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#include "BaseGameEntity.h"
#include "../Managers/EntityManager.h"

int BaseGameEntity::m_iNextValidID = 0;

BaseGameEntity::BaseGameEntity(int id) :
    m_iID(id)
{
    ENTITYMGR->registerEntity(this);
    m_strName = "BaseGameEntity";
//    assert(id >= m_iNextValidID && "<BaseGameEntity::BaseGameEntity(): invalid id");
    m_iID = id;
    m_iNextValidID = id + 1;
}

BaseGameEntity::~BaseGameEntity()
{
    ENTITYMGR->removeEntity(this);
}

bool BaseGameEntity::init()
{
    if (!Node::init())
    {
        return false;
    }
    
    m_drawNode = DrawNode::create();
    addChild(m_drawNode);
    
    return true;
}

const char* BaseGameEntity::getName()
{
    return m_strName.c_str();
}