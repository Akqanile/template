#include <dobby.h>
#include <dlfcn.h>
#include "cocos2d.h"
#include "gd.h"

void* get_sym_addr(const char* sym_name)
{
    auto handle = dlopen("libgame.so", RTLD_NOW);
    return dlsym(handle, sym_name);
}


class Callback
{
public:
    void example(cocos2d::CCObject*)
    {
        AchievementNotifier::sharedState()->notifyAchievement("Title", "Description", NULL);
    }
};

bool (*OMenuLayer_init)(MenuLayer*);
bool HMenuLayer_init(MenuLayer* self)
{
    if (!OMenuLayer_init(self))
        return false;
    
    auto sprite = cocos2d::CCSprite::createWithSpriteFrameName("GJ_gkBtn_001.png");
    auto menu_sprite = CCMenuItemSpriteExtra::create(sprite, nullptr, (cocos2d::CCObject*)self, (cocos2d::SEL_MenuHandler)&Callback::example);

    auto menu = cocos2d::CCMenu::create();
    menu->addChild(menu_sprite);

    self->addChild(menu);

    auto win_size = cocos2d::CCDirector::sharedDirector()->getWinSize();
    menu_sprite->setPosition(menu->convertToNodeSpace(
        cocos2d::CCPoint(win_size.width - sprite->getContentSize().width, win_size.height / 2))
    );

    return true;
}

const char*(*OLoadingLayer_getLoadingString)(LoadingLayer*);
const char* HLoadingLayer_getLoadingString(LoadingLayer* self)
{
    return "Hooked LoadingLayer";
}


[[gnu::constructor]]
void constructor()
{
    // For non-static functions you have to use get_sym_addr
    DobbyHook(reinterpret_cast<void*>(&LoadingLayer::getLoadingString), (void*)HLoadingLayer_getLoadingString, (void**)&OLoadingLayer_getLoadingString);
    DobbyHook(get_sym_addr("_ZN9MenuLayer4initEv"), (void*)HMenuLayer_init, (void**)&OMenuLayer_init);
}
