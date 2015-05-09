//
//  MessageType.h
//  Learn36
//
//  Created by DONG on 15/5/9.
//
//

#ifndef Learn36_MessageType_h
#define Learn36_MessageType_h

enum MessageType
{
    Msg_ImHome,
    Msg_StewReady,
    Msg_BeHit,
};

struct Telegram
{
    int sender;
    int receiver;
    MessageType msgType;
    void* extraInfo;
    int extraInt;
    
    Telegram() {}
    Telegram(int _sender, int _receiver, MessageType _msgType, void* _extraInfo = nullptr) :
    sender(_sender), receiver(_receiver), msgType(_msgType), extraInfo(_extraInfo)
    {
        
    }
    
};

#endif
