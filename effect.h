#ifndef EFFECT_H
#define EFFECT_H

#include "framework/component.h"
#include "framework/gameobject.h"
#include "framework/imagetransform.h"

class Effect : public Component
{
public:
    Effect(int id);
    void onAttach() override;
    void onUpdate(float deltaTime) override;
    int id;
    ImageTransform* imagetransform;
};

#endif // EFFECT_H
