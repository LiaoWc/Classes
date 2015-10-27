//
//  Box2dDebugDraw.cpp
//  Pooyan
//
//  Created by Liao on 15/10/6.
//
//

#include "Box2dDebugDraw.hpp"
#define PTM_RATIO 32
Box2dDebugDraw::~Box2dDebugDraw(){
    
}

Box2dDebugDraw::Box2dDebugDraw()
{
    m_drawNode = NULL;
}
void Box2dDebugDraw::clear(){
    m_drawNode->clear();
}

void Box2dDebugDraw::setParent(Node* s){
    m_drawNode = DrawNode::create();
    //    drawNode->retain();
    //    m_drawNode = drawNode;
    //    m_drawNode->drawSegment(Vec2(0,0), Vec2(1136,0), 0.0f, Color4F(1,0,0,1.0f));
    
    s->addChild(m_drawNode,10);
};

void Box2dDebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color){
    
}

/// Draw a solid closed polygon provided in CCW order.
void Box2dDebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color){
    Vec2* new_vertices = new Vec2[vertexCount];
    for( int i=0;i<vertexCount;i++) {
        new_vertices[i] = Vec2(vertices[i].x*PTM_RATIO,vertices[i].y*PTM_RATIO) ;
    }
    m_drawNode->drawPolygon(new_vertices, vertexCount, Color4F(color.r,color.g,color.b,0.5f), 1.0f, Color4F(color.r,color.g,color.b,1.0f));
}

/// Draw a circle.
void Box2dDebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color){
    m_drawNode->drawCircle(Vec2(center.x*PTM_RATIO,center.y*PTM_RATIO), radius*PTM_RATIO ,0, 50, true, Color4F(color.r,color.g,color.b,1.0f));
}

/// Draw a solid circle.
void Box2dDebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color){
    
//        CCLOG("%f,%f",axis.x,axis.y);
    
    m_drawNode->drawCircle(Vec2(center.x*PTM_RATIO,center.y*PTM_RATIO), radius*PTM_RATIO ,0, radius*PTM_RATIO, true, Color4F(color.r,color.g,color.b,1.0f));
    m_drawNode->drawSolidCircle(Vec2(center.x*PTM_RATIO,center.y*PTM_RATIO), radius*PTM_RATIO, 0, radius*PTM_RATIO, 1, 1, Color4F(color.r,color.g,color.b,0.5f));
}

/// Draw a line segment.
void Box2dDebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color){
//        CCLOG("DrawSegment %f",p1.x);
    m_drawNode->drawSegment(Vec2(p1.x*32,p1.y*32), Vec2(p2.x*32,p2.y*32), 1.0f, Color4F(color.r,color.g,color.b,1.0f));
}

/// Draw a transform. Choose your own length scale.
/// @param xf a transform.
void Box2dDebugDraw::DrawTransform(const b2Transform& xf){
    
}
