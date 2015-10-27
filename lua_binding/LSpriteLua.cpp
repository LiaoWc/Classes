/*
** Lua binding: LSpriteLua
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
TOLUA_API int tolua_LSpriteLua_open (lua_State* tolua_S);
LUALIB_API int luaopen_LSpriteLua (lua_State* tolua_S);

#include "LSprite.hpp"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"LNode");
 tolua_usertype(tolua_S,"LSprite");
 tolua_usertype(tolua_S,"cocos2d::Node");
}

/* method: new of class  LSprite */
static int tolua_LSpriteLua_LSprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"LSprite",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  char* image = ((char*)  tolua_tostring(tolua_S,2,0));
 {
  LSprite* tolua_ret = (LSprite*)  new LSprite(image);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"LSprite");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: setPosition of class  LSprite */
static int tolua_LSpriteLua_LSprite_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LSprite",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LSprite* self = (LSprite*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
 {
  self->setPosition(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}

/* method: setParent of class  LSprite */
static int tolua_LSpriteLua_LSprite_setParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LSprite",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"cocos2d::Node",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LSprite* self = (LSprite*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::Node* n = ((cocos2d::Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setParent'",NULL);
#endif
 {
  self->setParent(n);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setParent'.",&tolua_err);
 return 0;
#endif
}

/* method: setWithJson of class  LSprite */
static int tolua_LSpriteLua_LSprite_setWithJson00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LSprite",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LSprite* self = (LSprite*)  tolua_tousertype(tolua_S,1,0);
  char* json = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWithJson'",NULL);
#endif
 {
  self->setWithJson(json);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWithJson'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_LSpriteLua (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"LSprite","LSprite","LNode",NULL);
 tolua_beginmodule(tolua_S,"LSprite");
 tolua_function(tolua_S,"new",tolua_LSpriteLua_LSprite_new00);
 tolua_function(tolua_S,"setPosition",tolua_LSpriteLua_LSprite_setPosition00);
 tolua_function(tolua_S,"setParent",tolua_LSpriteLua_LSprite_setParent00);
 tolua_function(tolua_S,"setWithJson",tolua_LSpriteLua_LSprite_setWithJson00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_LSpriteLua_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_LSpriteLua);
 lua_pushstring(tolua_S, "LSpriteLua");
 lua_call(tolua_S, 1, 0);
 return 1;
}
