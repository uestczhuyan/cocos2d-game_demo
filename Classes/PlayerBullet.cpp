#include "PlayerBullet.h"


PlayerBullet::PlayerBullet(void)
{
	bullet_speed = 400.0f;
	allBullet = CCArray::create();
	allBullet->retain();
}


PlayerBullet::~PlayerBullet(void)
{
	allBullet->release();
	allBullet = NULL;
}

bool PlayerBullet:: init(){
	CCTexture2D * texture = CCTextureCache::sharedTextureCache()->addImage(s_shotImage);
	bulletBatchNode = CCSpriteBatchNode::createWithTexture(texture);
	addChild(bulletBatchNode);
	return true;
}

void PlayerBullet:: startShotOutBullet(float delay){
	schedule(schedule_selector(PlayerBullet::scheduleShot),delay);
}

void PlayerBullet:: startShotOutBullet(){
	startShotOutBullet(0.5f);
 }

void PlayerBullet::stopShotOutBullet(){
	unschedule(schedule_selector(PlayerBullet::scheduleShot));
}

void PlayerBullet::scheduleShot(float f){
	CCSprite * bullet = CCSprite::createWithSpriteFrameName("bullet1.png");
	bulletBatchNode->addChild(bullet);
	//addChild(bullet);

	CCNode * node = PlanPlayer::SharedPlanPlayer()->getChildByTag(PlanPlayer::AIR_PLAN_TAG);
	CCPoint pos = ccp(node->getPosition().x,node->getPosition().y+node->getContentSize().height/2);
	/*CCPoint pos = ccp(100,0);*/
	bullet->setPosition(pos);
	allBullet->addObject(bullet);

	float dur = 0.3f + (CCDirector::sharedDirector()->getWinSize().height - pos.y)/bullet_speed;
	CCSequence * seq = CCSequence::create(CCMoveTo::create(dur,ccp(pos.x,CCDirector::sharedDirector()->getWinSize().height+20)),
		CCCallFuncN::create(this,callfuncN_selector(PlayerBullet::bulletMoveFinished)),NULL);
	bullet->runAction(seq);
}
void PlayerBullet:: bulletMoveFinished(CCNode* node){
	CCSprite * bullet = (CCSprite*)node;
	allBullet->removeObject(bullet);
	this->bulletBatchNode->removeChild(bullet,true);
}

void PlayerBullet:: bulletDistroyed(CCSprite* bullet){
	if(allBullet->containsObject(bullet)){
		allBullet->removeObject(bullet);
		this->bulletBatchNode->removeChild(bullet,true);
	}
}


void PlayerBullet::setBulletSpeed(float speed){
	if(speed>0){
		this->bullet_speed = speed;
	}
}

CCArray* PlayerBullet::getAllBullet(){
	return allBullet;
}