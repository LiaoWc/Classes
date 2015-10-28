//
//  LWebSocket.cpp
//  Pooyan
//
//  Created by Liao on 15/10/28.
//
//

#include "LWebSocket.hpp"
LWebSocket* LWebSocket::m_instance = nullptr;
LWebSocket* LWebSocket::getInstance(){
    if(m_instance == nullptr){
        m_instance = new LWebSocket();
    }
    return m_instance;
}

LWebSocket::LWebSocket(){
    m_delegate = new WebSocketDelegate();
}


LWebSocket::~LWebSocket(){
    
}

void LWebSocket::connect(){
    m_socket = new network::WebSocket();
    m_socket->init(*m_delegate, "ws://127.0.0.1:9000");
}

void LWebSocket::setOnOpen(function<void ()> cb){
    m_func_onOpen = cb;
}
void LWebSocket::setOnMessage(function<void (const WebSocket::Data &)> cb){
    m_func_onMessage = cb;
}
void LWebSocket::setOnClose(function<void ()> cb){
    m_func_onClose = cb;
}
void LWebSocket::setOnError(function<void (const WebSocket::ErrorCode &)> cb){
    m_func_onError = cb;
}

void LWebSocket::onOpen(){
    if(m_func_onOpen != nullptr){
        m_func_onOpen();
    }
}

void LWebSocket::onMessage(const WebSocket::Data& data){
//    std::string str = data.bytes;
//    CCLOG("%s\n", str.c_str());
    if(m_func_onMessage != nullptr){
        m_func_onMessage(data);
    }
}
void LWebSocket::onClose(){
    if(m_func_onClose != nullptr){
        m_func_onClose();
    }

}
void LWebSocket::onError(const WebSocket::ErrorCode& error){
    if(m_func_onError != nullptr){
        m_func_onError(error);
    }

}

void LWebSocket::send(string s){
    if(m_socket->getReadyState() == WebSocket::State::OPEN){
        m_socket->send(s);
    }
}

void WebSocketDelegate::onOpen(WebSocket *ws){
    LWebSocket::getInstance()->onOpen();
//    CCLOG("onOpen");
}

void WebSocketDelegate::onMessage(WebSocket* ws, const WebSocket::Data& data){
//    CCLOG("onMessage");
    LWebSocket::getInstance()->onMessage(data);
    //    rapidjson::Document d;
    //    d.Parse<0>(str.c_str());
    //    if (d.HasParseError())  //打印解析错误
    //    {
    //        CCLOG("GetParseError %u\n",d.GetParseError());
    //    }
    //    if(d.IsArray()){
    //        //        const rapidjson::Value &pArray = _doc["entities"];
    //    }
    //    if (d.IsObject()) {
    //        const rapidjson::Value &pArray = d["images"];
    //        for (rapidjson::SizeType i = 0; i < pArray.Size(); i++)
    //        {
    //            const rapidjson::Value &p = pArray[i];
    //            std::string ss = p.GetString();
    //            CCLOG("%s",ss.c_str());
    //        }
    //        //        CCLOG("%s\n", d["hello"].GetString());//打印获取hello的值
    //    }
    
    ;
}

void WebSocketDelegate::onClose(WebSocket *ws){
    LWebSocket::getInstance()->onClose();
}

void WebSocketDelegate::onError(WebSocket* ws, const WebSocket::ErrorCode& error){
    LWebSocket::getInstance()->onError(error);
}