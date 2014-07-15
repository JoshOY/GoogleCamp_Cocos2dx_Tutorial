#ifndef __SECOND_SCENE_H__
#define __SECOND_SCENE_H__

#include "cocos2d.h"

class SecondScene : public cocos2d::CCLayer
{
public:
	static cocos2d::CCScene* scene();
	virtual bool init();
	CREATE_FUNC(SecondScene);

	//pop this scene
	void popScene(CCObject* pSender);

	//create bird animate
	cocos2d::CCAnimate* createBirdAnimate();

	//fly action
	void BtnClick(CCObject* pSender);

	cocos2d::CCSprite* bird;
};


#endif