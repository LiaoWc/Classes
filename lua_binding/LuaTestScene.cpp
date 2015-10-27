//
//  LuaTestScene.cpp
//  Pooyan
//
//  Created by Liao on 15/10/20.
//
//

#include "LuaTestScene.hpp"

#include "lua.hpp"
#include "LWindow.hpp"


USING_NS_CC;
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

int tolua_LSpriteLua_open (lua_State* tolua_S);
int tolua_LWindowLua_open (lua_State* tolua_S);

void LuaTestScene::onEnter(){
    Scene::onEnter();
    
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
    
    Director::getInstance()->getScheduler()->schedule([=](float delta){
        lua_getglobal(lua_state, "CocosUpdate");
        lua_pushnumber(lua_state, delta);
        lua_call(lua_state,1, 0);
    }, Director::getInstance(), 0.0f, false, "CocosUpdate");

//    lua_pushnumber(lua_state, 1);
//    lua_pushstring(lua_state, "cb");
//    lua_call(lua_state,2, 1);
    
    
}