#ifndef __SHOTPLANSECENE_H__
#define __SHOTPLANSECENE_H__

#include "cocos2d.h"
#include "ShotPlanLayer.h"
#include "resource.h"
#include "PauseLayer.h"

USING_NS_CC;

class ShotPlanSecene : public CCScene
{
	ShotPlanLayer * mShotPlanLayer;
public:
	ShotPlanSecene(void);
	~ShotPlanSecene(void);
	
	virtual bool init();
	CREATE_FUNC(ShotPlanSecene);

};
#endif
