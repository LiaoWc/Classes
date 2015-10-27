//
//  Box2dManager.cpp
//  Pooyan
//
//  Created by Liao on 15/10/7.
//
//

#include "Box2dManager.hpp"
Box2dWorld* Box2dManager::m_worldList = nullptr;

Box2dWorld* Box2dManager::createWorld(){
    Box2dWorld* world = new Box2dWorld();
    m_worldList = world;
    return world;
}


