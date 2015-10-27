//
//  LSprite.cpp
//  Pooyan
//
//  Created by Liao on 15/10/20.
//
//

#include "LSprite.hpp"

LSprite::LSprite(const std::string image){
    m_sprite = Sprite::create(image);
}

void LSprite::setWithJson(const std::string json){
    CCLOG("setWithJson:%s",json.c_str());
    setParent(Director::getInstance()->getRunningScene());
}

void LSprite::setParent(cocos2d::Node *parent){
    if(nullptr != m_sprite){
        parent->addChild(m_sprite);
    }
    
}

LSprite::~LSprite(){
    
}