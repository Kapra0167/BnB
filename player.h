#ifndef PLAYER_H
#define PLAYER_H

#include "framework/component.h"
#include "framework/gameobject.h"
#include "framework/transform.h"
#include "framework/imagetransform.h"

class ImageTransform;

class Player : public Component{
public:
 explicit Player(int id);
    void onAttach() override;
    void onUpdate(float deltaTime) override;

    void onDetach() override;
    void settype(int type){flytype=type;}
    void beHit(int pw);
    int pw=1;
    int id;
    float speed=0.4;
    int booms=1;
    int Health=600;
    int strong=0;
    int super=0;
    int moveable=0;
    bool beprotect=false;
    int flycool=0;
    int flytype=2;
    int behitting=0;

    protected:
    ImageTransform *imagetransform = nullptr;


};
#endif // PLAYER_H
