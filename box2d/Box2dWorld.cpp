//
//  Box2dWorld.cpp
//  Pooyan
//
//  Created by Liao on 15/10/7.
//
//

#include "Box2dWorld.hpp"
#include "Box2dContactListener.hpp"


b2Vec2 vec2Tob2Vec2 (Vec2 p){
    return b2Vec2(p.x/PTM_RATIO,p.y/PTM_RATIO);
}

float numTob2Num(float f){
    return f/PTM_RATIO;
}


Box2dWorld::Box2dWorld(){
    
    m_world = new b2World(b2Vec2(0,0));
    m_world->SetAllowSleeping(1);
    m_world->SetWarmStarting(1);
    m_world->SetContinuousPhysics(1);
    m_world->SetSubStepping(0);
    m_contectListener = new Box2dContactListener();
    m_world->SetContactListener(m_contectListener);
    
    
    
    auto listener2 = EventListenerCustom::create("destroyBody", [this](EventCustom* event){
        b2Body* body = static_cast<b2Body*>(event->getUserData());
//        this->DestroyBody(body);
        
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener2, 1);
    
    m_destroyBody = new DestroyBody(nullptr);
    
    //    uint32 flags = 0;
    //    flags += settings->drawShapes			* b2Draw::e_shapeBit;
    //    flags += settings->drawJoints			* b2Draw::e_jointBit;
    //    flags += settings->drawAABBs			* b2Draw::e_aabbBit;
    //    flags += settings->drawCOMs				* b2Draw::e_centerOfMassBit;
    //    m_debugDraw.SetFlags(2);
    
    
    m_debugDraw = new Box2dDebugDraw();
    m_debugDraw->SetFlags(3);
    m_world->SetDebugDraw(m_debugDraw);
    
    
    
    //    m_world->CreateJoint(<#const b2JointDef *def#>)
}

Box2dWorld::~Box2dWorld(){
    delete m_world;
    delete m_debugDraw;
    delete m_contectListener;
}

void Box2dWorld::setDebugNode(Node* parent){
    m_debugDraw->setParent(parent);
    
    
//    auto listener1 = EventListenerTouchOneByOne::create();
//    listener1->setSwallowTouches(true);
//    auto ed = Director::getInstance()->getEventDispatcher();
//    listener1->onTouchBegan = [this](Touch* touch, Event* event){
//        auto target = static_cast<Scene*>(event->getCurrentTarget());
//        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
//        return this->onTouchBegan(locationInNode);
//        //        return true;
//    };
//    listener1->onTouchMoved = [this](Touch* touch, Event* event){
//        auto target = static_cast<Scene*>(event->getCurrentTarget());
//        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
//        this->onTouchMoved(locationInNode);
//    };
//    listener1->onTouchEnded = [this](Touch* touch, Event* event){
//        auto target = static_cast<Scene*>(event->getCurrentTarget());
//        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
//        this->onTouchEnded(locationInNode);
//    };
//    
//    ed->addEventListenerWithSceneGraphPriority(listener1, parent);
    
}

void Box2dWorld::addWallBody(){
    auto size = Director::getInstance()->getVisibleSize();
    
    b2BodyDef bodyDef = b2BodyDef();
    b2Body* body = m_world->CreateBody(&bodyDef);
    
    b2FixtureDef fixtureDef = b2FixtureDef();
    fixtureDef.friction = 0.5f;
    b2EdgeShape shape =b2EdgeShape();
    shape.Set(vec2Tob2Vec2(Vec2(0,0)), vec2Tob2Vec2(Vec2(size.width,0)));
    fixtureDef.shape = &shape;
    body->CreateFixture(&fixtureDef);
    shape.Set(vec2Tob2Vec2(Vec2(0,0)), vec2Tob2Vec2(Vec2(0,size.height)));
    body->CreateFixture(&fixtureDef);
    //
    //    shape.Set(vec2Tob2Vec2(Vec2(0,0)), vec2Tob2Vec2(Vec2(size.width,0)));
    //
    //    shape.Set(vec2Tob2Vec2(Vec2(0,0)), vec2Tob2Vec2(Vec2(size.width,0)));
    
    m_groundBody = body;
}
//
//void Box2dWorld::addDestroyBody(b2Body* body){
//    DestroyBody* b = new DestroyBody(body);
//    b->next = m_destroyBody;
//    m_destroyBody = b;
//}
//
//bool Box2dWorld::onTouchBegan(Vec2 p){
//    CCLOG("Box2dWorld::onTouchBegan");
//    
//    m_touchPoint = p;
//    
//    if (m_mouseJoint != nullptr)
//    {
//        return false;
//    }
//    
//    // Make a small box.
//    b2AABB aabb;
//    b2Vec2 d;
//    b2Vec2 point = vec2Tob2Vec2(p);
//    d.Set(0.001f, 0.001f);
//    aabb.lowerBound = point - d;
//    aabb.upperBound = point + d;
//    
//    // Query the world for overlapping shapes.
//    QueryCallback callback(point);
//    m_world->QueryAABB(&callback, aabb);
//    
//    if (callback.m_fixture)
//    {
//        b2Body* body = callback.m_fixture->GetBody();
//        b2MouseJointDef md;
//        md.bodyA = m_groundBody;
//        md.bodyB = body;
//        md.target = point;
//        md.maxForce = 1000.0f * body->GetMass();
//        md.collideConnected = true;
//        m_mouseJoint = (b2MouseJoint*)m_world->CreateJoint(&md);
//        
//        body->SetAwake(true);
//        return true;
//    }
//    return false;
//    
//}
//void Box2dWorld::onTouchMoved(Vec2 p){
//    m_touchPoint = p;
//    b2Vec2 point = vec2Tob2Vec2(p);
//    if (m_mouseJoint)
//    {
//        m_mouseJoint->SetTarget(point);
//    }
//}
//void Box2dWorld::onTouchEnded(Vec2 p){
//    if (m_mouseJoint)
//    {
//        m_world->DestroyJoint(m_mouseJoint);
//        m_mouseJoint = nullptr;
//    }
//}
//
//void Box2dWorld::addPlayerBody(){
//    //    b2Body* yeren;
//    b2Body* qiang;
//    auto size = Director::getInstance()->getVisibleSize();
//    //移动距离控制墙
//    {
//        
//        b2BodyDef bodyDef = b2BodyDef();
//        bodyDef.position = vec2Tob2Vec2(Vec2(size.width*0.9,0));
//        b2Body* body  = qiang = m_world->CreateBody(&bodyDef);
//        
//        b2FixtureDef fixtureDef = b2FixtureDef();
//        fixtureDef.friction = 0.5f;
//        b2EdgeShape shape =b2EdgeShape();
//        shape.Set(vec2Tob2Vec2(Vec2(0,0)), vec2Tob2Vec2(Vec2(0,size.height*0.8)));
//        fixtureDef.shape = &shape;
//        fixtureDef.isSensor = true;
//        body->CreateFixture(&fixtureDef);
//    }
//    //野人
//    {
//        b2BodyDef bodyDef = b2BodyDef();
//        bodyDef.type = b2_dynamicBody;
//        bodyDef.fixedRotation = true;
//        bodyDef.bullet = true;
//        bodyDef.linearDamping = 10.0f;
//        //    bodyDef.allowSleep = false;
//        bodyDef.position = vec2Tob2Vec2(Vec2(size.width*0.9,size.height*0.8));
//        b2Body* body= m_yerenBody = m_world->CreateBody(&bodyDef);
//        
//        b2FixtureDef fixtureDef = b2FixtureDef();
//        fixtureDef.restitution = 0.5f;
//        fixtureDef.density = 2000.0f;
//        b2CircleShape shape =b2CircleShape();
//        shape.m_radius = 20.0f / PTM_RATIO;
//        fixtureDef.shape = &shape;
//        fixtureDef.isSensor = true;
//        body->CreateFixture(&fixtureDef);
//    }
//    
//    
//    
//    b2PrismaticJointDef jointDef = b2PrismaticJointDef();
//    jointDef.collideConnected = false;
//    jointDef.enableLimit = true;
//    jointDef.lowerTranslation = -numTob2Num(size.height*0.8);
//    jointDef.upperTranslation = 0;
//    //    jointDef.localAxisA.Set(1,0);
//    jointDef.Initialize(qiang, m_yerenBody, vec2Tob2Vec2(Vec2(size.width*0.9,size.height*0.8)), b2Vec2(0,1));
//    
//    m_world->CreateJoint(&jointDef);
//    
//}
//
//void Box2dWorld::addBallBody(cocos2d::Vec2 p){
//    
//    b2BodyDef bodyDef = b2BodyDef();
//    bodyDef.type = b2_dynamicBody;
//    bodyDef.fixedRotation = true;
//    bodyDef.bullet = true;
//    //    bodyDef.linearDamping = 10.0f;
//    //    bodyDef.allowSleep = false;
//    bodyDef.position = m_yerenBody->GetPosition();
//    bodyDef.position.x -= 5;
//    b2Body* body = m_world->CreateBody(&bodyDef);
//    
//    b2FixtureDef fixtureDef = b2FixtureDef();
//    fixtureDef.restitution = 0.5f;
//    fixtureDef.density = 20.0f;
//    b2CircleShape shape =b2CircleShape();
//    shape.m_radius = 10.0f / PTM_RATIO;
//    fixtureDef.shape = &shape;
//    b2Filter filter = b2Filter();
//    filter.groupIndex = -1;
//    fixtureDef.filter = filter;
//    
//    body->CreateFixture(&fixtureDef);
//    body->ApplyLinearImpulse(b2Vec2(-200,0), body->GetWorldCenter(), true);
//    
//    
//    //
//    //
//    //    b2PrismaticJointDef jointDef = b2PrismaticJointDef();
//    //    jointDef.enableLimit = true;
//    //    jointDef.lowerTranslation = 0;
//    //    jointDef.upperTranslation = 10;
//    //    //    jointDef.localAxisA.Set(1,0);
//    //    jointDef.Initialize(m_groundBody, body, b2Vec2(0,0), b2Vec2(1,0));
//    //
//    //    m_world->CreateJoint(&jointDef);
//    
//}
//
//void Box2dWorld::addBoxBody(cocos2d::Vec2 p){
//    
//    b2BodyDef bodyDef = b2BodyDef();
//    //    bodyDef.fixedRotation = true;
//    //    bodyDef.angularVelocity = 10;
//    bodyDef.type = b2_dynamicBody;
//    bodyDef.position = b2Vec2(p.x/PTM_RATIO,p.y/PTM_RATIO);
//    b2Body* body = m_world->CreateBody(&bodyDef);
//    
//    b2FixtureDef fixtureDef = b2FixtureDef();
//    fixtureDef.restitution = 0.5f;
//    fixtureDef.density = 20.0f;
//    b2PolygonShape shape = b2PolygonShape();
//    shape.SetAsBox(20.0f / PTM_RATIO, 20.0f / PTM_RATIO);
//    //    shape.m_radius = 20.0f / PTM_RATIO;
//    fixtureDef.shape = &shape;
//    
//    body->CreateFixture(&fixtureDef);
//}

void Box2dWorld::update(){
    while (m_destroyBody->body != nullptr){
        m_world->DestroyBody(m_destroyBody->body);
        m_destroyBody = m_destroyBody->next;
    }
    m_world->Step(1/60.0f, 8, 3);
    //    m_world->ClearForces();
    m_debugDraw->clear();
    m_world->DrawDebugData();
}