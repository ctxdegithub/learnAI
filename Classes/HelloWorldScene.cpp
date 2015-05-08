#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Miner.h"
#include "MinerUI.h"

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
    
    m_pMiner = Miner::create(Miner::getNextValidID());
    addChild(m_pMiner);
    m_time = 0;
    
    auto minerUI = MinerUI::create(m_pMiner);
    addChild(minerUI);
    m_pMiner->setMinerUI(minerUI);
    
    m_worldMap = WorldMap::getInstance();
    addChild(m_worldMap);
    
    this->scheduleUpdate();
    
    return true;
}

void HelloWorld::update(float dt)
{
    //    m_time += dt;
    //    if (m_time > 1.f)
    {
        m_time -= 1.f;
        m_pMiner->update(dt);
    }
    
}
