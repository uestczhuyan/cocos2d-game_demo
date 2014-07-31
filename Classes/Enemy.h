#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "cocos2d.h"

USING_NS_CC;

class Enemy : public CCSprite{
private:
	 int lifeCount;
	 int dieScore;
	 int type;
	 bool alie;
	 
public:
	Enemy(int life,int score,int type,char * name);
	~Enemy();

	virtual int getLifeCount();
	virtual bool lostLife(int count);
	virtual bool isAlie();
	virtual void setLifeCount(int lifeCount);
	virtual void setDieScore(int sore);
	virtual int getDieScore();
	virtual int getType();

};

#endif