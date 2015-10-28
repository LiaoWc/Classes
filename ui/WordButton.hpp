//
//  WordButton.hpp
//  Pooyan
//
//  Created by Liao on 15/10/28.
//
//

#ifndef WordButton_hpp
#define WordButton_hpp

#include "cocos2d.h"
USING_NS_CC;

class WordButton
{
public:
    WordButton(std::string word);
    ~WordButton();
    void setParent(Node* n);
    void setPosition(float x,float y);
    void setCallFunc(std::function<void()> cb);
private:
    std::function<void()> m_cb;
    Label* m_word;
    DrawNode* m_draw;
    Layer* m_layer;

};
#endif /* WordButton_hpp */
