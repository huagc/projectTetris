#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

void HelloWorld::drawWorld()
{
    static bool ifinit=false;
    static map<int,Sprite*> SpriteMap;
    static map<int,Sprite*> SpriteMap1;
    static map<int,Sprite*> SpriteMap2;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    float StartPointx,StartPointy,interval;
    StartPointx=visibleSize.width*0.14;
    StartPointy=visibleSize.height-70;
    
    float ratio=2.5;
    float ratio2=1.3;
    interval=(visibleSize.width/80)*ratio;
    
    if(!ifinit)
    {
        LabelTTF* labelS=LabelTTF::create("SCORE: ", "Chalkduster", 28);
        
        labelS->setPosition(Vec2(visibleSize.width*0.42,visibleSize.height*((float)1/2-0.04)));
        
        this->addChild(labelS);
        
        label = LabelTTF::create("0", "Arial", 28);
        
        // position the label on the center of the screen
        label->setPosition(Vec2(visibleSize.width*0.42,visibleSize.height*((float)2/5-0.04)));
        
        // add the label as a child to this layer
        this->addChild(label);
        
        LabelTTF* labelN=LabelTTF::create("NEXT: ", "Chalkduster", 28);
        
        labelN->setPosition(Vec2(visibleSize.width*0.42,visibleSize.height*((float)3/4)));
        
        this->addChild(labelN);
        
        LabelTTF* labelL=LabelTTF::create("LEVEL: ", "Chalkduster", 28);
        
        labelL->setPosition(Vec2(visibleSize.width*0.42,visibleSize.height*((float)1/5+0.03)));
        
        this->addChild(labelL);
        
        labelLL=LabelTTF::create("5", "Arial", 28);
        
        labelLL->setPosition(Vec2(visibleSize.width*0.42,visibleSize.height*(0.12+0.03)));
        
        this->addChild(labelLL);
        
        ifinit=true;
    }
    
    char s[50];
    sprintf(s,"%06d",score);
    
    string ss(s);
    
    label->setString(ss);
    
    sprintf(s,"%d",difficult+1);
    
    string sss(s);
    
    labelLL->setString(sss);
    
    
    
    int idx=0;
    
    for(vector<unsigned short>::iterator i=TheWorldToPrint.begin();i!=TheWorldToPrint.end();i++)
    {
        for(int j=0;j<16;j++)
        {
            unsigned short K=1;
            K=K<<j;
            if((*i&K)!=0)
            {
                if(SpriteMap.find(idx*16+j)!=SpriteMap.end())
                    continue;
                else
                {
                    float x,y;
                    x=StartPointx+j*interval;
                    
                    y=StartPointy;
                    
                    Sprite* sprite;
                    
                    if(j<2||j>13||idx>29)
                    {
                        sprite = Sprite::create("Ice_Block_NSMBDIY.png");
                        sprite->setScale(0.023f*ratio2);
                    }
                    else
                    {
                        sprite = Sprite::create("block.png");
                        sprite->setColor(Color3B(200, 100, 200));
                        sprite->setScale(0.045f*ratio2);
                    }
                    
                    // position the sprite on the center of the screen
                    sprite->setPosition(Vec2(x , y ));
                    
                    
                    
                    sprite->setOpacity(230);
                    
                    sprite->getTexture()->setAntiAliasTexParameters();
                    
                    
                    
                    // add the sprite as a child to this layer
                    this->addChild(sprite, 0);
                    
                    SpriteMap[idx*16+j]=sprite;
                }
            }
            else
            {
                if(SpriteMap.find(idx*16+j)!=SpriteMap.end())
                {
                    SpriteMap[idx*16+j]->removeFromParentAndCleanup(true);
                    SpriteMap.erase(idx*16+j);
                }
            }
        }
        StartPointy-=interval;
        idx++;
    }
    
    StartPointx=visibleSize.width*0.14;
    StartPointy=visibleSize.height-70;
    interval=(visibleSize.width/80)*ratio;
    idx=0;
    
    for(vector<unsigned short>::iterator i=dynamicTetrisToPrint.begin();i!=dynamicTetrisToPrint.end();i++)
    {
        for(int j=0;j<16;j++)
        {
            unsigned short K=1;
            K=K<<j;
            if((*i&K)!=0)
            {
                if(SpriteMap1.find(idx*16+j)!=SpriteMap1.end())
                    continue;
                else
                {
                    float x,y;
                    x=StartPointx+j*interval;
                    
                    y=StartPointy;
                    Sprite* sprite = Sprite::create("block.png");
                    
                    // position the sprite on the center of the screen
                    sprite->setPosition(Vec2(x , y ));
                    
                    sprite->setScale(0.045f*ratio2);
                    
                    sprite->setColor(Color3B(0, 100, 255));
                    
                    sprite->setOpacity(230);
                    
                    sprite->getTexture()->setAntiAliasTexParameters();
                    
                    // add the sprite as a child to this layer
                    this->addChild(sprite, 0);
                    
                    SpriteMap1[idx*16+j]=sprite;
                }
            }
            else
            {
                if(SpriteMap1.find(idx*16+j)!=SpriteMap1.end())
                {
                    SpriteMap1[idx*16+j]->removeFromParentAndCleanup(true);
                    SpriteMap1.erase(idx*16+j);
                }
            }
        }
        StartPointy-=interval;
        idx++;
    }
    
    StartPointx=visibleSize.width*0.57;
    StartPointy=visibleSize.height-200;
    interval=(visibleSize.width/80)*ratio;
    idx=0;
    
    for(vector<unsigned short>::iterator i=NextStructure.begin();i!=NextStructure.end();i++)
    {
        for(int j=0;j<16;j++)
        {
            unsigned short K=1;
            K=K<<j;
            if((*i&K)!=0)
            {
                if(SpriteMap2.find(idx*16+j)!=SpriteMap2.end())
                    continue;
                else
                {
                    float x,y;
                    x=StartPointx+j*interval;
                    
                    y=StartPointy;
                    Sprite* sprite = Sprite::create("block.png");
                    
                    // position the sprite on the center of the screen
                    sprite->setPosition(Vec2(x , y ));
                    
                    sprite->setScale(0.045f*ratio2);
                    
                    sprite->setColor(Color3B(0, 255, 255));
                    
                    sprite->setOpacity(230);
                    
                    sprite->getTexture()->setAntiAliasTexParameters();
                    
                    // add the sprite as a child to this layer
                    this->addChild(sprite, 0);
                    
                    SpriteMap2[idx*16+j]=sprite;
                }
            }
            else
            {
                if(SpriteMap2.find(idx*16+j)!=SpriteMap2.end())
                {
                    SpriteMap2[idx*16+j]->removeFromParentAndCleanup(true);
                    SpriteMap2.erase(idx*16+j);
                }
            }
        }
        StartPointy-=interval;
        idx++;
    }
    
}

