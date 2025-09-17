#include "HelloWorldScene.h"
#include"Sun.h"
#include"Ground.h"
#include"Bird.h"
#include"Cactus.h"

USING_NS_CC;

Scene* Trex::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);

    scene->getPhysicsWorld()->setGravity(Vect(0, -200.0));
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto Sonce = Sun::create();
    scene->addChild(Sonce, 2);

    auto Zemlya = Ground::create();
    scene->addChild(Zemlya, 3);

    auto Cacctus = Cactus::create();
    scene->addChild(Cacctus, 3);

    auto Ptah = Bird::create();
    scene->addChild(Ptah, 3);

  

    auto layer = Trex::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer, 0);



    auto Layer1 = cocos2d::LayerColor::create(Color4B(0, 255, 0, 255));
    scene->addChild(Layer1, -3);

   

    return scene;
   
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Trex::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    Size  visibleSize = Director::getInstance()->getVisibleSize(); // auto = Size;
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /*auto background = LayerColor::create(Color4B(173, 216, 230, 255));*/
  /*  this->addChild(background, -1);*/

    /* ground = Sprite::create("ground.png");
    ground->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 3));
     groundBody = PhysicsBody::createBox(ground->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    groundBody->setDynamic(false);
    ground->setPhysicsBody(groundBody);

    this->addChild(ground);*/

    //cactus_1 = Sprite::create("cactus1.png");
    //cactus_1->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height / 3 + 50));
    //cactus_1Body = PhysicsBody::createBox(Size(45, 150), PhysicsMaterial(0.0f, 0.0f, 0.0f)); //густина, пружність, тертя
    //cactus_1Body->setDynamic(false);
    //cactus_1Body->setCollisionBitmask(1);
    //cactus_1Body->setCategoryBitmask(2);
    //cactus_1Body->setContactTestBitmask(1);
    //cactus_1->setPhysicsBody(cactus_1Body);
    //cactus_1->setScale(0.7f);


    /*this->addChild(cactus_1);*/

     rex = Sprite::create("dino.png");
    rex->setPosition(Vec2(origin.x + visibleSize.width / 2 - 300, origin.y + visibleSize.height / 3 + 50));
     rexBody = PhysicsBody::createBox(Size(80, 85), PhysicsMaterial(50.0f, 0.0f, 0.0f));
     rexBody->setCollisionBitmask(6);
     rexBody->setCategoryBitmask(1);
     rexBody->setContactTestBitmask(6);
    rexBody->setDynamic(true);
    rex->setPhysicsBody(rexBody);

    this->addChild(rex);

   /* bird = Sprite::create("ptera.png");
    bird->setPosition(Vec2(origin.x + visibleSize.width / 2 - 300, origin.y + visibleSize.height / 3 + 250));
    birdBody = PhysicsBody::createBox(Size(50, 50), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    birdBody->setCollisionBitmask(1);
    birdBody->setCategoryBitmask(4);
    birdBody->setContactTestBitmask(1);
    birdBody->setDynamic(false);
    bird->setPhysicsBody(birdBody);

    this->addChild(bird);*/

    

    ++score;
    tempScore = StringUtils::format("%i", score);

    scoreLabel = Label::createWithTTF(tempScore.c_str(), "fonts/Marker Felt.ttf", 33);
    scoreLabel->setColor(Color3B::WHITE);
    scoreLabel->setPosition(Point(visibleSize.width / 2 - 100, visibleSize.height - 22));

    this->scheduleUpdate(); // вмикає виклик update(dt)

    this->addChild(scoreLabel);


    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Trex::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    

    /*rex->runAction(rexJump);*/

    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(Trex::onKeyPressed, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    


    /*auto rexMove = MoveBy::create(2, Vec2(50, 100));

    rex->runAction(rexMove);*/
   
   /* auto mySprite = Sprite::create("man.png");
    mySprite->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    auto mySprite_body = PhysicsBody::createBox(mySprite->getContentSize(), PhysicsMaterial(0.5f, 1.0f, 0.3f));
    mySprite_body->setLinearDamping(0.3f);
    mySprite_body->setDynamic(true);
    mySprite->setPhysicsBody(mySprite_body);
    mySprite->setScale(0.5f);
    
    this->addChild(mySprite);*/
   
   
    return true;
}

void Trex::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    auto rexJump = JumpBy::create(2, Vec2(50, 0), 50, 1);

    
        rex->runAction(rexJump);
        
    
}

void Trex::update(float dt)
{

    score += dt * 100; // збільшуємо score пропорційно часу
    scoreLabel->setString(StringUtils::format("Score: %d", (int)score));
}

//void count_scores() {
//    
//    ++score;
//    std::string tempScore = StringUtils::format("%i", score);
//    scoreLabel->setString(tempScore.c_str());
//
//}


bool Trex::onContactBegin(PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    int coll_A = nodeA->getPhysicsBody()->getCollisionBitmask();
    int cat_A = nodeA->getPhysicsBody()->getCategoryBitmask();
    int cont_A = nodeA->getPhysicsBody()->getContactTestBitmask();
    int coll_B = nodeB->getPhysicsBody()->getCollisionBitmask();
    int cat_B = nodeB->getPhysicsBody()->getCategoryBitmask();
    int cont_B = nodeB->getPhysicsBody()->getContactTestBitmask();

    /*nodeB->removeFromParentAndCleanup(true);
    nodeA->removeFromParentAndCleanup(true);*/
    if (nodeA && nodeB)
    {
          
        if ((cat_A  & cont_B) || (cat_A & cont_B))
        {
            auto moveRex = MoveBy::create(1, Vec2(-200, 0));

            rex->runAction(moveRex);
        }
      
        /*else if (((nodeA->getPhysicsBody()->getCollisionBitmask() == 3) && (nodeB->getPhysicsBody()->getCollisionBitmask() == 2)) || ((nodeA->getPhysicsBody()->getCollisionBitmask() == 2) && (nodeB->getPhysicsBody()->getCollisionBitmask() == 3)))
        {

            if (nodeA->getTag() == 2)
            {

                nodeB->removeFromParentAndCleanup(true);
            }
            else if (nodeB->getTag() == 1)
            {
                nodeA->removeFromParentAndCleanup(true);
            }
        }*/
    }
    return true;
}

void Trex::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
