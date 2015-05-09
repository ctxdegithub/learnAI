#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Miner/Miner.h"
#include "Miner/MinerUI.h"
#include "Animal/Fly.h"
#include "MinerWife/MinerWife.h"
#include "Entity/EntityNames.h"
#include "Managers/MessageDispatcher.h"
#include "Managers/EntityManager.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    m_worldMap = WorldMap::getInstance();
    addChild(m_worldMap);
    
    auto fly = Fly::create(fly_id);
    fly->setOriginPos(BAR_POS);
    fly->setPosition(BAR_POS);
    addChild(fly);
    
    m_pMiner = Miner::create(miner_id);
    addChild(m_pMiner);
    m_time = 0;

    auto minerUI = MinerUI::create(m_pMiner);
    addChild(minerUI);
    m_pMiner->setMinerUI(minerUI);
    
    m_pMinerWife = MinerWife::create(wife_id);
    addChild(m_pMinerWife);
    

    
    this->scheduleUpdate();
    
    return true;
}

void HelloWorld::update(float dt)
{
    m_time += dt;
    if (m_time > 15.f)
    {
        m_time -= 15.f;
        
        auto fly = static_cast<Fly*>(ENTITYMGR->getEntityByID(fly_id));
        if (fly == nullptr)
        {
            fly = Fly::create(fly_id);
            fly->setOriginPos(BAR_POS);
            fly->setPosition(BAR_POS);
            addChild(fly);
        }

    }
    
    MSGMANAGER->update(dt);
    ENTITYMGR->update(dt);
    
}
