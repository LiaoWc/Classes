#include "AppDelegate.h"
//#include "ZZScene.hpp"
//#include "SceneEditor.hpp"
//#include "BlendEditor.hpp"
//#include "Level1Scene.h"
#include "LuaTestScene.hpp"


#include "lua.hpp"
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

int tolua_LSpriteLua_open (lua_State* tolua_S);
int tolua_LWindowLua_open (lua_State* tolua_S);


USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(1920, 1544);
//static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
//static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
//static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate() {
    
}

AppDelegate::~AppDelegate()
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    
    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages,
// don't modify or remove this function
//static int register_all_packages()
//{
//    return 0; //flag for packages manager
//}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
//    auto glview = director->getOpenGLView();
//    if(!glview) {
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
//        glview = GLViewImpl::createWithRect("Pooyan", Rect(0, 0, designResolutionSize.width/2, designResolutionSize.height/2));
//        //        glview->setFrameZoomFactor(0.6);
//        //        glview = GLViewImpl::createWithFullScreen("");
//        
//#else
//        glview = GLViewImpl::create("Pooyan");
//        
//#endif
//        director->setOpenGLView(glview);
////        director->init();
////         glview = GLViewImpl::createWithFullScreen("");
////        director->setOpenGLView(glview);
//    }
    
    // turn on display FPS
//    director->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
//    director->setAnimationInterval(1.0 / 60);
    
    // Set the design resolution
//    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::FIXED_HEIGHT);
//    Size frameSize = glview->getFrameSize();
    CCLOG("hello");
//    Director::getInstance()->getConsole()->setBindAddress("127.0.0.1");
//    Director::getInstance()->getConsole()->listenOnTCP(9001);
    
    FileUtils::getInstance()->addSearchPath("/Users/liao/Documents/Cocos2d-x/LuaProject/ZhuZi/images");
    FileUtils::getInstance()->addSearchPath("/Users/liao/Documents/Cocos2d-x/LuaProject/ZhuZi/scripts");

    
    
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
    tolua_LSpriteLua_open(lua_state);
    tolua_LWindowLua_open(lua_state);
    
    std::string scriptPath = FileUtils::getInstance()->fullPathForFilename("hello.lua");
    
    //    int status = luaL_loadfile(lua_state, scriptPath.c_str());
    //    lua_register(lua_state, "average", average);
    
    luaL_dofile(lua_state, scriptPath.c_str());
    
//    Director::getInstance()->getScheduler()->schedule([=](float delta){
//        lua_getglobal(lua_state, "CocosUpdate");
//        lua_pushnumber(lua_state, delta);
//        lua_call(lua_state,1, 0);
//    }, Director::getInstance(), 1.0f, false, "CocosUpdate");

    
//    register_all_packages();
    
    //  FileUtils::getInstance()->addSearchPath("fonts");
    
    // run
    director->runWithScene(Scene::create());
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
