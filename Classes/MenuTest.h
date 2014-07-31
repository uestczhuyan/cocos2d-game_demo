#ifndef _MENUTEST_H
#define _MENUTEST_H

#include "cocos2d.h"
#include "cocos-ext.h"
#include "UiEditLayer.h"

using namespace cocos2d::extension;
USING_NS_CC;

class MenuLayerMainMenu : public cocos2d::CCLayer
{
protected:
    cocos2d::CCMenuItem*    m_disabledItem;

public:
    MenuLayerMainMenu(void);
    ~MenuLayerMainMenu();

public:
    virtual bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent * pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent * pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent * pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent * pEvent);

    void allowTouches(float dt);
    void menuCallback(CCObject* pSender);
	void menuCloseCallback(CCObject* pSender);
	void menuStartGame(CCObject* pSender);
	void menuStartAirGame(CCObject* pSender);
	void menuChangeUiEditCallBack(CCObject *pSender);
    /*void menuCallbackConfig(CCObject* pSender);
    void menuCallbackDisabled(CCObject* pSender);
    void menuCallbackEnable(CCObject* pSender);
    void menuCallback2(CCObject* pSender);
    void menuCallbackPriorityTest(CCObject* pSender);
    void menuCallbackBugsTest(CCObject *pSender);
    void menuOnQuit(CCObject* pSender);
    void menuMovingCallback(CCObject *pSender);*/

    //CREATE_NODE(MenuLayer1);
};

#endif
