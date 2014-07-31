#include "ShotPlanSecene.h"


ShotPlanSecene::ShotPlanSecene(void)
{
	mShotPlanLayer = NULL;
}


ShotPlanSecene::~ShotPlanSecene(void)
{
}


bool ShotPlanSecene::init(){
		bool bRet=false;  
		CCLOG("%s \n","plan secene init");
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(s_ShotPlanBgPList);
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(s_shotPlist);
		mShotPlanLayer = ShotPlanLayer::create();
		this->addChild(mShotPlanLayer);//add _gameLayerµ½³¡¾°ÖÐ  

		bRet=true;  
		return bRet;  
}