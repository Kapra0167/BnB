#ifndef SCOREBOARD_H
#define SCOREBOARD_H


#include "framework/component.h"
#include "framework/gameobject.h"
#include "framework/transform.h"
#include "wall.h"
#include "physics.h"
#include "player.h"

class Scoreboard:public  Component
{
public:
    Scoreboard(Player* owner);

    void onAttach() override;
    void onUpdate(float deltaTime) override;


protected:
    QGraphicsSimpleTextItem* mytest;
    Transform *transform = nullptr;
    Player *owner = nullptr;
};


#endif // SCOREBOARD_H
