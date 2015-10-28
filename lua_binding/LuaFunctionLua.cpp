/*
** Lua binding: LuaFunction
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
TOLUA_API int tolua_LuaFunction_open (lua_State* tolua_S);
LUALIB_API int luaopen_LuaFunction (lua_State* tolua_S);

#include "LuaFunction.hpp"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"LuaFunction");
}

/* method: new of class  LuaFunction */
static int tolua_LuaFunction_LuaFunction_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"LuaFunction",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  LuaFunction* tolua_ret = (LuaFunction*)  new LuaFunction(tolua_S);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaFunction");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: registerValue of class  LuaFunction */
static int tolua_LuaFunction_LuaFunction_registerValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaFunction",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaFunction* self = (LuaFunction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerValue'",NULL);
#endif
 {
  self->registerValue();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerValue'.",&tolua_err);
 return 0;
#endif
}

/* method: Call of class  LuaFunction */
static int tolua_LuaFunction_LuaFunction_Call00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaFunction",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaFunction* self = (LuaFunction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Call'",NULL);
#endif
 {
  self->Call();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Call'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_LuaFunction (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"LuaFunction","LuaFunction","",NULL);
 tolua_beginmodule(tolua_S,"LuaFunction");
 tolua_function(tolua_S,"new",tolua_LuaFunction_LuaFunction_new00);
 tolua_function(tolua_S,"registerValue",tolua_LuaFunction_LuaFunction_registerValue00);
 tolua_function(tolua_S,"Call",tolua_LuaFunction_LuaFunction_Call00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_LuaFunction_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_LuaFunction);
 lua_pushstring(tolua_S, "LuaFunction");
 lua_call(tolua_S, 1, 0);
 return 1;
}
