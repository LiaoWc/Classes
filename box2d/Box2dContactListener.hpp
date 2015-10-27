//
//  Box2dContactListener.hpp
//  Pooyan
//
//  Created by Liao on 15/10/9.
//
//

#ifndef Box2dContactListener_hpp
#define Box2dContactListener_hpp
#include "external/Box2D/Box2D.h"
class Box2dContactListener:public b2ContactListener
{
public:
    void BeginContactProc(b2Fixture* fixture);
    
    void BeginContact(b2Contact* contact);
};

#endif /* Box2dContactListener_hpp */