void HelloWorld::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    switch (keyCode) {
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
            action=3;
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            action=0;
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            startClick=true;
            action=1;
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            startClick=true;
            action=2;
            break;
            
        default:
            break;
    }
}

void HelloWorld::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    startClick=false;
    longClick=false;
    action=10;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    difficult=4;
    drawWorld();
    noGameOVer=true;
    longClick=false;
    startClick=false;
    //////////////////////////////
    // 1. super init first
    
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    if (!LayerGradient::initWithColor(ccc4(200, 200, 200, 255),ccc4(100, 100, 185, 255),ccp(0.0f, 2.0f))) //RGBA
    {
        return false;
    }
    
//    Director::getInstance()->getOpenGLView()->setDesignResolutionSize(500,600,ResolutionPolicy::EXACT_FIT);
//    
//    Director::getInstance()->getOpenGLView()->setFrameSize(500,600);

    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Director::sharedDirector()->setDisplayStats(false);
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    
    cocos2d::Vector<cocos2d::MenuItem*> pMenuItems;
    
    auto closeItem = MenuItemImage::create(
                                           "arrow_circle_left_32.png",
                                           "arrow_circle_left_32_touch.png",
                                           this,
                                           menu_selector(HelloWorld::menuCloseCallback));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y +visibleSize.height- closeItem->getContentSize().height/2));
    
    closeItem->setOpacity(125);
    
    pMenuItems.pushBack(closeItem);
    
    auto closeItemUp = MenuItemImage::create(
                                             "arrow_up_32.png",
                                             "arrow_up_32_touch.png",
                                             this,
                                             menu_selector(HelloWorld::menuCloseCallbackUp));
    
	closeItemUp->setPosition(Vec2(origin.x + visibleSize.width - (5*(closeItemUp->getContentSize().width/2)) ,
                                  origin.y +visibleSize.height- closeItemUp->getContentSize().height/2));
    
    closeItemUp->setOpacity(125);
    
    pMenuItems.pushBack(closeItemUp);
    
    auto closeItemDown = MenuItemImage::create(
                                               "arrow_down_32.png",
                                               "arrow_down_32_touch.png",
                                               this,
                                               menu_selector(HelloWorld::menuCloseCallbackDown));
    
	closeItemDown->setPosition(Vec2(origin.x + visibleSize.width - (9*(closeItemUp->getContentSize().width/2)) ,
                                    origin.y +visibleSize.height- closeItemUp->getContentSize().height/2));
    closeItemDown->setOpacity(125);
    
    
    pMenuItems.pushBack(closeItemDown);
    
    // create menu, it's an autorelease object

    cocos2d::Menu* pMenu = cocos2d::Menu::createWithArray(pMenuItems);
    
    pMenu->setPosition(Vec2::ZERO);
    
    this->addChild(pMenu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    m_tetris= new Tetris();
    
    
    labelGO = LabelTTF::create("Game Over!!", "Arial", 50);
    
    // position the label on the center of the screen
    labelGO->setPosition(Vec2(visibleSize.width*0.375,visibleSize.height/2));
    
    // add the label as a child to this layer
    this->addChild(labelGO,99);
    
    labelGO->setVisible(false);
    
    
    action=10;
    
    m_tetris->update(TheWorldToPrint, dynamicTetrisToPrint,action,score,NextStructure,difficult);
    
    drawWorld();
    
    this->schedule(schedule_selector(HelloWorld::testTimer), 0.015);
    
    this->schedule(schedule_selector(HelloWorld::testTimerb), 0.1);
    
    this->schedule(schedule_selector(HelloWorld::testTimerx), 0.01);
    
    
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::keyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::keyReleased, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    
    return true;
}

