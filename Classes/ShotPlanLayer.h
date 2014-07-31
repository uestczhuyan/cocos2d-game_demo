#ifndef __SHOTPLANLAYER_H__
#define __SHOTPLANLAYER_H__

#include "cocos2d.h"
#include "ShotPlanLayer.h"
#include "PlanPlayer.h"
#include "PlayerBullet.h"
#include "EnemyLayer.h"
#include "PauseLayer.h"

USING_NS_CC;

class ShotPlanLayer : public CCLayer
{
private:
	CCSprite * bgOne;
	CCSprite * bgSec;
	PlayerBullet * bulletLayer;
	EnemyLayer * enemyLayer;
	PauseLayer * mPauseLayer;
	int score;
public:
	ShotPlanLayer(void);
	~ShotPlanLayer(void);

	virtual void update(float dt);

	CREATE_FUNC(ShotPlanLayer);

	bool init();
	void backgroundMove(float f);

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	void registerWithTouchDispatcher();
	
};
#endif
