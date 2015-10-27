//
//  LWindow.cpp
//  Pooyan
//
//  Created by Liao on 15/10/25.
//
//

#include "LWindow.hpp"
LWindow* LWindow::m_instance = nullptr;
LWindow* LWindow::getInstance(){
    if(m_instance == nullptr){
        m_instance = new LWindow();
    }
    return m_instance;
}
LWindow::LWindow()
{
    isInitScreen = false;
    isFullScreen = false;
}
LWindow::~LWindow(){
    
}

float LWindow::getWidth(){
    return Director::getInstance()->getVisibleSize().width;
};

float LWindow::getHeight(){
    return Director::getInstance()->getVisibleSize().height;
};

void LWindow::initWindowWithSize(float width,float height){
    if(isInitScreen){
        return;
    }
    isInitScreen = true;
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("Pooyan", Rect(0, 0, width/2, height/2));
#else
        glview = GLViewImpl::create("Pooyan");
        
#endif
        director->setOpenGLView(glview);
    }
}

void LWindow::initWindowWithFullScreen(){
    if(isInitScreen){
        return;
    }
    isInitScreen = true;
    isFullScreen = true;
};

void LWindow::setDisplayStats(bool b){
    Director::getInstance()->setDisplayStats(b);
};
void LWindow::setAnimationInterval(float f){
    Director::getInstance()->setAnimationInterval(f);
};
void LWindow::setDesignResolutionSize(float width ,float height,int r){
    Director::getInstance()->getOpenGLView()->setDesignResolutionSize(width,height,ResolutionPolicy(r));
};
void LWindow::runWithScene(cocos2d::Scene *s){
    Director::getInstance()->runWithScene(s);
}
Scene* LWindow::getRunningScene(){
    return Director::getInstance()->getRunningScene();
}

