#include "SpriteHelper.h"
#include "cocos2d.h"

USING_NS_CC;

CCAnimation* SpriteHelper::animationWithSingleFrames(const char *name, int count, float delay){
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();

	CCArray *animFrames = new CCArray(count);

	char str[80];
	for(int k = 0; k < count; k++) 
	{
		sprintf(str, "%s%d.png", name, (k+1));
		CCSpriteFrame *frame = cache->spriteFrameByName(str);
		animFrames->addObject(frame);
	}

	CCAnimation *animation = CCAnimation::createWithSpriteFrames(animFrames, delay);

	return animation;
}