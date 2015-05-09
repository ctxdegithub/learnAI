//
//  BaseGameEntity.h
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#ifndef __test226__BaseGameEntity__
#define __test226__BaseGameEntity__

#include "cocos2d.h"
#include "../Message/Message.h"
USING_NS_CC;

class BaseGameEntity : public Node
{
public:
    BaseGameEntity(int id);
    virtual ~BaseGameEntity();
    virtual bool init();
    virtual void update(float) = 0;
    virtual void handleMessage(const Telegram& msg) = 0;
    virtual const char* getName();
    
    static int getNextValidID() { return m_iNextValidID; }
private:
    static int m_iNextValidID;
    
protected:
    CC_SYNTHESIZE(int, m_iID, ID);
    std::string m_strName;
    DrawNode* m_drawNode;
};
#endif /* defined(__test226__BaseGameEntity__) */
