#include "UiEditLayer.h"

UiEditLayer::UiEditLayer(){
	inti();
}
UiEditLayer::~UiEditLayer(){

}
void UiEditLayer::inti(){
	UILayer * layer = UILayer::create();
	UIWidget * node = GUIReader::shareReader()->widgetFromJsonFile("uiedit/DemoShop.ExportJson");
	layer->addWidget(node);
	UIButton * btn = (UIButton *)node->getChildByName("back_Button");
	btn->addTouchEventListener(this,toucheventselector(UiEditLayer::onClickBackButton));
	addChild(layer);
}
void UiEditLayer::onClickBackButton(CCObject *sender,TouchEventType type){
	//CCLOG("%s \n","click back buttons");
	switch (type)
	{
	case TOUCH_EVENT_BEGAN:
		CCLOG("%s \n","click back buttons begin");
		break;
	case TOUCH_EVENT_MOVED:
		CCLOG("%s \n","click back buttons moved");
		break;
	case TOUCH_EVENT_ENDED:
		CCLOG("%s \n","click back buttons end");
		break;
	}
}