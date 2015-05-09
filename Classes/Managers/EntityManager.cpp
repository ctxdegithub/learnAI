//
//  EntityManager.cpp
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#include "EntityManager.h"

EntityManager* EntityManager::getInstance()
{
    static EntityManager s_instance;
    return &s_instance;
}

void EntityManager::registerEntity(BaseGameEntity* entity)
{
    m_entityMap.insert(make_pair(entity->getID(), entity));
}

void EntityManager::removeEntity(BaseGameEntity* entity)
{
    auto entityIter = m_entityMap.find(entity->getID());
    if (entityIter != m_entityMap.end())
    {
        m_entityMap.erase(entityIter);
    }
}

BaseGameEntity* EntityManager::getEntityByID(int id) const
{
    auto entity = m_entityMap.find(id);
    if (entity != m_entityMap.end())
    {
        return entity->second;
    }
    return nullptr;
}

void EntityManager::update(float dt)
{
    for (auto entity : m_entityMap) {
        (entity.second)->update(dt);
    }
}