#include "SecondScene.h"

USING_NS_CC;

CCScene* SecondScene::scene()
{
	CCScene* scene = CCScene::create();
	SecondScene* layer = SecondScene::create();
	scene->addChild(layer);
	return scene;
}

bool SecondScene::init()
{
	if (!CCLayer::init()) {
		return false;
	}

	CCLayer::create();
	CCSize screenSize = CCDirector::sharedDirector()->getVisibleSize();

	CCLabelTTF* label = CCLabelTTF::create("Hello, this is the second scene!", "Arial", 40);
	label->setPosition(ccp(screenSize.width / 2, screenSize.height / 2));
	this->addChild(label);
	
	//Add a button
	CCMenuItemImage* pCloseItem = CCMenuItemImage::create("CloseNormal.png"
														, "CloseSelected.png"
														, this
														, menu_selector(SecondScene::BtnClick)
														);
	pCloseItem->setPosition(ccp(screenSize.width / 2, screenSize.height / 2 - 160));
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	bird = CCSprite::create("bird1.png");
	bird->setPosition(ccp(0, screenSize.height / 2) );
	this->addChild(bird);

	bird->runAction(createBirdAnimate());
	

	return true;
}

void SecondScene::popScene(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}

CCAnimate* SecondScene::createBirdAnimate()
{
	//Add a bird
	CCSpriteFrame* frame = nullptr;
	CCArray* frameArray = CCArray::create();

	//用一个列表保存所有的CCSpriteFrame对象
	for (int i = 1; i <= 3; i++) {
		frame = CCSpriteFrame::create(CCString::createWithFormat("bird%d.png", i)->getCString(), CCRectMake(0, 0, 85, 60));
		frameArray->addObject(frame);
	}

	CCAnimation* animation = CCAnimation::createWithSpriteFrames(frameArray);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.3f);

	//将动画包装成一个动作
	CCAnimate* action = CCAnimate::create(animation);

	return action;
}

void SecondScene::BtnClick(CCObject* pSender)
{
	CCSize screenSize = CCDirector::sharedDirector()->getVisibleSize();
	CCMoveTo* moveTo = CCMoveTo::create(10.0f, ccp(screenSize.width, screenSize.height / 2));
	bird->runAction(moveTo);
}