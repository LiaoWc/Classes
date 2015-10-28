//
//  LTextureLoader.hpp
//  Pooyan
//
//  Created by Liao on 15/10/28.
//
//

#ifndef LTextureLoader_hpp
#define LTextureLoader_hpp
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class LTextureLoader
{
public:
    static LTextureLoader* getInstance();
    void addPng(std::string path);
    void load(std::function<void(int loaded,int total)> cb);
private:
    LTextureLoader();
    ~LTextureLoader();
    static LTextureLoader* m_instance;
    vector<string> m_loadList;
    int m_loaded;
    function<void(int loaded,int total)> m_callback;
    void loadProc();
};

#endif /* LTextureLoader_hpp */
