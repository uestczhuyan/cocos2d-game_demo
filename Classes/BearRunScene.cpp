#include "BearRunScene.h"
#include "SpriteHelper.h"


bool BearRunScene::init(){

	setTouchEnabled(true);

	CCSize s = CCDirector::sharedDirector()->getWinSize();
	bear = CCSprite::create("bear1.png");
	bear->setAnchorPoint(ccp(0,0.5));
	bear->setPosition(ccp(10,s.height /2));
	addChild(bear,0);


	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bear.plist");
	//CCSpriteBatchNode* node = CCSpriteBatchNode::create("bear.png");
	//addChild(node);

	//animation = SpriteHelper::animationWithSingleFrames("bear",8,0.1f);
	//bear->runAction(CCMoveTo::create(duration,after));
	bear->setFlipX(true);
	return true;
}


void BearRunScene::moveCallBack(){
	isMoving = false;
	bear->stopAllActions();
}

void BearRunScene::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);

	CCPoint after = touch->getLocation();

	bear->stopAllActions();

	CCRepeatForever * animate = CCRepeatForever::create(CCAnimate::create(SpriteHelper::animationWithSingleFrames("bear",8,0.1f)));
	CCPoint  now = bear->getPosition();
	float speed = 320.f;
	if(now.x > after.x){
		bear->setFlipX(false);
	}else{
		bear->setFlipX(true);
	}
	float duration = ccpLength(ccpSub(after,now))/speed;

	bear->runAction(animate);
	bear->runAction(CCSequence::create(CCMoveTo::create(duration,after),
		CCCallFunc::create(this,callfunc_selector(BearRunScene::moveCallBack)),NULL));
	isMoving = true;
}

bool BearRunScene::isMovingNow(){
	return isMoving;
}



BearRunScene::~BearRunScene(void)
{
	/*moveAction->release();
	walkAction->release();*/
}
