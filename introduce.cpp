
#include "introduce.h"
#include "framework/imagetransform.h"
#include "framework/gamescene.h"
#include "framework/transformbuilder.h"
#include <QFont>
#include <cstring>
extern bool gamestart;
Introduce::Introduce(int id) : Component(),id(id){}

void Introduce::onAttach() {
  imagetransform = this->gameObject->getComponent<ImageTransform>();
  Q_ASSERT(imagetransform != nullptr);
  // Handle mouse event of text by this->transform
  imagetransform->setFiltersChildEvents(true);
}
void Introduce::onClick(QGraphicsSceneMouseEvent *ev) {

    if(gamestart)
    {imagetransform->setPos(1000,1000);return;}
    auto gameScene=this->gameObject->sss();

    if(id==1)
    {
        auto intro = new GameObject();
        ImageTransformBuilder()
            .setPos(QPointF(360,280))
            .setImage("://intro")
            .setAlignment(Qt::AlignCenter)
            .addToGameObject(intro);
        intro->addComponent(new Transform);
        intro->addComponent(new Introduce(2));
        gameScene->attachGameObject(intro);
    }else{
        imagetransform->setPos(1200,1500);
    }
}
