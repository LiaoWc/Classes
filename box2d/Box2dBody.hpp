//
//  Box2dBody.hpp
//  Pooyan
//
//  Created by Liao on 15/10/12.
//
//

#ifndef Box2dBody_hpp
#define Box2dBody_hpp

#include "cocos2d.h"
#include "external/Box2d/Box2d.h"
USING_NS_CC;

class Box2dBody
{
public:
    Box2dBody();
    ~Box2dBody();
    void setTag(std::string m_myType);
    std::string getTag();
private:
    std::string m_myType;
    b2Body* m_body;
    b2Body* getBody();
};

#endif /* Box2dBody_hpp */
