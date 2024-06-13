#ifndef INTRODUCE_H
#define INTRODUCE_H
#include "framework/component.h"
#include "framework/imagetransform.h"
class Introduce:public  Component
{
public:
    Introduce(int id);
    int id;
    void onAttach() override;
    void onClick(QGraphicsSceneMouseEvent *ev) override;
    ImageTransform* imagetransform;
};
#endif // INTRODUCE_H
