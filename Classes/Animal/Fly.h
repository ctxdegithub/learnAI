//
//  Fly.h
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#ifndef __Learn36__Fly__
#define __Learn36__Fly__

#include "../Entity/BaseGameEntity.h"

class Fly : public BaseGameEntity
{
public:
    static Fly* create(int id);
    Fly(int id);
    bool init();
    void update(float);
    void handleMessage(const Telegram& msg);
    const char* getName();
    
    void setOriginPos(const Vec2& pos);
    bool getCanHit() { return m_bCanHit; }
    
private:
    void hurt(int attack);
    
private:
    Vec2 m_originPos;
    bool m_bCanHit;
    int m_hp;
    int m_maxHp;
    int m_eludeRate;
    float m_hitDelay;
};

#endif /* defined(__Learn36__Fly__) */
