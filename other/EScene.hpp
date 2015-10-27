//
//  EScene.hpp
//  Pooyan
//
//  Created by Liao on 15/10/16.
//
//

#ifndef EScene_hpp
#define EScene_hpp

#include "cocos2d.h"
USING_NS_CC;

#include "network/WebSocket.h"

class EScene: public Layer
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(EScene);
    void onEnter();
    void set();
    //    cocos2d::SpriteBatchNode* CreateCaoPing();
    //    void update(float delta);
};

#endif /* EScene_hpp */
