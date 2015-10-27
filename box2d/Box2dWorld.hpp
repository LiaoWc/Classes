//
//  Box2dWorld.hpp
//  Pooyan
//
//  Created by Liao on 15/10/7.
//
//

#ifndef Box2dWorld_hpp
#define Box2dWorld_hpp
#include "Box2dBody.hpp"
#include "cocos2d.h"
#include "Box2dDebugDraw.hpp"
#include "external/Box2d/Box2d.h"
USING_NS_CC;
#define PTM_RATIO 32

class QueryCallback : public b2QueryCallback
{
public:
    QueryCallback(const b2Vec2& point)
    {
        m_point = point;
        m_fixture = nullptr;
    }
    
    bool ReportFixture(b2Fixture* fixture)
    {
        b2Body* body = fixture->GetBody();
        if (body->GetType() == b2_dynamicBody)
        {
            bool inside = fixture->TestPoint(m_point);
            if (inside)
            {
                m_fixture = fixture;
                
                // We are done, terminate the query.
                return false;
            }
        }
        
        // Continue the query.
        return true;
    }
    
    b2Vec2 m_point;
    b2Fixture* m_fixture;
};

class DestroyBody{
public:
    DestroyBody(b2Body* b){
        body = b;
        next = nullptr;
    };
    ~DestroyBody(){
        delete next;
    };
    b2Body* body;
    DestroyBody* next;
};


class Box2dWorld
{
public:
    Box2dWorld();
    ~Box2dWorld();
    
    //设置debug节点
    void setDebugNode(Node* parent);
    
    //更新物理世界
    void update();
    
    //设置世界大小
//    void setWorldSize(b2Vec2 size,bool hasGround = true);
    
    //获取bodyId
    int getBodyId();

    
    void addPlayerBody();
    
    void addWolfBody(Vec2 position);
    
    void addBallBody(Vec2 position);
    void addBoxBody(Vec2 position);

    void addWallBody();
    
    void addBody(std::string name);
    void delBody(std::string name);
    
    bool onTouchBegan(Vec2 p);
    void onTouchMoved(Vec2 p);
    void onTouchEnded(Vec2 p);
    
    
    //删除刚体
//    void DestroyBody(b2Body* body);
private:
    int m_bodyId;
    //物理世界
    b2World* m_world;
    //世界大小
    b2Vec2* m_worldSize;
    b2Body* m_groundBody;
//    b2MouseJoint* m_mouseJoint;
//    Vec2 m_touchPoint;
    
//    b2Body* m_yerenBody;
    Box2dDebugDraw* m_debugDraw;
    b2ContactListener *m_contectListener;
    DestroyBody* m_destroyBody;
};
#endif /* Box2dWorld_hpp */
