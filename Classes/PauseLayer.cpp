#include "PauseLayer.h"

bool PauseLayer::init(){

	CCLOG("%s \n","PauseLayer init()");
	/*setTouchEnabled(true);
	setTouchMode(kCCTouchesOneByOne);
	setTouchPriority(kCCMenuHandlerPriority+1);*/

	paseNormalSprite = CCSprite::createWithSpriteFrameName("game_pause_nor.png");
	paseSelectedSprite =CCSprite::createWithSpriteFrameName("game_pause_pressed.png");
	paseItem = CCMenuItemImage::create();
	paseItem->initWithNormalSprite(paseNormalSprite,paseSelectedSprite,
		NULL,this,menu_selector(PauseLayer::menuPaseCallBack));
	paseItem->setAnchorPoint(ccp(0,0));
	paseItem->setPosition(0,0);

	CCMenu* menu = CCMenu::create(paseItem,NULL);
	menu->setPosition(0,200);
	addChild(menu);

	scoreItem= CCLabelTTF::create();
	scoreItem->setColor(ccc3(143,146,147));
	scoreItem->setFontSize(30);
	scoreItem->setAnchorPoint(ccp(0,0));
	scoreItem->setString("000ssss");
	scoreItem->setPosition(ccp(50,200));
	this->addChild(scoreItem);
	return true;
}

void PauseLayer::updateScore(int score){
	CCString* strScore=CCString::createWithFormat("%d",score);
	scoreItem->setString(strScore->m_sString.c_str());
}

void PauseLayer::menuPaseCallBack(CCObject* pSender){
	CCLOG("%s \n","menuPaseCallBack");
	if(CCDirector::sharedDirector()->isPaused()){
		/*paseItem->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(""));
		paseItem->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(""));*/
		CCDirector::sharedDirector()->resume();
	}else{
		/*paseItem->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(""));
		paseItem->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(""));*/
		CCDirector::sharedDirector()->pause();
	}
}

PauseLayer::PauseLayer(){
	init();
}
PauseLayer::~PauseLayer(){

}