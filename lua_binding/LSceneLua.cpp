/*
** Lua binding: LSceneLua
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
TOLUA_API int tolua_LSceneLua_open (lua_State* tolua_S);
LUALIB_API int luaopen_LSceneLua (lua_State* tolua_S);

#include "LScene.hpp"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"LScene");
 tolua_usertype(tolua_S,"LSprite");
}

/* method: new of class  LScene */
static int tolua_LSceneLua_LScene_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"LScene",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  LScene* tolua_ret = (LScene*)  new LScene();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"LScene");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: run of class  LScene */
static int tolua_LSceneLua_LScene_run00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LScene",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LScene* self = (LScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'run'",NULL);
#endif
 {
  self->run();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'run'.",&tolua_err);
 return 0;
#endif
}

/* method: addChild of class  LScene */
static int tolua_LSceneLua_LScene_addChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LScene",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"LSprite",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LScene* self = (LScene*)  tolua_tousertype(tolua_S,1,0);
  LSprite* s = ((LSprite*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addChild'",NULL);
#endif
 {
  self->addChild(s);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addChild'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_LSceneLua (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"LScene","LScene","",NULL);
 tolua_beginmodule(tolua_S,"LScene");
 tolua_function(tolua_S,"new",tolua_LSceneLua_LScene_new00);
 tolua_function(tolua_S,"run",tolua_LSceneLua_LScene_run00);
 tolua_function(tolua_S,"addChild",tolua_LSceneLua_LScene_addChild00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_LSceneLua_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_LSceneLua);
 lua_pushstring(tolua_S, "LSceneLua");
 lua_call(tolua_S, 1, 0);
 return 1;
}
