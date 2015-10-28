/*
** Lua binding: LWindowLua
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
TOLUA_API int tolua_LWindowLua_open (lua_State* tolua_S);
LUALIB_API int luaopen_LWindowLua (lua_State* tolua_S);

#include "LWindow.hpp"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"LWindow");
}

/* method: getInstance of class  LWindow */
static int tolua_LWindowLua_LWindow_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"LWindow",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  LWindow* tolua_ret = (LWindow*)  LWindow::getInstance();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"LWindow");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}

/* method: getWidth of class  LWindow */
static int tolua_LWindowLua_LWindow_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LWindow",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LWindow* self = (LWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'",NULL);
#endif
 {
  float tolua_ret = (float)  self->getWidth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}

/* method: getHeight of class  LWindow */
static int tolua_LWindowLua_LWindow_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LWindow",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LWindow* self = (LWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'",NULL);
#endif
 {
  float tolua_ret = (float)  self->getHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}

/* method: initWindowWithSize of class  LWindow */
static int tolua_LWindowLua_LWindow_initWindowWithSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LWindow",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LWindow* self = (LWindow*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWindowWithSize'",NULL);
#endif
 {
  self->initWindowWithSize(width,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWindowWithSize'.",&tolua_err);
 return 0;
#endif
}

/* method: initWindowWithFullScreen of class  LWindow */
static int tolua_LWindowLua_LWindow_initWindowWithFullScreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LWindow",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LWindow* self = (LWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWindowWithFullScreen'",NULL);
#endif
 {
  self->initWindowWithFullScreen();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWindowWithFullScreen'.",&tolua_err);
 return 0;
#endif
}

/* method: setDisplayStats of class  LWindow */
static int tolua_LWindowLua_LWindow_setDisplayStats00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LWindow",0,&tolua_err) || 
 !tolua_isboolean(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LWindow* self = (LWindow*)  tolua_tousertype(tolua_S,1,0);
  bool b = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDisplayStats'",NULL);
#endif
 {
  self->setDisplayStats(b);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDisplayStats'.",&tolua_err);
 return 0;
#endif
}

/* method: setAnimationInterval of class  LWindow */
static int tolua_LWindowLua_LWindow_setAnimationInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LWindow",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LWindow* self = (LWindow*)  tolua_tousertype(tolua_S,1,0);
  float f = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimationInterval'",NULL);
#endif
 {
  self->setAnimationInterval(f);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimationInterval'.",&tolua_err);
 return 0;
#endif
}

/* method: setDesignResolutionSize of class  LWindow */
static int tolua_LWindowLua_LWindow_setDesignResolutionSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LWindow",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LWindow* self = (LWindow*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  int resolutionPolicy = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDesignResolutionSize'",NULL);
#endif
 {
  self->setDesignResolutionSize(width,height,resolutionPolicy);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDesignResolutionSize'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_LWindowLua (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"LWindow","LWindow","",NULL);
 tolua_beginmodule(tolua_S,"LWindow");
 tolua_function(tolua_S,"getInstance",tolua_LWindowLua_LWindow_getInstance00);
 tolua_function(tolua_S,"getWidth",tolua_LWindowLua_LWindow_getWidth00);
 tolua_function(tolua_S,"getHeight",tolua_LWindowLua_LWindow_getHeight00);
 tolua_function(tolua_S,"initWindowWithSize",tolua_LWindowLua_LWindow_initWindowWithSize00);
 tolua_function(tolua_S,"initWindowWithFullScreen",tolua_LWindowLua_LWindow_initWindowWithFullScreen00);
 tolua_function(tolua_S,"setDisplayStats",tolua_LWindowLua_LWindow_setDisplayStats00);
 tolua_function(tolua_S,"setAnimationInterval",tolua_LWindowLua_LWindow_setAnimationInterval00);
 tolua_function(tolua_S,"setDesignResolutionSize",tolua_LWindowLua_LWindow_setDesignResolutionSize00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_LWindowLua_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_LWindowLua);
 lua_pushstring(tolua_S, "LWindowLua");
 lua_call(tolua_S, 1, 0);
 return 1;
}
