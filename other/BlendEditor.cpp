//
//  BlendEditor.cpp
//  Pooyan
//
//  Created by Liao on 15/10/15.
//
//

#include "BlendEditor.hpp"
void BlendEditor::onEnter(){
    Scene::onEnter();
    
    //    auto bg = LayerColor::create(Color4B(255, 255, 255, 255));
    //    addChild(bg);
    unsigned int blend_src_factor[] = {
        
        GL_ZERO,
        GL_ONE,
        
        GL_DST_ALPHA,
        GL_DST_COLOR,
        GL_ONE_MINUS_DST_COLOR,
        GL_ONE_MINUS_DST_ALPHA,
        
        GL_SRC_ALPHA,
        GL_ONE_MINUS_SRC_ALPHA,
        
        
        GL_SRC_ALPHA_SATURATE
    };
    std::string blend_src_factor_name[] = {
        std::string("GL_ZERO"),
        std::string("GL_ONE"),
        
        std::string("GL_DST_ALPHA"),
        std::string("GL_DST_COLOR"),
        std::string("GL_ONE_MINUS_DST_COLOR"),
        std::string("GL_ONE_MINUS_DST_ALPHA"),
        
        std::string("GL_SRC_ALPHA"),
        std::string("GL_ONE_MINUS_SRC_ALPHA"),
        
        std::string("GL_SRC_ALPHA_SATURATE")
        
    };
    
    unsigned int blend_des_factor[] = {
        GL_ZERO,
        GL_ONE,
        GL_SRC_COLOR,
        GL_ONE_MINUS_SRC_COLOR,
        GL_SRC_ALPHA,
        GL_ONE_MINUS_SRC_ALPHA,
        GL_DST_ALPHA,
        GL_ONE_MINUS_DST_ALPHA
    };
    std::string blend_des_factor_name[] = {
        std::string("GL_ZERO"),
        std::string("GL_ONE"),
        std::string("GL_SRC_COLOR"),
        std::string("GL_ONE_MINUS_SRC_COLOR"),
        std::string("GL_SRC_ALPHA"),
        std::string("GL_ONE_MINUS_SRC_ALPHA"),
        std::string("GL_DST_ALPHA"),
        std::string("GL_ONE_MINUS_DST_ALPHA")
    };
    
    auto size = Director::getInstance()->getVisibleSize();
    int blend_src_factor_count =(sizeof(blend_src_factor)/sizeof(int));
    int blend_des_factor_count =(sizeof(blend_des_factor)/sizeof(int));
    
    float sprite_frame_width = size.width / blend_des_factor_count ;
    float sprite_frame_height = size.height / blend_src_factor_count;
    
    
    auto win_size = Director::getInstance()->getVisibleSize();
    auto spr = Sprite::create("animation_z/z000.png");
    spr->setPosition(win_size.width/2,win_size.height/2);
    //        spr->runAction(RepeatForever::create(action));
    addChild(spr);

    
    static float last_x,last_y,last_scale;
    for(int d=0;d<blend_des_factor_count;d++){
        for(int s=0;s<blend_src_factor_count;s++){
            //                        char* src_str = ;
            //                        int str_len = blend_src_factor_name[s].length();
            TTFConfig ttfConfig("arial.ttf", 40, GlyphCollection::DYNAMIC,nullptr,true);
            // Green
            auto label1 = Label::createWithTTF(ttfConfig,blend_src_factor_name[s]+"\n"+blend_des_factor_name[d], TextHAlignment::CENTER, size.width);
            label1->setAnchorPoint(Vec2(0.5, 1));
            label1->setPosition(size.width/2,size.height);
            label1->setVisible(false);
            label1->setTextColor( Color4B::WHITE );
            addChild(label1,10);
            //
            //            auto p3 = Sprite::create("p3.png");
            //            //            p3->setOpacity(200);
            //            //            p3->setAnchorPoint(Vec2(0.5,1));
            //            p3->setPosition((0.5+d)*sprite_frame_width,(0.5+s)*sprite_frame_height);
            //            p3->setScale(sprite_frame_width/p3->getContentSize().width*0.9);
            //            addChild(p3);
            //            BlendFunc cbl = { blend_src_factor[s] , blend_des_factor[d] };
            //            p3->setBlendFunc(cbl);
            {
                auto head = Sprite::create("head0.png");
                head->setOpacity(150);
                head->setScale(sprite_frame_height/head->getContentSize().height*0.9);
                head->setPosition((0.5+d)*sprite_frame_width,(0.5+s)*sprite_frame_height);
                
                this->addChild(head);
                auto head_size = head->getContentSize();
                
                auto light = Sprite::create("headlight2.png");
                light->setPosition(Vec2(head_size.width/2,head_size.height/2));
                
                BlendFunc cbl = { blend_src_factor[s] , blend_des_factor[d] };
                light->setBlendFunc(cbl);
                
                
                head->addChild(light);
                
                
                auto listener1 = EventListenerTouchOneByOne::create();
                listener1->setSwallowTouches(true);
                auto ed = Director::getInstance()->getEventDispatcher();
                listener1->onTouchBegan = [=](Touch* touch, Event* event){
                    auto target = static_cast<Sprite*>(event->getCurrentTarget());
                    
                    Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
                    Size s = target->getContentSize();
                    Rect rect = Rect(0, 0, s.width, s.height);
                    
                    if (rect.containsPoint(locationInNode))
                    {
                        last_x = target->getPositionX();
                        last_y = target->getPositionY();
                        last_scale =target->getScale();
                        //                    last_pos = target->getPosition();
                        log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
                        target->setPosition(size.width/2,size.height/2);
                        target->setScale(size.height/head->getContentSize().height*0.9);
                        target->setLocalZOrder(1);
                        label1->setVisible(true);
                        //            target->setScale(1.9);
                        //            m_world->addBallBody(Vec2(0,0));
                        return true;
                    }
                    return false;
                };
                listener1->onTouchEnded = [=](Touch* touch, Event* event){
                    auto target = static_cast<Sprite*>(event->getCurrentTarget());
                    target->setPosition(last_x,last_y);
                    target->setScale(last_scale);
                    label1->setVisible(false);
                    log("sprite onTouchesEnded.. ");
                };
                
                ed->addEventListenerWithSceneGraphPriority(listener1, head);

            }
            
        }
    }
    
    
    //    p3->setBlendFunc(cbl);
    
}