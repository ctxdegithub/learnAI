//
//  StateMachine.h
//  test226
//
//  Created by DONG on 15/5/8.
//
//

#ifndef __test226__StateMachine__
#define __test226__StateMachine__

#include "State.h"
#include "cocos2d.h"

template <class entity_type>
class StateMachine
{
public:
    
    StateMachine(entity_type* owner) :
    m_pOwner(owner),
    m_pCurrentState(nullptr),
    m_pPreviousState(nullptr),
    m_pGlobalState(nullptr)
    {
        
    }
    
    void update(float dt)
    {
        if (m_pCurrentState)
        {
            m_pCurrentState->execute(m_pOwner);
        }
        
//        if (m_pGlobalState)
//        {
//            m_pGlobalState->execute(m_pOwner);
//        }
    }
    
    void changeState(State<entity_type> *pNewState)
    {
        assert(pNewState && "<StateMachine::changeState>: trying to change to a null state.");
        m_pPreviousState = m_pCurrentState;
        m_pCurrentState->onExit(m_pOwner);
        m_pCurrentState = pNewState;
        m_pCurrentState->onEnter(m_pOwner);
    }
    
    void revertToPreviousState()
    {
        changeState(m_pPreviousState);
    }
    
    bool isInState(State<entity_type>* pState)
    {
        return m_pCurrentState == pState;
    }
    
private:
    entity_type* m_pOwner;
    CC_SYNTHESIZE(State<entity_type>*, m_pCurrentState, CurrentState);
    CC_SYNTHESIZE(State<entity_type>*, m_pPreviousState, PreviousState);
    CC_SYNTHESIZE(State<entity_type>*, m_pGlobalState, GlobalState);
};

#endif /* defined(__test226__StateMachine__) */
