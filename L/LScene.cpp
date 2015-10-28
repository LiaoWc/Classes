//
//  LScene.cpp
//  Pooyan
//
//  Created by Liao on 15/10/27.
//
//

#include "LScene.hpp"
LScene::LScene(){
    m_scene = Scene::create();
}
LScene::~LScene(){
    
}

void LScene::run(){
    auto d = Director::getInstance();
    if(d->getRunningScene() == nullptr){
        d->runWithScene(m_scene);
    }else{
        d->replaceScene(m_scene);
    }
}

void LScene::addChild(LSprite * s){
    m_scene->addChild(s->getSprite());
}

void LScene::setCallBack(LuaFunction* func){
    
}