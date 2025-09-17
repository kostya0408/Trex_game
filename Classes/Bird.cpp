
#include <Bird.h>

bool Bird::init() {

    

    Size  visibleSize = Director::getInstance()->getVisibleSize(); // auto = Size;
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto bird = Sprite::create("ptera.png");
    bird->setPosition(Vec2(origin.x + visibleSize.width / 2 + 300, origin.y + visibleSize.height / 3 + 100));
    auto birdBody = PhysicsBody::createBox(Size(50, 50), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    birdBody->setCollisionBitmask(1);
    birdBody->setCategoryBitmask(4);
    birdBody->setContactTestBitmask(1);
    birdBody->setDynamic(false);
    bird->setPhysicsBody(birdBody);

    this->addChild(bird);
    

    return true;
}
