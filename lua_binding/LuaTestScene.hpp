//
//  LuaTestScene.hpp
//  Pooyan
//
//  Created by Liao on 15/10/20.
//
//

#ifndef LuaTestScene_hpp
#define LuaTestScene_hpp

#include "cocos2d.h"
USING_NS_CC;

class LuaTestScene : public Scene
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(LuaTestScene);
    void onEnter();
//    cocos2d::SpriteBatchNode* CreateCaoPing();
//    void update(float delta);
//    void sendToLua();
//    void setCallFunc(int handler){
//        m_handler = handler;
//    };
//    void printScene(){
//        CCLOG("hellp tolua");
//    };
    
private:
//    int m_handler;
//    void createWorld();
//    Box2dWorld* m_world;
};

#endif /* LuaTestScene_hpp */
