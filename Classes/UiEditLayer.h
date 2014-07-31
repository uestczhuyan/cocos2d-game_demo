#ifndef __UIEDITLAYER_H__
#define __UIEDITLAYER_H__

#include "cocos2d.h"
#include "cocos-ext.h"


using namespace cocos2d::extension;
using namespace cocos2d::gui;
USING_NS_CC;

class UiEditLayer : public CCLayer{

public:
	UiEditLayer();
	~UiEditLayer();
	void inti();
	void onClickBackButton(CCObject *sender,TouchEventType type);
};
#endif