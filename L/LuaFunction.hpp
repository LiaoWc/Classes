//
//  lua_value.hpp
//  Pooyan
//
//  Created by Liao on 15/10/27.
//
//

#ifndef LuaFunction_hpp
#define LuaFunction_hpp

extern "C" {
#include "lualib.h"
#include "lauxlib.h"
}

class LuaFunction
{
public:
    LuaFunction(lua_State* L):m_L(L), m_ref(0){};
    LuaFunction(lua_State* L, int index);
    ~LuaFunction();
    
    void registerValue();
    void push()const
    {
        lua_rawgeti(m_L,LUA_REGISTRYINDEX,m_ref);
    }
    
public:
    int Call();
    bool Validate();
protected:
    lua_State* m_L;
    int m_ref;
};

#endif /* LuaFunction_hpp */
