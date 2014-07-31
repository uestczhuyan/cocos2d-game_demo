#ifndef __PLANPLAYER_H__
#define __PLANPLAYER_H__
#include "cocos2d.h"
#include "SpriteHelper.h"

USING_NS_CC;

class PlanPlayer : public CCLayer
{
public:
	~PlanPlayer(void);
	virtual bool init();

	//virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

	virtual bool isAlive();

	virtual void planMoveTo(CCPoint p);

	static PlanPlayer* SharedPlanPlayer();

	static int AIR_PLAN_TAG;

private:
	static PlanPlayer* mPlayer ;
	CCMoveTo * moveToAction;
	bool alive;
	PlanPlayer(void);
};
#endif