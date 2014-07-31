#include "Enemy.h"

Enemy::Enemy(int life,int score,int type,char * name){
	initWithSpriteFrameName(name);
	this->lifeCount = life;
	this->dieScore = score;
	this->type = type;
	this->alie = true;
	//this->setFr(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name));
}
Enemy::~Enemy(){

}

int Enemy:: getLifeCount(){
	return lifeCount;
}
bool Enemy:: lostLife(int count){
	if(count <= 0){
		return true;
	}
	lifeCount -= count;
	if(lifeCount >0){
		return true;
	}else {
		alie = false;
		return false;
	}
}
void Enemy::setLifeCount(int lifeCount){
	this->lifeCount = lifeCount;
}
void Enemy::setDieScore(int sore){
	this->dieScore = sore;
}
int Enemy::getDieScore(){
	return dieScore;
}
int Enemy::getType(){
	return type;
}

bool Enemy::isAlie(){
	return alie;
}
