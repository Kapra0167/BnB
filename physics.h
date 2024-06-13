#ifndef PHYSICS_H
#define PHYSICS_H

#include "framework/component.h"
#include "framework/gameobject.h"
#include "framework/transform.h"

class Physics : public Component
{
public:
    Physics();

    void onAttach() override;
    void onUpdate(float deltaTime) override;
    int rex(){return transform->pos().x();}
    int rey(){return transform->pos().y();}

    float revx(){return vx;}
    float revy(){return vy;}

    void setVelocity(int x,int y);
    void setaty(float vx,float vy);

private:
    Transform *transform;
    float vx=0,vy=0;
    float ax=0,ay=0;
};

#endif // PHYSICS_H
