#ifndef __PLAYERBULLET_H__
#define __PLAYERBULLET_H__
#include "cocos2d.h"
#include "resource.h"
#include "PlanPlayer.h"

USING_NS_CC;
class PlayerBullet : public CCLayer
{
private :
	CCArray * allBullet;
	float bullet_speed;
	CCSpriteBatchNode * bulletBatchNode;

public:
	PlayerBullet(void);
	~PlayerBullet(void);

	virtual bool init();

	virtual CCArray* getAllBullet();
	virtual void startShotOutBullet();
	virtual void startShotOutBullet(float delay);
	virtual void stopShotOutBullet();
	virtual void setBulletSpeed(float speed);
	virtual void scheduleShot(float f);

	virtual void bulletMoveFinished(CCNode* node);
	virtual void bulletDistroyed(CCSprite* bullet);
};

#endif 