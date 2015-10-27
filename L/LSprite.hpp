//
//  LSprite.hpp
//  Pooyan
//
//  Created by Liao on 15/10/20.
//
//

#ifndef LSprite_hpp
#define LSprite_hpp

#include "cocos2d.h"
USING_NS_CC;

class LNode
{
private:
    float m_x;
    float m_y;
    bool m_visible;
    int m_opacity;
public:
    
};

class LSprite: public LNode
{
public:
    LSprite(const std::string image);
    ~LSprite();
    void setParent(Node* parent);
    void setPosition(float x,float y){
        if(m_sprite != nullptr){
            m_sprite->setPosition(x,y);
        }
    };
    void setWithJson(const std::string json);
    
    
    Sprite* getSprite(){
        return m_sprite;
    };
private:
    Sprite* m_sprite;
};

#endif /* LSprite_hpp */
