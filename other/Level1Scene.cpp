#include "Level1Scene.h"

#include "lua.hpp"
USING_NS_CC;
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

int tolua_Level1SceneLua_open (lua_State*);
void Level1Scene::onEnter(){
    Scene::onEnter();
    //    auto bg = LayerColor::create(Color4B(32,0,176,255));
    //    this->addChild(bg);
    auto size = Director::getInstance()->getVisibleSize();
    
    
    lua_State *lua_state;
    lua_state = luaL_newstate();
    //2.设置待注册的Lua标准库，这个库是给你的Lua脚本用的
    //因为接下来我们只想在Lua脚本里面输出hello world，所以只引入基本库就可以了
    static const luaL_Reg lualibs[] =
    {
        { "base", luaopen_base },
        {"debug", luaopen_debug},
        {"string",luaopen_string},
        { NULL, NULL}
    };
    //3.注册Lua标准库并清空栈
    const luaL_Reg *lib = lualibs;
    for(; lib->func != NULL; lib++)
    {
        luaL_requiref(lua_state, lib->name, lib->func, 1);
        lua_pop(lua_state, 1);
    }
    //4、运行hello.lua脚本
    tolua_Level1SceneLua_open(lua_state);
    std::string scriptPath = FileUtils::getInstance()->fullPathForFilename("hello.lua");
    
    //    int status = luaL_loadfile(lua_state, scriptPath.c_str());
//    lua_register(lua_state, "average", average);
    
    luaL_dofile(lua_state, scriptPath.c_str());
    
    int n = lua_getglobal(lua_state, "CocosCallBack");
    lua_pushnumber(lua_state, 1);
    lua_pushstring(lua_state, "cb");
    lua_call(lua_state,2, 1);

//    lua_CFunction handler = lua_tocfunction(lua_state, 1);
//    lua_pop(lua_state,1);
//    lua_function
//    lua_state->pushString("this is lua cb!");
//    stack->executeFunctionByHandler(m_handler, 1);
//    stack->clean();
    //    5. 关闭Lua虚拟机
//    lua_close(lua_state);
    
    
    m_world = Box2dManager::createWorld();
    
    m_world->setDebugNode(this);
    //    m_world->setWorldSize(b2Vec2(size.width,size.height));
    //    m_world->addPlayerBody();
    //    m_world->addWallBody();
    //    m_world->addBallBody(Vec2(size.width/2,size.height/2));
    //    m_world->addBoxBody(Vec2(size.width/2 - 100,size.height/2));
    
    
    this->scheduleUpdate();
    
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    auto ed = Director::getInstance()->getEventDispatcher();
    listener1->onTouchBegan = [this](Touch* touch, Event* event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode))
        {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            //            target->setScale(1.9);
            //            m_world->addBallBody(Vec2(0,0));
            return true;
        }
        return false;
    };
    //    listener1->onTouchEnded = [=](Touch* touch, Event* event){
    //        auto target = static_cast<Sprite*>(event->getCurrentTarget());
    //        target->setScale(2);
    //        log("sprite onTouchesEnded.. ");
    //    };
    
    ed->addEventListenerWithSceneGraphPriority(listener1, this);
    //        b2Body* body = m_world->GetBodyList();
    //    for( b2Body* b = m_world->GetBodyList();b != nullptr;b=b->GetNext()){
    //        CCLOG("%f",b->GetPosition().y);
    //    }
    
}


SpriteBatchNode* Level1Scene::CreateCaoPing(){
    auto size = Director::getInstance()->getVisibleSize();
    //地草皮
    auto node = SpriteBatchNode::create("level1_4.png");
    int caopingSize = ceil(size.width/103) ;
    //    CCLOG("%d,%f",caopingSize,size.width/103);
    for (int i =0;i<caopingSize;i++){
        auto spr = Sprite::create("level1_4.png");
        spr->setAnchorPoint(Vec2(0,0));
        node->addChild(spr);
        spr->setPosition(i*103,0);
    }
    this->addChild(node,1);
    return node;
    //    level1_4->initWithFile("level1_4.png", Rect(0,0,size.width,size.height));
    //    level1_4->setAnchorPoint(Vec2(0,0));
    //    this->addChild(level1_4);
    
}
int VELOCITY_INTERATIONS= 8;
int POSITION_INTERATIONS= 1;
float TIME_STEP= 1.0f / 60.0f;

//void Level1Scene::sendToLua(){
//    CCLuaStack* stack = CCLuaEngine::defaultEngine()->getLuaStack();
//    //        stack->pushInt(msgId);
//    stack->pushString("this is lua cb!");
//    stack->executeFunctionByHandler(m_handler, 1);
//    stack->clean();
//};

void Level1Scene::update(float delta){
    m_world->update();
    //    CCLOG("update");
    //    b2d_draw->clear();
    //    m_world->DrawDebugData();
    //    m_world->Step(TIME_STEP, VELOCITY_INTERATIONS,POSITION_INTERATIONS);
    //    for( b2Body* b = m_world->GetBodyList();b != nullptr;b=b->GetNext()){
    //
    //        if (b->GetUserData() != NULL) {
    //            CCLOG("%f",b->GetPosition().y);
    //            DrawNode* spr = (DrawNode*)  b->GetUserData();
    //            spr->setPosition(b->GetPosition().x*PTM_RATIO,b->GetPosition().y*PTM_RATIO);
    //        }
    //    }
    
}
