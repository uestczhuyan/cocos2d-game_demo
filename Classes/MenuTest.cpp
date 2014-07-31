#include "MenuTest.h"
#include "cocos2d.h"
#include "resource.h"
#include "BearRunScene.h"
#include "ShotPlanSecene.h"

using namespace cocos2d;
MenuLayerMainMenu::MenuLayerMainMenu(void){
		setTouchEnabled(true);
		setTouchMode(kCCTouchesOneByOne);
		setTouchPriority(kCCMenuHandlerPriority+1);

		CCSprite* itemNor = CCSprite::create(s_MenuItem,CCRectMake(0,23*2,115,23));
		CCSprite* itemSelected = CCSprite::create(s_MenuItem,CCRectMake(0,23*1,115,23));
		CCSprite* itemDisAbled = CCSprite::create(s_MenuItem,CCRectMake(0,23*0,115,23));

		CCMenuItemSprite* menuItem1 = CCMenuItemSprite::create(itemNor,itemSelected,
			itemDisAbled,this,menu_selector(MenuLayerMainMenu::menuChangeUiEditCallBack));
		CCMenuItemImage* menuItem2 = CCMenuItemImage::create("SendScoreButton.png","SendScoreButtonPressed.png",
			this,menu_selector(MenuLayerMainMenu::menuCloseCallback));
		CCMenuItemImage* item3 = CCMenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			this,
			menu_selector(MenuLayerMainMenu::menuCloseCallback));
		
		// Font Item
		CCMenuItemFont *item4 = CCMenuItemFont::create("Start Game", this, menu_selector(MenuLayerMainMenu::menuStartGame) );

		item4->setFontSizeObj(30);
		item4->setFontName("Marker Felt");

		CCMenuItemFont *item5 = CCMenuItemFont::create("Quite Game", this, menu_selector(MenuLayerMainMenu::menuCloseCallback) );

		item5->setFontSizeObj(30);
		item5->setFontName("Marker Felt");

		CCMenuItemFont *item6 = CCMenuItemFont::create("Start Shot Plan Game", this, menu_selector(MenuLayerMainMenu::menuStartAirGame) );

		item6->setFontSizeObj(30);
		item6->setFontName("Marker Felt");

		CCSize size = CCDirector::sharedDirector()->getWinSize();

		CCMenu* menu = CCMenu::create(item5,menuItem1,menuItem2,item3,item6,item4,NULL);

		int i=0;
		CCNode* child;
		CCArray * pArray = menu->getChildren();
		CCObject* pObject = NULL;
		CCARRAY_FOREACH(pArray, pObject)
		{
			if(pObject == NULL)
				break;

			child = (CCNode*)pObject;

			CCPoint dstPoint = child->getPosition();
			int offset = (int) (size.width/2 + 50);
			if( i % 2 == 0)
				offset = -offset;

			child->setPosition( ccp( dstPoint.x + offset, i*40 - 40) );
			child->runAction( 
				CCEaseElasticOut::create(CCMoveBy::create(2, ccp(dstPoint.x - offset,0)), 0.35f) 
				);
			i++;
		}


		addChild(menu);
		menu->setPosition(ccp(size.width/2, size.height/2));
}

MenuLayerMainMenu::~MenuLayerMainMenu(){
	m_disabledItem->release();
}

 bool MenuLayerMainMenu :: ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent * pEvent){
	return true;
 }
 void MenuLayerMainMenu :: ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent * pEvent){
 }
 void MenuLayerMainMenu :: ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent * pEvent){
 }
 void MenuLayerMainMenu :: ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent * pEvent){
 }

 void MenuLayerMainMenu :: allowTouches(float dt){
	cocos2d:: CCDirector* mCCDirector = cocos2d::CCDirector::sharedDirector();
	mCCDirector->getTouchDispatcher()->setPriority(cocos2d::kCCMenuHandlerPriority+1,this);
	this->unscheduleAllSelectors();
 }
 void MenuLayerMainMenu :: menuCallback(CCObject* pSender){
	 
 }

 void MenuLayerMainMenu::menuCloseCallback(CCObject* pSender){
	 CCDirector::sharedDirector()->end();
 }

 void MenuLayerMainMenu::menuStartGame(CCObject* pSender){
	 CCDirector* director = CCDirector::sharedDirector();
	 director->purgeCachedData();
	 CCScene* ccscene = CCScene::create();
	 ccscene->addChild(BearRunScene::create());
	 director->replaceScene(ccscene);
 }


 void MenuLayerMainMenu::menuStartAirGame(CCObject* pSender){
	 CCDirector* director = CCDirector::sharedDirector();
	 director->purgeCachedData();
	 CCScene* ccscene = ShotPlanSecene::create();
	 CCLOG ("%s \n", "menuStartAirGame");
	 director->replaceScene(ccscene);
 }

 void MenuLayerMainMenu::menuChangeUiEditCallBack(CCObject *pSender){
	 CCDirector* director = CCDirector::sharedDirector();
	 director->purgeCachedData();
	 CCScene* ccscene = CCScene::create();
	 ccscene->addChild(new UiEditLayer());
	 director->replaceScene(ccscene);
 }