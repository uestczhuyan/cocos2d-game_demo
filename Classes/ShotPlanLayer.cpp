#include "ShotPlanLayer.h"


ShotPlanLayer::ShotPlanLayer(void)
{
	score = 0;
}


ShotPlanLayer::~ShotPlanLayer(void)
{
}

void ShotPlanLayer::registerWithTouchDispatcher(){
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);
}

bool ShotPlanLayer::init(){

	CCLOG ("%s \n", "init");

	//addChild(CCSpriteBatchNode::create(s_ShotPlanBgImage));
	bgOne = CCSprite::create();
	bgOne->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("background.png"));
	bgOne->setAnchorPoint(ccp(0,0));
	bgOne->setPosition(ccp(0,0));
	this->addChild(bgOne);

	bgSec = CCSprite::create();
	bgSec->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("background.png"));
	bgSec->setAnchorPoint(ccp(0,0));
	bgSec->setPosition(ccp(0,bgOne->getContentSize().height-2));
	this->addChild(bgSec);

	CCLOG("%s \n","start Schedule");
	this->schedule(schedule_selector(ShotPlanLayer::backgroundMove),1.0f/40.0f);  

	PlanPlayer * plan = PlanPlayer::SharedPlanPlayer();
	addChild(plan);		

	bulletLayer = new PlayerBullet();
	bulletLayer->init();
	bulletLayer->startShotOutBullet(0.1f);
	addChild(bulletLayer);

	enemyLayer = new EnemyLayer();
	addChild(enemyLayer);

	mPauseLayer = new PauseLayer();
	this->addChild(mPauseLayer);

	this->scheduleUpdate();

	setTouchEnabled(true);
	this->setKeypadEnabled(true);

	return true;
}

void ShotPlanLayer::backgroundMove(float f){
	bgOne->setPositionY(bgOne->getPositionY()-4);
	bgSec->setPositionY(bgOne->getPositionY()+bgOne->getContentSize().height-2);
	if(bgSec->getPositionY()<=4){
		bgOne->setPositionY(0);
	}
}

bool ShotPlanLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
	
	return true;
}

void ShotPlanLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
	if(CCDirector::sharedDirector()->isPaused()){
		return;
	}
	CCPoint startPoint = pTouch->getLocation();
	CCNode * plan =  PlanPlayer::SharedPlanPlayer()->getChildByTag(PlanPlayer::AIR_PLAN_TAG);
	CCRect planRect = plan->boundingBox();

	//origin 指的是rect的左下角的点坐标，如果要扩大rect，那么要保持rect的位置不变，势必会改变origin的大小
	planRect.origin.x -= 15;
	planRect.origin.y -= 15;
	planRect.size.width += 30;
	planRect.size.height += 30;

	if(planRect.containsPoint(pTouch->getPreviousLocation())){
		CCPoint endPoint = pTouch->getPreviousLocation();
		CCPoint offset = ccpSub(startPoint,endPoint);
		CCPoint toPoint = ccpAdd(plan->getPosition(),offset);

		PlanPlayer::SharedPlanPlayer()->planMoveTo(toPoint);
	}
}

void ShotPlanLayer::update(float f){
	CCArray * allDeletedBullet = CCArray::create();
	allDeletedBullet->retain();
	CCObject * bt;
	CCObject * et;
	int lost = 1;
	lost = score/100;
	if(score > 10){
		lost = 10;
	}else if(lost < 1){
		lost = 1;
	}
	CCARRAY_FOREACH(bulletLayer->getAllBullet(),bt){
		CCSprite * bullet = (CCSprite*) bt;
		CCArray* allDeletedEnemy = CCArray::create();
		allDeletedEnemy->retain();

		bool isadd = false;
		CCARRAY_FOREACH(enemyLayer->getAllEnemy(),et){
			Enemy * enemy = (Enemy *) et;
			if(bullet->boundingBox().intersectsRect(enemy->boundingBox())){
				if(enemy->isAlie()){
					if(enemy->lostLife(lost)){
						if(!isadd){
							allDeletedBullet->addObject(bullet);
							isadd = true;
						}else{
							CCLOG("%s \n","造成二次伤害");
						}
					}else{
						allDeletedEnemy->addObject(enemy);
						if(!isadd){
							allDeletedBullet->addObject(bullet);
							isadd = true;
						}else{
							CCLOG("%s \n","造成二次伤害");
						}

						score += enemy->getDieScore();
					}
				}
			}
			isadd = false;
		}
		CCARRAY_FOREACH(allDeletedEnemy,et){
			Enemy* enemy = (Enemy *)et;
			this->enemyLayer->enemyDistoryed(enemy);
		}
		allDeletedEnemy->removeAllObjects();
		allDeletedEnemy->release();
	}
	//CCLog("%d \n",allDeletedBullet->count());
	CCARRAY_FOREACH(allDeletedBullet,bt){
		CCSprite * bullet = (CCSprite *)bt;
		this->bulletLayer->bulletDistroyed(bullet);
	}
	allDeletedBullet->removeAllObjects();
	allDeletedBullet->release();
	
	mPauseLayer->updateScore(score);
}