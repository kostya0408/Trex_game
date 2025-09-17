

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;


class Trex : public Scene
{
public:
    static  Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback( Ref* pSender);
    void SetPhysicsWorld( PhysicsWorld* world) { sceneWorld = world; };
     PhysicsWorld* sceneWorld;


     Sprite* ground;
     PhysicsBody* groundBody;
    
     Sprite* cactus_1;
     PhysicsBody* cactus_1Body;

     Sprite* bird;
     PhysicsBody* birdBody;

    unsigned int score = 0;
     Label* scoreLabel;
    std::string tempScore;

     Layer* hudLayer;

    void update(float dt);

    bool onContactBegin( PhysicsContact& contact);
        
     Sprite* rex;
     PhysicsBody* rexBody;
     JumpBy* rexJump;
    void onKeyPressed( EventKeyboard::KeyCode keyCode,  Event* event);

    /* MoveBy* rexMove;*/
    // implement the "static create()" method manually
    CREATE_FUNC(Trex);
};


#endif // __HELLOWORLD_SCENE_H__
