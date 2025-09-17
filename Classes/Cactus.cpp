
#include<Cactus.h>

bool Cactus::init() {

    if (!Layer::init())
    {
        return false;
    }
    Size  visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto cactus_1 = Sprite::create("cactus1.png");
    cactus_1->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height / 5 + 60));
    auto cactus_1Body = PhysicsBody::createBox(Size(45, 150), PhysicsMaterial(0.0f, 0.0f, 0.0f)); //густина, пружність, тертя
    cactus_1Body->setDynamic(false);
    cactus_1Body->setCollisionBitmask(1);
    cactus_1Body->setCategoryBitmask(2);
    cactus_1Body->setContactTestBitmask(1);
    cactus_1->setPhysicsBody(cactus_1Body);
    cactus_1->setScale(0.7f);

    this->addChild(cactus_1);

    auto cactus_2 = Sprite::create("cactus1.png");
    cactus_2->setPosition(Vec2(origin.x + visibleSize.width / 2 - 100, origin.y + visibleSize.height / 5 + 60));
    auto cactus_2Body = PhysicsBody::createBox(Size(45, 150), PhysicsMaterial(0.0f, 0.0f, 0.0f)); //густина, пружність, тертя
    cactus_2Body->setDynamic(false);
    cactus_2Body->setCollisionBitmask(1);
    cactus_2Body->setCategoryBitmask(2);
    cactus_2Body->setContactTestBitmask(1);
    cactus_2->setPhysicsBody(cactus_2Body);
    cactus_2->setScale(0.7f);

    this->addChild(cactus_2);

}