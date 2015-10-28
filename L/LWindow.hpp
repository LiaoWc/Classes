//
//  LWindow.hpp
//  Pooyan
//
//  Created by Liao on 15/10/25.
//
//

#ifndef LWindow_hpp
#define LWindow_hpp

#include "cocos2d.h"
USING_NS_CC;

class LWindow
{
public:
    static LWindow* getInstance();
    ~LWindow();
    //获取宽度
    float getWidth();
    //获取高度
    float getHeight();
    
    //按尺寸初始化窗口
    void initWindowWithSize(float width,float height);
    //全屏初始化窗口
    void initWindowWithFullScreen();
    
    //设置显示帧数
    void setDisplayStats(bool b);
    //设置帧间隔
    void setAnimationInterval(float f);
    //设置设计尺寸
    void setDesignResolutionSize(float width ,float height,int resolutionPolicy);
        
    static Scene* getRunningScene();
private:
    LWindow();
    static LWindow* m_instance;
    bool isInitScreen;
    bool isFullScreen;
};

#endif /* LWindow_hpp */
