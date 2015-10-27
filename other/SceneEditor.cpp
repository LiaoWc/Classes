//
//  SceneEditor.cpp
//  Pooyan
//
//  Created by Liao on 15/10/15.
//
//

#include "SceneEditor.hpp"
#include "ScrollView.hpp"


void SceneEditor::onEnter(){
    Scene::onEnter();
    auto scene = EScene::create();
    addChild(scene);
    
    ScrollView* sv = new ScrollView();
    sv->setParent(scene);
//    auto size = Director::getInstance()->getVisibleSize();
//    {
//        TTFConfig ttfConfig("Marker Felt.ttf", 50);
//        // Green
//        auto label1 = Label::createWithTTF(ttfConfig,"View", TextHAlignment::CENTER, size.width);
//        label1->setPosition(size.width/2, size.height * 0.5f);
//        label1->setTextColor( Color4B::WHITE );
//        addChild(label1);
//        
//        auto listener1 = EventListenerTouchOneByOne::create();
//        listener1->setSwallowTouches(true);
//        auto ed = Director::getInstance()->getEventDispatcher();
//        listener1->onTouchBegan = [this](Touch* touch, Event* event){
//            auto target = static_cast<Sprite*>(event->getCurrentTarget());
//            
//            Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
//            Size s = target->getContentSize();
//            Rect rect = Rect(0, 0, s.width, s.height);
//            
//            if (rect.containsPoint(locationInNode))
//            {
//                log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
//                target->setScale(0.9);
//                //            m_world->addBallBody(Vec2(0,0));
//                return true;
//            }
//            return false;
//        };
//        listener1->onTouchEnded = [=](Touch* touch, Event* event){
//            auto target = static_cast<Sprite*>(event->getCurrentTarget());
//            target->setScale(1);
//            log("sprite onTouchesEnded.. ");
//        };
//        
//        ed->addEventListenerWithSceneGraphPriority(listener1, label1);
//    }
//    
//    {
//        auto pTextField = TextFieldTTF::textFieldWithPlaceHolder("<click here for input>",
//                                                                 "Marker Felt.ttf",
//                                                                 50);
//        pTextField->setPosition(size.width/2, size.height * 0.5f);
//        pTextField->attachWithIME();
//        addChild(pTextField);
//        
//        
//        auto listener1 = EventListenerTouchOneByOne::create();
//        listener1->setSwallowTouches(true);
//        auto ed = Director::getInstance()->getEventDispatcher();
//        listener1->onTouchBegan = [this](Touch* touch, Event* event){
//            auto target = static_cast<TextFieldTTF*>(event->getCurrentTarget());
//            
//            Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
//            Size s = target->getContentSize();
//            Rect rect = Rect(0, 0, s.width, s.height);
//            
//            if (rect.containsPoint(locationInNode))
//            {
//                target->runAction(RepeatForever::create( Sequence::create(
//                                                                      FadeTo::create( 0.5f, 200),
//                                                                      FadeTo::create( 0.5f,  255),
//                                                                      nullptr)
//                                                    )
//                              );
////                pTextField->runAction(<#cocos2d::Action *action#>)
//                target->attachWithIME();
//                return true;
//            }else{
//                target->stopAllActions();
//                target->detachWithIME();
//            }
//            return false;
//        };
//        ed->addEventListenerWithSceneGraphPriority(listener1, pTextField);
//        
////        TextFieldDelegate tfd = TextFieldDelegate();
////        tfd.
//    }
    
    
}