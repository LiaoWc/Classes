/*
 ** Lua binding: Level1SceneLua
 */

#include "tolua.h"

#ifndef __cplusplus
#include <stdlib.h>
#endif
#ifdef __cplusplus
extern "C" int tolua_bnd_takeownership (lua_State* L); // from tolua_map.c
#else
int tolua_bnd_takeownership (lua_State* L); /* from tolua_map.c */
#endif
#include <string.h>

/* Exported function */
TOLUA_API int tolua_Level1SceneLua_open (lua_State* tolua_S);
LUALIB_API int luaopen_Level1SceneLua (lua_State* tolua_S);

#include "Level1Scene.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Level1Scene");
    tolua_usertype(tolua_S,"Scene");
}

/* method: new of class  Level1Scene */
static int tolua_Level1SceneLua_Level1Scene_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"Level1Scene",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        {
            Level1Scene* tolua_ret = (Level1Scene*)  new Level1Scene();
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"Level1Scene");
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
    return 0;
#endif
}

/* method: printScene of class  Level1Scene */
static int tolua_Level1SceneLua_Level1Scene_printScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"Level1Scene",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        Level1Scene* self = (Level1Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'printScene'",NULL);
#endif
        {
            self->printScene();
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'printScene'.",&tolua_err);
    return 0;
#endif
}

/* method: setCallFunc of class  Level1Scene */
static int tolua_Level1SceneLua_Level1Scene_setCallFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"Level1Scene",0,&tolua_err) ||
        !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        Level1Scene* self = (Level1Scene*)  tolua_tousertype(tolua_S,1,0);
        int nHandler = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCallFunc'",NULL);
#endif
        {
            self->setCallFunc(nHandler);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setCallFunc'.",&tolua_err);
    return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_Level1SceneLua (lua_State* tolua_S)
{
    tolua_open(tolua_S);
    tolua_reg_types(tolua_S);
    tolua_module(tolua_S,NULL,0);
    tolua_beginmodule(tolua_S,NULL);
    tolua_cclass(tolua_S,"Level1Scene","Level1Scene","Scene",NULL);
    tolua_beginmodule(tolua_S,"Level1Scene");
    tolua_function(tolua_S,"new",tolua_Level1SceneLua_Level1Scene_new00);
    tolua_function(tolua_S,"printScene",tolua_Level1SceneLua_Level1Scene_printScene00);
    tolua_function(tolua_S,"setCallFunc",tolua_Level1SceneLua_Level1Scene_setCallFunc00);
    tolua_endmodule(tolua_S);
    tolua_endmodule(tolua_S);
    return 1;
}
/* Open tolua function */
TOLUA_API int tolua_Level1SceneLua_open (lua_State* tolua_S)
{
    lua_pushcfunction(tolua_S, luaopen_Level1SceneLua);
    lua_pushstring(tolua_S, "Level1SceneLua");
    lua_call(tolua_S, 1, 0);
    return 1;
}
