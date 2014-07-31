#include "PlanPlayer.h"


PlanPlayer::~PlanPlayer(void)
{
	alive = true;
}

PlanPlayer::PlanPlayer(void){

}
PlanPlayer* PlanPlayer::mPlayer = NULL;
int PlanPlayer::AIR_PLAN_TAG = 100001;


PlanPlayer* PlanPlayer::SharedPlanPlayer()
{
	if(!mPlayer){
		mPlayer = new PlanPlayer();
		mPlayer->init();
	}
	return mPlayer;
}

bool PlanPlayer::init(){

	//setTouchEnabled(true);

	CCSize s = CCDirector::sharedDirector()->getWinSize();
	CCSprite * plan = CCSprite::createWithSpriteFrame(
				CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("hero1.png"));
	plan->setPosition(ccp(s.width/2,plan->getContentSize().height));
	this->addChild(plan,0,AIR_PLAN_TAG);

	CCBlink * blink = CCBlink::create(0.6,4);

	CCAnimation * animation = SpriteHelper::animationWithSingleFrames("hero",2,0.2f);
	plan->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
	plan->runAction(blink);

	return true;
}

bool PlanPlayer::isAlive(){
	return alive;
}
void PlanPlayer:: planMoveTo(CCPoint after){
	//对于after 移动到的目的地进行边界判断
	CCNode * node = getChildByTag(AIR_PLAN_TAG);
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	if(after.y >= s.height/2.0f - node->getContentSize().height){
		after.y = s.height/2.0f - node->getContentSize().height;
	}else if(after.y<= node->getContentSize().height/2.0f+50){
		after.y = node->getContentSize().height/2.0f+50;
	}

	if(after.x>=s.width - node->getContentSize().width/2.0f){
		after.x = s.width - node->getContentSize().width/2.0f;
	}else if(after.x <= node->getContentSize().width/2.0f){
		after.x = node->getContentSize().width/2.0f;
	}
	
	node->setPosition(after);
}


//void PlanPlayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent){
//
//	CCSetIterator it = pTouches->begin();
//	CCTouch* touch = (CCTouch*)(*it);
//	
//	
//	CCNode * node = getChildByTag(AIR_PLAN_TAG);
//	node->stopActionByTag(3000);
//
//	CCPoint after = touch->getLocation();
//
//	//对于after 移动到的目的地进行边界判断
//	CCSize s = CCDirector::sharedDirector()->getWinSize();
//	if(after.y >= s.height/2.0f - node->getContentSize().height){
//		after.y = s.height/2.0f - node->getContentSize().height;
//	}else if(after.y<= node->getContentSize().height/2.0f+50){
//		after.y = node->getContentSize().height/2.0f+50;
//	}
//
//	if(after.x>=s.width - node->getContentSize().width/2.0f){
//		after.x = s.width - node->getContentSize().width/2.0f;
//	}else if(after.x <= node->getContentSize().width/2.0f){
//		after.x = node->getContentSize().width/2.0f;
//	}
//
//
//	CCLog("%s %f %f\n","after",after.x,after.y);
//	CCPoint  now = node->getPosition();
//	float speed = 300.f;
//	float duration = ccpLength(ccpSub(after,now))/speed;
//	moveToAction = CCMoveTo::create(duration,after);
//	moveToAction->setTag(3000);
//	node->runAction(moveToAction);
//}