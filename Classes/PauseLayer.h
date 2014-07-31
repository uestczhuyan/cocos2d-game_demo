#ifndef __PAUSELAYER_H__
#define __PAUSELAYER_H__
#include "cocos2d.h"
#include "cocos-ext.h"


USING_NS_CC;
USING_NS_CC_EXT;
using namespace gui;

class PauseLayer :public CCLayer{
private:
	CCMenuItemImage * paseItem;
	CCSprite* paseNormalSprite;
	CCSprite* paseSelectedSprite;
	CCLabelTTF* scoreItem;
public:

	PauseLayer();
	~PauseLayer();
	CREATE_FUNC(PauseLayer);
	bool init();
	void updateScore(int score);
	virtual void menuPaseCallBack(CCObject* pSender);
};

#endif