//
//  LLua.hpp
//  Pooyan
//
//  Created by Liao on 15/10/27.
//
//

#ifndef LLua_hpp
#define LLua_hpp

#include "lua.hpp"
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class LLua
{
public:
    ~LLua();
    static LLua* getInstance();
    void getLuaState();
    void doFile(std::string path);
private:
    LLua();
    static LLua* m_instance;
    lua_State *m_state;
};

#endif /* LLua_hpp */
