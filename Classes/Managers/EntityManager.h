//
//  EntityManager.h
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#ifndef __Learn36__EntityManager__
#define __Learn36__EntityManager__
#include <map>
#include "../Entity/BaseGameEntity.h"
using namespace std;

class EntityManager
{
private:
    typedef std::map<int, BaseGameEntity*> EntityMap;
    
public:
    static EntityManager* getInstance();
    void registerEntity(BaseGameEntity* entity);
    void removeEntity(BaseGameEntity* entity);
    BaseGameEntity* getEntityByID(int id) const;
    
    void update(float dt);
    
private:
    EntityManager() {}
    

private:
    map<int, BaseGameEntity*> m_entityMap;
};

#define ENTITYMGR EntityManager::getInstance()

#endif /* defined(__Learn36__EntityManager__) */
