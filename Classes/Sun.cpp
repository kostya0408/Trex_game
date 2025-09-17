
#include <Sun.h>

bool Sun::init() {

    if (!Layer::init())
    {
        return false;
    }

    Size  visibleSize = Director::getInstance()->getVisibleSize(); // auto = Size;
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto Slunce = Sprite::create("cloud.png");
    Slunce->setPosition(Vec2(origin.x + visibleSize.width/2 + 200, origin.y + visibleSize.height/2 + 200));
    Slunce->setScale(3.0f);

    this->addChild(Slunce);

    return true;
}

