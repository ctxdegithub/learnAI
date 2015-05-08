//
//  QuenchThirst.h
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#ifndef __test226__QuenchThirst__
#define __test226__QuenchThirst__

#include "State.h"
#include "Miner.h"

class QuenchThirst : public State<Miner>
{
public:
    static QuenchThirst* getInstance();
    virtual void onEnter(Miner* pMiner);
    virtual void onExit(Miner* pMiner);
    virtual void execute(Miner* pMiner);
    
private:
    QuenchThirst() {}
};


#endif /* defined(__test226__QuenchThirst__) */
