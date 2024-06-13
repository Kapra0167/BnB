#include "player.h"
#include "physics.h"

#include "framework/gameobject.h"
#include "framework/transform.h"
#include "framework/gamescene.h"
#include "framework/imagetransform.h"
#include "framework/transformbuilder.h"
#include "qapplication.h"
#include <QTime>

#include <QGraphicsRectItem>
bool gameover=0;
Player::Player(int id) : Component(),id(id) {}

void Player::onAttach() {
  imagetransform = this->gameObject->getComponent<ImageTransform>();
  assert(imagetransform != nullptr );
}
void Player::onUpdate(float deltaTime) {
    if(gameover)destory(this->gameObject);
  if(id==1)
  {
      if(behitting>0){
          behitting--;
          if(behitting==1)
          this->imagetransform->setImage(":/p1s/h1");
          if(behitting==6)
          this->imagetransform->setImage(":/p1s/p1s0");
          return;
      }
      flycool++ ;
      if(flycool>=30)flycool-=30 ;
      if(flytype==1){
          if(flycool==0)
              this->imagetransform->setImage(":/p1s/p1w0");
          else if(flycool==10)
              this->imagetransform->setImage(":/p1s/p1w1");
          else if(flycool==20)
              this->imagetransform->setImage(":/p1s/p1w2");
      }else if(flytype==2){
          if(flycool==0)
              this->imagetransform->setImage(":/p1s/p1s0");
          else if(flycool==10)
              this->imagetransform->setImage(":/p1s/p1s1");
          else if(flycool==20)
              this->imagetransform->setImage(":/p1s/p1s2");

      }else if(flytype==3){
          if(flycool==0)
              this->imagetransform->setImage(":/p1s/p1a0");
          else if(flycool==10)
              this->imagetransform->setImage(":/p1s/p1a1");
          else if(flycool==20)
              this->imagetransform->setImage(":/p1s/p1a2");
      }else{
          if(flycool==0)
              this->imagetransform->setImage(":/p1s/p1d0");
          else if(flycool==10)
              this->imagetransform->setImage(":/p1s/p1d1");
          else if(flycool==20)
              this->imagetransform->setImage(":/p1s/p1d2");
      }
    }
  else if(id==2){
      if(behitting>0){
          behitting--;
          if(behitting==1)
          this->imagetransform->setImage(":/p2s/h2");
          if(behitting==6)
          this->imagetransform->setImage(":/p2s/p2s0");
          return;
      }
      flycool++ ;
      if(flycool>=30)flycool-=30 ;
      if(flytype==1){
          if(flycool==0)
              this->imagetransform->setImage(":/p2s/p2w0");
          else if(flycool==10)
              this->imagetransform->setImage(":/p2s/p2w1");
          else if(flycool==20)
              this->imagetransform->setImage(":/p2s/p2w2");
      }else if(flytype==2){
          if(flycool==0)
              this->imagetransform->setImage(":/p2s/p2s0");
          else if(flycool==10)
              this->imagetransform->setImage(":/p2s/p2s1");
          else if(flycool==20)
              this->imagetransform->setImage(":/p2s/p2s2");

      }else if(flytype==3){
          if(flycool==0)
              this->imagetransform->setImage(":/p2s/p2a0");
          else if(flycool==10)
              this->imagetransform->setImage(":/p2s/p2a1");
          else if(flycool==20)
              this->imagetransform->setImage(":/p2s/p2a2");
      }else{
          if(flycool==0)
              this->imagetransform->setImage(":/p2s/p2d0");
          else if(flycool==10)
              this->imagetransform->setImage(":/p2s/p2d1");
          else if(flycool==20)
              this->imagetransform->setImage(":/p2s/p2d2");
      }
  }
  else if(id==3){
      if(behitting>0){
          behitting--;
          if(behitting==1)
          this->imagetransform->setImage(":/bt3/bot3/h3.png");
          if(behitting==6)
          this->imagetransform->setImage(":/bt3/bot3/0.png");
          return;
      }
      flycool++ ;
      if(flycool>=30)flycool-=30 ;
      if(flytype==1){
          if(flycool==0)
              this->imagetransform->setImage(":/bt3/bot3/6.png");
          else if(flycool==10)
              this->imagetransform->setImage(":/bt3/bot3/7.png");
          else if(flycool==20)
              this->imagetransform->setImage(":/bt3/bot3/8.png");
      }else if(flytype==2){
          if(flycool==0)
              this->imagetransform->setImage(":/bt3/bot3/0.png");
          else if(flycool==10)
              this->imagetransform->setImage(":/bt3/bot3/1.png");
          else if(flycool==20)
              this->imagetransform->setImage(":/bt3/bot3/2.png");

      }else if(flytype==3){
          if(flycool==0)
              this->imagetransform->setImage(":/bt3/bot3/3.png");
          else if(flycool==10)
              this->imagetransform->setImage(":/bt3/bot3/4.png");
          else if(flycool==20)
              this->imagetransform->setImage(":/bt3/bot3/5.png");
      }else{
          if(flycool==0)
              this->imagetransform->setImage(":/bt3/bot3/9.png");
          else if(flycool==10)
              this->imagetransform->setImage(":/bt3/bot3/10.png");
          else if(flycool==20)
              this->imagetransform->setImage(":/bt3/bot3/11.png");
      }
  }

  else if(id==4){
      if(behitting>0){
          behitting--;
          if(behitting==1)
          this->imagetransform->setImage(":/bt4/bot4/h4.png");
          if(behitting==6)
          this->imagetransform->setImage(":/bt4/bot4/0.png");
          return;
      }
      flycool++ ;
      if(flycool>=30)flycool-=30 ;
      if(flytype==1){
          if(flycool==0)
              this->imagetransform->setImage(":/bt4/bot4/6.png");
          else if(flycool==10)
              this->imagetransform->setImage(":/bt4/bot4/7.png");
          else if(flycool==20)
              this->imagetransform->setImage(":/bt4/bot4/8.png");
      }else if(flytype==2){
          if(flycool==0)
              this->imagetransform->setImage(":/bt4/bot4/0.png");
          else if(flycool==10)
              this->imagetransform->setImage(":/bt4/bot4/1.png");
          else if(flycool==20)
              this->imagetransform->setImage(":/bt4/bot4/2.png");

      }else if(flytype==3){
          if(flycool==0)
              this->imagetransform->setImage(":/bt4/bot4/3.png");
          else if(flycool==10)
              this->imagetransform->setImage(":/bt4/bot4/4.png");
          else if(flycool==20)
              this->imagetransform->setImage(":/bt4/bot4/5.png");
      }else{
          if(flycool==0)
              this->imagetransform->setImage(":/bt4/bot4/9.png");
          else if(flycool==10)
              this->imagetransform->setImage(":/bt4/bot4/10.png");
          else if(flycool==20)
              this->imagetransform->setImage(":/bt4/bot4/11.png");
      }
  }
  else this->imagetransform->setImage("://test");
}
/*
void dielay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}*/
void Player::beHit(int pw)
{
    if(behitting==0)behitting=10;
    Health-=pw;
    if(Health<=0){
        destory(this->gameObject);
        //for(int i=1;i<=1000;i++)dielay();
    }
}
void Player::onDetach() {
    if(id<=2)
    {
        auto transform0=new ImageTransform();
        transform0->setPos(-450,-140);
        transform0->setImage("://over");
        auto endboard = new GameObject();
        endboard->addComponent(transform0);

        this->gameObject->sss()->attachGameObject(endboard);
        gameover=true;
    }
}
