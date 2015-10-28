//
//  LWebSocket.hpp
//  Pooyan
//
//  Created by Liao on 15/10/28.
//
//

#ifndef LWebSocket_hpp
#define LWebSocket_hpp

#include "cocos2d.h"
#include "network/WebSocket.h"
USING_NS_CC;
using namespace  cocos2d::network;
using namespace  std;
class WebSocketDelegate;
class LWebSocket
{
public:
    static LWebSocket* getInstance();
    void connect();
    void send(string s);
    void close();
    void setOnOpen(function<void()>);
    void setOnMessage(function<void(const WebSocket::Data& data)>);
    void setOnClose(function<void()>);
    void setOnError(function<void(const WebSocket::ErrorCode& error)>);
    
    void onOpen();
    void onMessage(const WebSocket::Data& data);
    void onClose();
    void onError(const WebSocket::ErrorCode& error);
    
private:
    function<void()> m_func_onOpen;
    function<void(const WebSocket::Data& data)> m_func_onMessage;
    function<void(const WebSocket::ErrorCode& error)> m_func_onError;
    function<void()> m_func_onClose;
    
    LWebSocket();
    ~LWebSocket();
    static LWebSocket* m_instance;
    WebSocket* m_socket;
    WebSocketDelegate* m_delegate;
};

class WebSocketDelegate:public WebSocket::Delegate{
public:
    WebSocketDelegate(){};
    ~WebSocketDelegate(){};
    void onOpen(WebSocket* ws);
    void onMessage(WebSocket* ws, const WebSocket::Data& data);
    void onClose(WebSocket* ws);
    void onError(WebSocket* ws, const WebSocket::ErrorCode& error);
};


#endif /* LWebSocket_hpp */
