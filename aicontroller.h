#ifndef AICONTROLLER_H
#define AICONTROLLER_H


#include "framework/component.h"
#include "framework/gameobject.h"
#include "physics.h"
#include "player.h"
#include "boom.h"

class AiController : public Component
{
public:
    AiController(int id);

    void onAttach() override;
    void onUpdate(float deltaTime) override;
    int cul();
    bool nearwall();
    bool move_able(int px,int py,int type);
    int breath(int x,int y);
    int safeway_judge(int tx,int ty,int type);
    int danger(int px,int py,int type);
    int danger2(int px,int py,int type);
    int id;

    int lastanswer;
    int boomcool[5];
    int pickcool[5];

private:
    Physics *physics;
    Transform *transform;
    Player *player;
    Boom *boom;
};

#endif // AICONTROLLER_H
