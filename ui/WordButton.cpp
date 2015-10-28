//
//  WordButton.cpp
//  Pooyan
//
//  Created by Liao on 15/10/28.
//
//

#include "WordButton.hpp"

WordButton::WordButton(std::string word){
    m_layer = Layer::create();
    m_layer->setAnchorPoint(Vec2(0,0));
    
    

    m_word = Label::createWithSystemFont(word, "", 100);
    m_word->setColor(Color3B(0, 0, 0));
    m_layer->addChild(m_word,1);
    
    auto word_size = m_word->getContentSize();
    m_draw = DrawNode::create();
    m_draw->drawSolidRect(Vec2(word_size.width,word_size.height) / -1.6, Vec2(word_size.width,word_size.height) / 1.6, Color4F(1.0f, 1.0f, 1.0f, 1.0f));
    m_layer->addChild(m_draw);
    
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [=](Touch* touch, Event* event){
        Vec2 locationInNode = m_word->convertToNodeSpace(touch->getLocation());
        Rect rect = Rect(0, 0, word_size.width, word_size.height);
        
        if (rect.containsPoint(locationInNode))
        {
            m_layer->setScale(0.95);
            return true;
        }
        CCLOG("f");
        return false;
    };
    listener->onTouchEnded = [=](Touch* touch, Event* event){
        m_layer->setScale(1);
        Rect rect = Rect(0, 0, word_size.width, word_size.height);
        Vec2 locationInNode = m_word->convertToNodeSpace(touch->getLocation());
        if (rect.containsPoint(locationInNode))
        {
            if(m_cb != nullptr){
                m_cb();
            }
        }
    };
    m_layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, m_word);

}
void WordButton::setParent(Node* n){
    n->addChild(m_layer);
}
void WordButton::setPosition(float x,float y){
    m_layer->setPosition(x, y);
}
void WordButton::setCallFunc(std::function<void()> cb){
    m_cb = cb;
}