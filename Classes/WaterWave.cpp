//
//  WaterWave.cpp
//  Learn36
//
//  Created by DONG on 15/5/7.
//
//

#include "WaterWave.h"

bool WaterWave::init()
{
    if (!Sprite::initWithFile("water.jpg"))
    {
        return false;
    }
    
    
    initShader();
    
    this->schedule([=](float dt) {
        _time += dt;
        CCLOG("%f", _time);
        
        getGLProgramState()->setUniformFloat("u_time", _time);
        
    }, "updatetime");
    return true;
}

bool WaterWave::initShader()
{
    auto glProgram = GLProgram::createWithFilenames("water.vert", "water.frag");

    auto glState = GLProgramState::create(glProgram);
    setGLProgramState(glState);
    glState->setUniformFloat("u_time", 0);
    
    return true;
}