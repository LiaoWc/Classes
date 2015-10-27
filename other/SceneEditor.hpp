//
//  SceneEditor.hpp
//  Pooyan
//
//  Created by Liao on 15/10/15.
//
//

#ifndef SceneEditor_hpp
#define SceneEditor_hpp

#include "cocos2d.h"
USING_NS_CC;

#include "EScene.hpp"

class SceneEditor: public Scene
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(SceneEditor);
    void onEnter();
    //    cocos2d::SpriteBatchNode* CreateCaoPing();
    //    void update(float delta);
};

#endif /* SceneEditor_hpp */
