//
//  ScrollView.cpp
//  Pooyan
//
//  Created by Liao on 15/10/16.
//
//

#include "ScrollView.hpp"
ScrollView::ScrollView(){
    m_layer_display = nullptr;
    m_layer_content = nullptr;
    m_size_display = Size(300,300);
    m_size_content = Size(0,0);
    m_content_offset = Vec2(0,0);
}

ScrollView::~ScrollView(){
    
}

//设置显示层大小
void ScrollView::setDisplaySize(const Size s){
    m_size_display = s;
}
//设置内容层大小
void ScrollView::setContentSize(const Size s){
    m_size_content = s;
    m_layer_stencil->setContentSize(m_size_display);
}

//添加内容
void ScrollView::addContent(Node* n,Size s,bool isLand){
    m_layer_content->addChild(n);
//    isLand = true;
    if(isLand){
        n->setPosition(Vec2(s.width/2,- s.height/2) + Vec2(m_size_content.width,m_size_display.height));
        m_size_content.width += s.width;
        if(m_size_content.height < s.height){
            m_size_content.height = s.height;
        }
    }else{
        n->setPosition(Vec2(s.width/2,- s.height/2) + Vec2(0,m_size_display.height - m_size_content.height));
        m_size_content.height += s.height;
        if(m_size_content.width < s.width){
            m_size_content.width = s.width;
        }
    }
   
//    m_layer_content->setPosition(m_size_content.width/2,m_size_display.height - m_size_content.height/2);
}


void ScrollView::setParent(Node* parent){
    //初始化显示层
    {
        if(!m_layer_display){
            m_layer_display = Layer::create();
            parent->addChild(m_layer_display);
        }
        if (ScrollView_Debug) {
            auto draw = DrawNode::create();
            draw->drawRect(Vec2(0,0), Vec2(m_size_display.width,m_size_display.height), Color4F(1,1,1,1));
            m_layer_display->addChild(draw);
        }
        
        
        auto draw = DrawNode::create();
        draw->drawSolidRect(Vec2(0,100), Vec2(10,0), Color4F(0.5,0.5,0.5,1));
//        draw->drawRect(Vec2(0,0), Vec2(m_size_display.width,m_size_display.height), Color4F(1,1,1,1));
        m_layer_display->addChild(draw,1);
    }
    //初始化遮罩
    {
        m_node_clipping  = ClippingNode::create();
        m_layer_stencil = LayerColor::create();
        m_layer_stencil->setContentSize(m_size_display);
        m_node_clipping->setStencil(m_layer_stencil);
        m_layer_display->addChild(m_node_clipping);
    }
    //初始化内容层
    {
        if(!m_layer_content){
            m_layer_content = Layer::create();
            m_node_clipping->addChild(m_layer_content);
        }
        auto listener1 = EventListenerTouchOneByOne::create();
        listener1->setSwallowTouches(true);
        auto ed = Director::getInstance()->getEventDispatcher();
        listener1->onTouchBegan = [=](Touch* touch, Event* event){
            auto target = static_cast<Layer*>(event->getCurrentTarget());
            
            Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
            CCLOG("%f,%f",locationInNode.x,locationInNode.y);
            Size s = target->getContentSize();
            Rect rect = Rect(0, 0, m_size_display.width, m_size_display.height);
            
            if (rect.containsPoint(locationInNode))
            {
                CCLOG("tt");
                return true;
            }
            return false;
        };
        listener1->onTouchMoved = [=](Touch* touch, Event* event){
            this->moveContent(touch->getDelta());
//            m_content_offset += touch->getDelta();
//            m_layer_content->setPosition(m_layer_content->getPosition() + touch->getDelta());
        };

        listener1->onTouchEnded = [=](Touch* touch, Event* event){
            //        auto target = static_cast<Sprite*>(event->getCurrentTarget());
            //        target->setPosition(last_x,last_y);
            //        target->setScale(last_scale);
            //        label1->setVisible(false);
            //        log("sprite onTouchesEnded.. ");
        };
        
        ed->addEventListenerWithSceneGraphPriority(listener1, m_layer_display);
        
        
        
    }
    //添加内容
//    {
//        auto content = Sprite::create("/Users/liao/test.png");
//        addContent(content, content->getContentSize());
//        
//    }
//    {
//        auto content = Sprite::create("/Users/liao/test.png");
//        addContent(content, content->getContentSize());
//        
//    }
}

void ScrollView::moveContent(cocos2d::Vec2 delta){
     m_content_offset += delta;

    if (m_content_offset.x >= 0){
        m_content_offset.x = 0;
    }else {
        if (m_content_offset.x + m_size_content.width >  m_size_display.width) {
        }else{
            m_content_offset.x =  m_size_display.width - m_size_content.width;
        }
    }
    
    if (m_content_offset.y <= 0){
        m_content_offset.y = 0;
    }else {
        if (m_content_offset.y + m_size_display.height >  m_size_content.height) {
            m_content_offset.y =  m_size_content.height - m_size_display.height;
        }else{
            
        }
    }
    
    m_layer_content->setPosition(m_content_offset.x,m_content_offset.y);
}