//
//  LScene.hpp
//  Pooyan
//
//  Created by Liao on 15/10/27.
//
//

#ifndef LScene_hpp
#define LScene_hpp

#include "cocos2d.h"
USING_NS_CC;

#include "LSprite.hpp"

class LScene
{
public:
    LScene();
    ~LScene();
    void run();
    void addChild(LSprite * s);
private:
    Scene* m_scene;
};


#endif /* LScene_hpp */
