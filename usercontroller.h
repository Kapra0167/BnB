#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "framework/component.h"
#include "framework/gameobject.h"
#include "physics.h"
#include "player.h"
#include "boom.h"

class UserController : public Component
{
public:
    UserController(int id);

    void onAttach() override;
    void onUpdate(float deltaTime) override;

    int id;
    int boomcool;

private:
    Physics *physics;
    Transform *transform;
    Player *player;
    Boom *boom;
};

#endif // USERCONTROLLER_H
