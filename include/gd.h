#include "cocos2d.h"

class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite
{
public:
    CC_SYNTHESIZE(float, m_fScaleVar, ScaleVar);
    CC_SYNTHESIZE(float, m_fOriginalScale, OriginalScale);
    CC_SYNTHESIZE(bool, m_bShouldAnimate, ShouldAnimate);
    CC_SYNTHESIZE(bool, m_bDarkenClick, DarkenClick);
    CC_SYNTHESIZE(float, m_fVolume, Volume);
    CC_SYNTHESIZE(const char*, m_pClickSound, ClickSound);

    static CCMenuItemSpriteExtra* create(cocos2d::CCNode* sprite, cocos2d::CCNode* unk, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback);
};

class AchievementNotifier
{
public:
    static AchievementNotifier* sharedState();
    void notifyAchievement(const char* title, const char* description, const char* icon);
};

class MenuLayer : public cocos2d::CCLayer
{
public:
    static void onMoreGames();
};

class LoadingLayer : public cocos2d::CCLayer
{
public:
    static const char* getLoadingString();
};
