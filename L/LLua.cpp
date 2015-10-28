//
//  LLua.cpp
//  Pooyan
//
//  Created by Liao on 15/10/27.
//
//

#include "LLua.hpp"
#include "cocos2d.h"
USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma comment(lib,"lua.lib")
#pragma comment(lib,"tolualib.lib")
#endif

int tolua_LSpriteLua_open (lua_State* tolua_S);
int tolua_LWindowLua_open (lua_State* tolua_S);
int tolua_LSceneLua_open (lua_State* tolua_S);
int tolua_LuaFunction_open (lua_State* tolua_S);

void register_luabinding(lua_State *lua_state){
    tolua_LSpriteLua_open(lua_state);
    tolua_LWindowLua_open(lua_state);
    tolua_LSceneLua_open(lua_state);
    tolua_LuaFunction_open(lua_state);
}


//static int lua_callback = LUA_REFNIL;
//static int setnotify(lua_State *L)
//{
//    lua_callback = luaL_ref(L, LUA_REGISTRYINDEX);
//    return 0;
//}
//static int testnotify(lua_State *L)
//{
//    lua_rawgeti(L, LUA_REGISTRYINDEX, lua_callback);
//     lua_call(L, 0, 0);
//    return 0;
//}
//static int testenv(lua_State *L)
//{
//    lua_getglobal(L, "defcallback");
//    lua_call(L, 0, 0);
//    return 0;
//}
//static const luaL_Reg cblib[] = {
//    {"setnotify", setnotify},
//    {"testnotify", testnotify},
//    {"testenv", testenv},
//    {NULL, NULL}
//};
//int luaopen_cb(lua_State *L)
//{
//    lua_register(L, "cb", cblib);
//    //    luaL_register(L, "cb", cblib);
//    return 1;
//}


LLua* LLua::m_instance = nullptr;

LLua::LLua(){
    //    lua_State *lua_state;
        m_state = luaL_newstate();
    //    //2.设置待注册的Lua标准库，这个库是给你的Lua脚本用的
    //    //因为接下来我们只想在Lua脚本里面输出hello world，所以只引入基本库就可以了
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
            luaL_requiref(m_state, lib->name, lib->func, 1);
            lua_pop(m_state, 1);
        }
    //
    //    //注册luabing
        register_luabinding(m_state);
    //
        std::string projectPath;
        std::string scriptPath;
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
        scriptPath = FileUtils::getInstance()->fullPathForFilename("scripts/hello.lua");
    #endif
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
        projectPath = "/Users/liao/Documents/Cocos2d-x/LuaProject/ZhuZi";
    #endif
        FileUtils::getInstance()->addSearchPath(projectPath+"/zhuzi_scripts");
        FileUtils::getInstance()->addSearchPath(projectPath+"/images");
//        scriptPath = FileUtils::getInstance()->fullPathForFilename("hello.lua");
//    
//    
//        luaL_dofile(lua_state, scriptPath.c_str());
    //
    //    Director::getInstance()->getScheduler()->schedule([=](float delta){
    //        lua_getglobal(lua_state, "CocosUpdate");
    //        lua_pushnumber(lua_state, delta);
    //        lua_call(lua_state,1, 0);
    //    }, Director::getInstance(), 1.0f, false, "CocosUpdate");

}

LLua::~LLua(){
    
}

void LLua::doFile(std::string path){
    auto scriptPath = FileUtils::getInstance()->fullPathForFilename(path);
    luaL_dofile(m_state, scriptPath.c_str());
}

LLua* LLua::getInstance(){
    if(m_instance == nullptr){
        m_instance = new LLua();
    }
    return m_instance;
}