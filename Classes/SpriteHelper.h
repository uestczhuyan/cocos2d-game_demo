#pragma once
#ifndef __SPRITEHELPER_H__
#define __SPRITEHELPER_H__

#include "cocos2d.h"

USING_NS_CC;
class SpriteHelper
{
public:
	static	CCAnimation* animationWithSingleFrames(const char *name, int count, float delay);
};
#endif
