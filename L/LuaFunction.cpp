//
//  lua_value.cpp
//  Pooyan
//
//  Created by Liao on 15/10/27.
//
//

#include "LuaFunction.hpp"

LuaFunction::LuaFunction( lua_State* L, int index ): m_L(L)
{
    m_ref = luaL_ref( m_L, index );
}

LuaFunction::~LuaFunction()
{
    if (m_L && m_ref != 0)
    {
        luaL_unref(m_L,LUA_REGISTRYINDEX,m_ref);
    }
}

bool LuaFunction::Validate()
{
    if (!m_L)
    {
        return false;
    }
    push();
    bool v = lua_isfunction(m_L,-1);
    lua_pop(m_L,1);
    return v;
}



int LuaFunction::Call()
{
    if (!Validate())
    {
        return -1;
    }
    int status = -1;
    push();
    if( lua_isfunction( m_L, -1 ) )
    {
        status = lua_pcall(m_L, 0, 1,NULL);
    }
    lua_pop(m_L, 1);
    return status;
}

void LuaFunction::registerValue()
{
    m_ref = luaL_ref( m_L, LUA_REGISTRYINDEX );  //2为参数索引号，如果调用函数中包括其他参数，需要根据实际需要修改
}