//
//  Box2dContactListener.cpp
//  Pooyan
//
//  Created by Liao on 15/10/9.
//
//

#include "Box2dContactListener.hpp"
#include "cocos2d.h"
USING_NS_CC;
void Box2dContactListener::BeginContactProc(b2Fixture* fixture){
    if(fixture->GetFilterData().groupIndex == -1){
        b2Body * body = fixture->GetBody();
        EventCustom event("destroyBody");
        event.setUserData(body);
        Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
    }
}

void Box2dContactListener::BeginContact(b2Contact* contact) {
    B2_NOT_USED(contact);
    BeginContactProc(contact->GetFixtureA());
    BeginContactProc(contact->GetFixtureB());
}
