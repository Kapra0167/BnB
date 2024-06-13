#ifndef WALL_H
#define WALL_H

#include "framework/component.h"
#include "framework/gameobject.h"
#include "framework/imagetransform.h"


class Transform;

class Wall : public Component{
public:
    Wall();
    void onAttach() override;
    void onUpdate(float deltaTime) override;
    void befire();
protected:
ImageTransform *imagetransform = nullptr;
    int type;
};

#endif // WALL_H
