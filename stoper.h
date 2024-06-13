#ifndef STOPER_H
#define STOPER_H

#include "framework/component.h"

class Stoper:public  Component
{
public:
    Stoper();

    void onAttach() override;
    void onClick(QGraphicsSceneMouseEvent *ev) override;
};

#endif // STOPER_H
