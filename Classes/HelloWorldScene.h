#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Tetris.h"

class HelloWorld : public cocos2d::LayerGradient
{
    Tetris* m_tetris;
    vector<unsigned short> TheWorldToPrint;
    vector<unsigned short> dynamicTetrisToPrint;
    void drawWorld();
    
    cocos2d::LabelTTF*  label;
    cocos2d::LabelTTF* labelGO;
    bool noGameOVer;
    
    bool longClick;
    bool startClick;
    
    void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    int action;
    bool updating;
    int score;
    vector<unsigned short> NextStructure;
    cocos2d::LabelTTF* labelLL;
    
    int difficult;
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void testTimer(float time);
    void testTimerx(float time);
    void testTimerb(float time);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuCloseCallbackUp(cocos2d::Ref* pSender);
    void menuCloseCallbackDown(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
