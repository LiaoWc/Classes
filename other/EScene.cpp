//
//  EScene.cpp
//  Pooyan
//
//  Created by Liao on 15/10/16.
//
//

#include "json/rapidjson.h"
#include "json/document.h"
//Json

#include "EScene.hpp"
//using namespace  cocos2d::network;
//
//class WebSocketDelegate:public WebSocket::Delegate{
//public:
//    WebSocketDelegate(){};
//    ~WebSocketDelegate(){};
//    void onOpen(WebSocket* ws);
//    void onMessage(WebSocket* ws, const WebSocket::Data& data);
//    void onClose(WebSocket* ws);
//    void onError(WebSocket* ws, const WebSocket::ErrorCode& error);
//};
//void WebSocketDelegate::onOpen(WebSocket *ws){
//    CCLOG("onOpen");
//}
//
//void WebSocketDelegate::onMessage(WebSocket* ws, const WebSocket::Data& data){
//    CCLOG("onMessage");
//    
//    std::string str = data.bytes;
//    CCLOG("%s\n", str.c_str());
//    rapidjson::Document d;
//    d.Parse<0>(str.c_str());
//    if (d.HasParseError())  //打印解析错误
//    {
//        CCLOG("GetParseError %u\n",d.GetParseError());
//    }
//    if(d.IsArray()){
////        const rapidjson::Value &pArray = _doc["entities"];
//    }
//    if (d.IsObject()) {
//        const rapidjson::Value &pArray = d["images"];
//        for (rapidjson::SizeType i = 0; i < pArray.Size(); i++)
//        {
//            const rapidjson::Value &p = pArray[i];
//            std::string ss = p.GetString();
//            CCLOG("%s",ss.c_str());
//        }
////        CCLOG("%s\n", d["hello"].GetString());//打印获取hello的值
//    }
//    
//    ;
//}
//
//void WebSocketDelegate::onClose(WebSocket *ws){
//    CCLOG("onClose");
//}
//
//void WebSocketDelegate::onError(WebSocket* ws, const WebSocket::ErrorCode& error){
//    CCLOG("onError");
//}

void EScene::set(){
    
}

void EScene::onEnter(){
    Layer::onEnter();
    auto design_size = Size(1920,1080);
    setScale(0.9);
    setContentSize(design_size);
    //外框
    {
        auto draw = DrawNode::create();
        draw->drawRect(Vec2(0,0), Vec2(design_size.width,design_size.height), Color4F(1,0,0,1));
        addChild(draw,100);
    }
    //分辨率文字
    {
        
        TTFConfig ttfConfig("arial.ttf", 50, GlyphCollection::DYNAMIC,nullptr,true);
        // Green
        char str[32] = "";
        sprintf(str, "%d x %d",(int)design_size.width,(int)design_size.height);
        auto label = Label::createWithTTF(ttfConfig,str, TextHAlignment::CENTER, design_size.width);
        label->setAnchorPoint(Vec2(0.5,0));
        //        label->setVerticalAlignment(TextVAlignment::TOP);
        label->setPosition(design_size.width/2,design_size.height);
        label->setTextColor( Color4B::WHITE );
        //        label->setScale(sprite_frame_width/label->getContentSize().width);
        addChild(label);
        //        FileUtils::getInstance()->
    }
//    {
//        auto spr = Sprite::create("/Users/liao/test.png");
//        addChild(spr);
//    }
    
//    WebSocketDelegate* wd = new WebSocketDelegate();
//    auto socket = new network::WebSocket();
//    socket->init(*wd, "ws://127.0.0.1:9000");
}