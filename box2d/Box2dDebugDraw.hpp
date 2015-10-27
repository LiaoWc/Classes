//
//  Box2dDebugDraw.hpp
//  Pooyan
//
//  Created by Liao on 15/10/6.
//
//

#ifndef Box2dDebugDraw_hpp
#define Box2dDebugDraw_hpp

#include "cocos2d.h"
#include "external/Box2D/Box2D.h"
USING_NS_CC;
class Box2dDebugDraw:public b2Draw
{
public:
    Box2dDebugDraw();
    ~Box2dDebugDraw();
    
    void setParent(Node* s);
    void clear();
    
    /// Draw a closed polygon provided in CCW order.
    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    
    /// Draw a solid closed polygon provided in CCW order.
    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) ;
    
    /// Draw a circle.
    void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) ;
    
    /// Draw a solid circle.
    void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) ;
    
    /// Draw a line segment.
    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) ;
    
    /// Draw a transform. Choose your own length scale.
    /// @param xf a transform.
    void DrawTransform(const b2Transform& xf) ;

protected:
    
    uint32 m_drawFlags;
private:
    DrawNode* m_drawNode;
    Node* m_parent;
};


#endif /* Box2dDebugDraw_hpp */
