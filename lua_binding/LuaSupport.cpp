//
//  LuaSupport.cpp
//  Pooyan
//
//  Created by Liao on 15/10/7.
//
//

#include "LuaSupport.hpp"
//#include "lua.hpp"
//USING_NS_CC;
//extern "C" {
//#include "lua.h"
//#include "lualib.h"
//#include "lauxlib.h"
//}
//#include "json/rapidjson.h"
//#include "json/document.h"
//Json
//std::string str = "{\"hello\" : \"word\"}";
//CCLOG("%s\n", str.c_str());
//rapidjson::Document d;
//d.Parse<0>(str.c_str());
//if (d.HasParseError())  //打印解析错误
//{
//    CCLOG("GetParseError %u\n",d.GetParseError());
//}
//
//if (d.IsObject() && d.HasMember("hello")) {
//    
//    CCLOG("%s\n", d["hello"].GetString());//打印获取hello的值
//}


//int average(lua_State *L)
//{
//    // get number of arguments
//    int n = lua_gettop(L);
//    double sum = 0;
//    int i;
//    // loop through each argument
//    for (i = 1; i <= n; i++)
//    {
//        // total the arguments
//        sum += lua_tonumber(L, i);
//    }
//    // push the average
//    lua_pushnumber(L, sum / n);
//    // push the sum
//    lua_pushnumber(L, sum);
//    // return the number of results
//    auto bg = LayerColor::create(Color4B(32,0,176,255));
//    Director::getInstance()->getRunningScene()->addChild(bg);
//
//    return 2;
//}

//    //1. 初始化Lua虚拟机
//    lua_State *lua_state;
//    lua_state = luaL_newstate();
//    //2.设置待注册的Lua标准库，这个库是给你的Lua脚本用的
//    //因为接下来我们只想在Lua脚本里面输出hello world，所以只引入基本库就可以了
//    static const luaL_Reg lualibs[] =
//    {
//        { "base", luaopen_base },
//        {"debug", luaopen_debug},
//        {"string",luaopen_string},
//        { NULL, NULL}
//    };
//    //3.注册Lua标准库并清空栈
//    const luaL_Reg *lib = lualibs;
//    for(; lib->func != NULL; lib++)
//    {
//        luaL_requiref(lua_state, lib->name, lib->func, 1);
//        lua_pop(lua_state, 1);
//    }
//    //4、运行hello.lua脚本
//    std::string scriptPath = FileUtils::getInstance()->fullPathForFilename("hello.lua");
//    //    int status = luaL_loadfile(lua_state, scriptPath.c_str());
//    lua_register(lua_state, "average", average);
//
//    luaL_dofile(lua_state, scriptPath.c_str());

//5. 关闭Lua虚拟机
//    lua_close(lua_state);
