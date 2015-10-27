//
//  ScrollView.hpp
//  Pooyan
//
//  Created by Liao on 15/10/16.
//
//

#ifndef ScrollView_hpp
#define ScrollView_hpp

#define ScrollView_Debug 1
//滚动条宽度
#define ScrollView_Width0 5

#include "cocos2d.h"
USING_NS_CC;

class ScrollView
{
    
public:
    // implement the "static create()" method manually
//    CREATE_FUNC(ScrollView);
    ScrollView();
    ~ScrollView();
    
    //设置显示层大小
    void setDisplaySize(const Size s);
    //设置内容层大小
    void setContentSize(const Size s);
    //添加内容
    void addContent(Node* n,Size s,bool isLand = false);
    
    //移动内容层
    void moveContent(Vec2 delta);
    //设置父节点
    void setParent(Node* parent);
    //设置位置
    void setPosition(const Vec2 p);
private:
    //显示层
    Layer* m_layer_display;
    //裁剪层
    ClippingNode* m_node_clipping;
    //容器层
    LayerColor * m_layer_stencil;
    //内容层
    Layer* m_layer_content;
    //显示层大小
    Size m_size_display;
    //内容层大小
    Size m_size_content;
    //内容层位移
    Vec2 m_content_offset;
    //垂直进度条
    DrawNode* m_node_vertical;
    //水平进度条
    DrawNode* m_node_horizontal;
};

#endif /* ScrollView_hpp */
