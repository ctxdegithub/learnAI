//
//  MessageDispatcher.h
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#ifndef __Learn36__MessageDispatcher__
#define __Learn36__MessageDispatcher__

#include "../Message/Message.h"
#include <set>
using namespace std;

struct MessageData
{
    int priority;
    float delay;
    float endTime;
    Telegram msgInfo;
    
    bool operator<(const MessageData& msg) const
    {
        if (priority == msg.priority)
        {
            return delay < msg.delay;
        }
        return priority > msg.priority;
    }
    
};

class BaseGameEntity;
class MessageDispatcher
{
public:
    static MessageDispatcher* getInstance();
    void dispatchMessage(const Telegram& msg, int priority = 0, float delay = 0);
    void dispatchMessage(int sender, int receiver, MessageType msgType, void *extraInfo = nullptr, int priority = 0, float delay = 0);
    
    void update(float dt);
    
private:
    MessageDispatcher() { m_curTime = 0.f; }
    void dispatchMessage(BaseGameEntity* receiver, const Telegram& msg);
    
private:
    float m_curTime;
    std::set<MessageData> m_msgQueue;
};

#define MSGMANAGER MessageDispatcher::getInstance()

#endif /* defined(__Learn36__MessageDispatcher__) */
