#ifndef __Level1Scene_SCENE_H__
#define __Level1Scene_SCENE_H__

#include "cocos2d.h"
#include "external/Box2d/Box2d.h"
#include "Box2dDebugDraw.hpp"
#include "Box2dWorld.hpp"
#include "Box2dManager.hpp"
USING_NS_CC;

class Level1Scene : public Scene
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(Level1Scene);
    void onEnter();
    cocos2d::SpriteBatchNode* CreateCaoPing();
    void update(float delta);
    void sendToLua();
    void setCallFunc(int handler){
        m_handler = handler;
    };
    void printScene(){
        CCLOG("hellp tolua");
    };

private:
    int m_handler;
    void createWorld();
    Box2dWorld* m_world;
};

#endif // __HELLOWORLD_SCENE_H__
