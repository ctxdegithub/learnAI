//
//  MinerUI.h
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#ifndef __test226__MinerUI__
#define __test226__MinerUI__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d::ui;

class Miner;
class MinerUI : public Layer
{
public:
    static MinerUI* create(Miner* pMiner);
    bool init(Miner *pMiner);
    void updateUI();
    
private:
    Text* m_pLabelThirst;
    LoadingBar* m_pProgressThirst;
    
    Text* m_pLabelFatigue;
    LoadingBar* m_pProgressFatigue;
    
    Text* m_pLabelGold;
    LoadingBar* m_pProgressGold;
    
    Text* m_pLabelMoney;
    LoadingBar* m_pProgressMoney;
    
    Miner* m_pMiner;
};

#endif /* defined(__test226__MinerUI__) */
