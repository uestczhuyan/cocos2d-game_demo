#ifndef _BEARRUNSCENE_H
#define _BEARRUNSCENE_H
#include "cocos2d.h"

using namespace cocos2d;

class BearRunScene : public CCLayer
{
protected:
	CCSprite * bear;
	CCAnimation * animation;
	bool isMoving;

public:

	~BearRunScene(void);
		
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

	bool init();
	bool isMovingNow();
	void moveCallBack();
	CREATE_FUNC(BearRunScene);

};
#endif