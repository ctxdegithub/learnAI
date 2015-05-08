//
//  MinerUI.cpp
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#include "MinerUI.h"
#include "Miner.h"


MinerUI* MinerUI::create(Miner *pMiner)
{
    auto ui = new MinerUI;
    if (ui && ui->init(pMiner))
    {
        ui->autorelease();
        return ui;
    }
    delete ui;
    return nullptr;
}

bool MinerUI::init(Miner *pMiner)
{
    if (!CCLayer::init())
    {
        return false;
    }
    m_pMiner = pMiner;
    
    auto reader = CSLoader::createNode("MainScene.csb");
    addChild(reader);
    
    m_pProgressThirst = (LoadingBar*)reader->getChildByName("thirst_bar");
    m_pProgressFatigue = (LoadingBar*)reader->getChildByName("fatigue_bar");
    m_pProgressGold = (LoadingBar*)reader->getChildByName("gold_bar");
    m_pProgressMoney = (LoadingBar*)reader->getChildByName("money_bar");
    
    m_pLabelThirst = (Text*)reader->getChildByName("thirst_text");
    m_pLabelFatigue = (Text*)reader->getChildByName("fatigue_text");
    m_pLabelGold = (Text*)reader->getChildByName("gold_text");
    m_pLabelMoney = (Text*)reader->getChildByName("money_text");
    
    return true;
}

void MinerUI::updateUI()
{
    m_pProgressThirst->setPercent(m_pMiner->getThirst() * 100 / (float)m_pMiner->getMaxThirst());
    m_pProgressFatigue->setPercent(m_pMiner->getFatigue() * 100 / (float)m_pMiner->getMaxFatigue());
    m_pProgressGold->setPercent(m_pMiner->getGoldCarried() * 100 / (float)m_pMiner->getMaxGoldCarried());
    m_pProgressMoney->setPercent(m_pMiner->getMoneyInBank() * 100 / (float)m_pMiner->getMaxMoneyInBank());
    
    m_pLabelThirst->setString(StringUtils::format("thirst: %d/%d", m_pMiner->getThirst(), m_pMiner->getMaxThirst()));
    m_pLabelFatigue->setString(StringUtils::format("fatigue: %d/%d", m_pMiner->getFatigue(), m_pMiner->getMaxFatigue()));
    m_pLabelGold->setString(StringUtils::format("gold: %d/%d", m_pMiner->getGoldCarried(), m_pMiner->getMaxGoldCarried()));
    m_pLabelMoney->setString(StringUtils::format("money: %d/%d", m_pMiner->getMoneyInBank(), m_pMiner->getMaxMoneyInBank()));
}


