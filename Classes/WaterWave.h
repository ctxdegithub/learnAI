//
//  WaterWave.h
//  Learn36
//
//  Created by DONG on 15/5/7.
//
//

#ifndef __Learn36__WaterWave__
#define __Learn36__WaterWave__

#include "cocos2d.h"
USING_NS_CC;

class WaterWave : public Sprite
{
public:
    CREATE_FUNC(WaterWave);
    bool init();
    
private:
    bool initShader();
    
private:
    float _time;
};

#endif /* defined(__Learn36__WaterWave__) */
