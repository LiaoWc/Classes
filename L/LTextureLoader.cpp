//
//  LTextureLoader.cpp
//  Pooyan
//
//  Created by Liao on 15/10/28.
//
//

#include "LTextureLoader.hpp"


LTextureLoader* LTextureLoader::m_instance = nullptr;

LTextureLoader::LTextureLoader()
{
    m_loaded = 0;
}

LTextureLoader::~LTextureLoader(){
    
}

LTextureLoader* LTextureLoader::getInstance(){
    if(nullptr == m_instance){
        m_instance = new LTextureLoader();
    }
    return m_instance;
}
void LTextureLoader::addPng(std::string path){
    m_loadList.push_back(path);
}

void LTextureLoader::load(std::function<void (int loaded, int total)> cb){
    m_callback = cb;
    m_loaded = 0;
    
    loadProc();
    
}
void LTextureLoader::loadProc(){
    vector<string>::iterator it= m_loadList.begin()+m_loaded;
    if(it == m_loadList.end()){
        m_loadList.clear();
        return;
    }
    Director::getInstance()->getTextureCache()->addImageAsync( (*it).c_str(), [=](Texture2D* textrue){
        ++m_loaded;
        if(m_callback != nullptr){
            m_callback(m_loaded,m_loadList.size());
        }
        loadProc();
    });
}