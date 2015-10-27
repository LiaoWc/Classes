//
//  Master.hpp
//  Pooyan
//
//  Created by Liao on 15/10/12.
//
//

#ifndef Master_hpp
#define Master_hpp

#include "cocos2d.h"
//#include "box"
USING_NS_CC;

class Master : public Layer
{
public:
    // implement the "static create()" method manually
    CREATE_FUNC(Master);
    void onEnter();
    
    void update(float delta);
private:
    void createBody();
    
};

#endif /* Master_hpp */
