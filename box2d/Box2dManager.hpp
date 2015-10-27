//
//  Box2dManager.hpp
//  Pooyan
//
//  Created by Liao on 15/10/7.
//
//

#ifndef Box2dManager_hpp
#define Box2dManager_hpp
#include "cocos2d.h"
//#include "Box2dContactListener.hpp"
#include "Box2dWorld.hpp"
#include "external/Box2d/Box2d.h"
USING_NS_CC;

class Box2dManager
{
public:
    static Box2dWorld* createWorld();
    static Box2dWorld* getWorld();
private:
    static Box2dWorld* m_worldList;
};

#endif /* Box2dManager_hpp */
