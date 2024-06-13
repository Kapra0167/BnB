#ifndef BOOM_H
#define BOOM_H

#include "framework/component.h"
#include "framework/gameobject.h"
#include "framework/imagetransform.h"
#include "wall.h"
#include "physics.h"
#include "player.h"

class Boom : public Component
{
public:
    explicit Boom(float vx,float vy,Player* owner);
    void onAttach() override;
    void onUpdate(float deltaTime) override;
    void onDetach() override;

    int pid;
    int pw;
    float vx,vy;
    int clock=250;
    ImageTransform* imagetransform;
    Physics* physics;
    Player* owner;
};

#endif // BOOM_H