void HelloWorld::testTimer(float time)
{
    static int previous_action=10;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    if(previous_action==1&&longClick)
    {
        action=1;
    }
    else if(previous_action==2&&longClick)
        action=2;
    
    if(noGameOVer)
    {
        updating=true;
        noGameOVer=m_tetris->update(TheWorldToPrint, dynamicTetrisToPrint,action,score,NextStructure,difficult);
        if(action==3) action=10;
        else if(action==1||action==2)
        {
            previous_action=action;
            action=10;
        }
        updating=false;
    }
    if(!noGameOVer)
    {
        labelGO->setVisible(true);
    }
    
}

void HelloWorld::testTimerx(float time)
{
    if(!updating)
        drawWorld();
}

void HelloWorld::testTimerb(float time)
{
    static int count=0;
    if(startClick)
    {
        if(count++>=2)
        {
            longClick=true;
        }
    }
    else
    {
        count=0;
        longClick=false;
    }
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    labelGO->setVisible(false);
    noGameOVer=true;
    m_tetris->init();
    score=0;
    
    
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
}

void HelloWorld::menuCloseCallbackUp(Ref* pSender)
{
    if(difficult<9)
        difficult++;
}

void HelloWorld::menuCloseCallbackDown(Ref* pSender)
{
    if(difficult>0)
        difficult--;
}
