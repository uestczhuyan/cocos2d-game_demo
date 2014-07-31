#ifndef __ENEMYLAYER_H__
#define __ENEMYLAYER_H__
#include "cocos2d.h"
#include "resource.h"
#include "Enemy.h"
#include "SpriteHelper.h"

USING_NS_CC;

class EnemyLayer : public CCLayer
{
public:
	EnemyLayer(void);
	~EnemyLayer();

	virtual int getAllCount();
	virtual int getScore();
	virtual CCArray * getAllEnemy();
	virtual void createEnemy(float delay);

	virtual void enemyMoveFinished(CCNode * node);
	void enemyDistoryed(Enemy * enemy);
protected:
private:
	CCArray * enemyArray;
	int allCount;
	int score;

	static int MMIN_SPEED;
	static int MAX_SPEED;
	static float BIGGEST_SPEED;
	static float BIGGEST_SHOW_TIME;
	static int BIGGEST_SHOW_NUM;
};


#endif