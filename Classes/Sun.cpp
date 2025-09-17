
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

    auto Slunce_2 = Sprite::create("cloud.png");
    Slunce_2->setPosition(Vec2(origin.x + visibleSize.width / 2 , origin.y + visibleSize.height / 2 + 200));
    Slunce_2->setScale(3.0f);

    auto Slunce_3 = Sprite::create("cloud.png");
    Slunce_3->setPosition(Vec2(origin.x + visibleSize.width / 2 - 200, origin.y + visibleSize.height / 2 + 200));
    Slunce_3->setScale(3.0f);

    this->addChild(Slunce);
    this->addChild(Slunce_2);
    this->addChild(Slunce_3);


    return true;
}

