
#include<Ground.h>


bool Ground::init() {

    if (!Layer::init())
    {
        return false;
    }
    Size  visibleSize = Director::getInstance()->getVisibleSize(); 
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto ground = Sprite::create("ground.png");
    ground->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 5));
    auto groundBody = PhysicsBody::createBox(ground->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    groundBody->setDynamic(false);
    ground->setPhysicsBody(groundBody);

    this->addChild(ground);

   

}