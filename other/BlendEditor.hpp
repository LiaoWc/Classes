//
//  BlendEditor.hpp
//  Pooyan
//
//  Created by Liao on 15/10/15.
//
//

#ifndef BlendEditor_hpp
#define BlendEditor_hpp

#include "cocos2d.h"
USING_NS_CC;
class BlendEditor: public Scene
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(BlendEditor);
    void onEnter();
    //    cocos2d::SpriteBatchNode* CreateCaoPing();
    //    void update(float delta);
};

#endif /* BlendEditor_hpp */
