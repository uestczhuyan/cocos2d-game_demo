#include "EnemyLayer.h"


int EnemyLayer::MMIN_SPEED = 300.0f;
int EnemyLayer::MAX_SPEED = 400.0f;
float EnemyLayer::BIGGEST_SPEED = 50.0f;
float EnemyLayer::BIGGEST_SHOW_TIME = 5;
int EnemyLayer::BIGGEST_SHOW_NUM = 200;

EnemyLayer::EnemyLayer(){
	enemyArray = CCArray::create();
	enemyArray->retain();

	schedule(schedule_selector(EnemyLayer::createEnemy),0.3f);
}

EnemyLayer::~EnemyLayer(){
	enemyArray->release();
	enemyArray = NULL;
}

void EnemyLayer::createEnemy(float delay){

	int num = rand()%10;
	Enemy * enemy;
	if(allCount%BIGGEST_SHOW_NUM ==0){
		enemy = new Enemy(500,1000,3,"enemy3_n1.png");
	}else if(num > 3){
		enemy = new Enemy(3,5,1,"enemy1.png");
	}else{
		enemy = new Enemy(5,10,2,"enemy2.png");
	}


	CCSize enemySize = enemy->getContentSize();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	int minX = enemySize.width/2;
	int maxX = winSize.width - enemySize.width/2;
	int posX = rand()%(maxX - minX) + minX;

	enemy->setPosition(ccp(posX,winSize.height+enemySize.height/2));
	this->addChild(enemy);
	this->getAllEnemy()->addObject(enemy);
	allCount++;

	float speed = rand()%(MAX_SPEED - MMIN_SPEED) + MMIN_SPEED;
	if(enemy->getType() == 3){
		speed = BIGGEST_SPEED;
	}
	float duration = (winSize.height + enemySize.height)/speed + 0.1f;
	CCSequence * se = CCSequence::create(CCMoveTo::create(duration,ccp(posX,-enemySize.height/2)),
		CCCallFuncN::create(this,callfuncN_selector(EnemyLayer::enemyMoveFinished)),NULL);
	
	enemy->runAction(se);
}

void EnemyLayer::enemyMoveFinished(CCNode * node){
	CCSprite * enemy = (CCSprite *) node;
	enemyArray->removeObject(enemy,true);
	this->removeChild(enemy);
}

void EnemyLayer::enemyDistoryed(Enemy * enemy){
	CCAnimation * animation;
	if(enemy->getType() ==1){
		animation = CCAnimationCache::sharedAnimationCache()->animationByName("enemy1_animation");
		if(animation == NULL){
			animation = SpriteHelper::animationWithSingleFrames("enemy1_down",4,0.07f);
			CCAnimationCache::sharedAnimationCache()->addAnimation(animation,"enemy1_animation");
		}
	}else if(enemy->getType()==2){
		animation = CCAnimationCache::sharedAnimationCache()->animationByName("enemy2_animation");
		if(animation == NULL){
			animation = SpriteHelper::animationWithSingleFrames("enemy2_down",4,0.07f);
			CCAnimationCache::sharedAnimationCache()->addAnimation(animation,"enemy2_animation");
		}
	}else{
		animation = CCAnimationCache::sharedAnimationCache()->animationByName("enemy3_animation");
		if(animation == NULL){
			animation = SpriteHelper::animationWithSingleFrames("enemy3_down",6,0.07f);
			CCAnimationCache::sharedAnimationCache()->addAnimation(animation,"enemy3_animation");
		}
	}

	CCSequence * seq = CCSequence::create(CCAnimate::create(animation),CCCallFuncN
		::create(this,callfuncN_selector(EnemyLayer::enemyMoveFinished)),NULL);
	enemy->runAction(seq);
}

int EnemyLayer::getAllCount(){
	return allCount;
}
int EnemyLayer::getScore(){
	return score;
}
CCArray * EnemyLayer::getAllEnemy(){
	return enemyArray;
}