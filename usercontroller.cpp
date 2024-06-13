#include "usercontroller.h"
#include "framework/transformbuilder.h"
#include <QGraphicsRectItem>
#include <QTime>
#include <QCoreApplication>
extern int mp[100][100];
extern int pushable[10];
int userpx[5];
int userpy[5];
UserController::UserController(int id) : Component(),id(id) {}

void UserController::onAttach()
{
    physics = this->gameObject->getComponent<Physics>();
    assert(physics != nullptr );

    player = this->gameObject->getComponent<Player>();
    assert(player != nullptr );
}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void UserController :: onUpdate (float deltaTime)
{
    if( getKey (Qt::Key_O) )
        for(int keep=0;keep<=10000000;keep++)
    {delay();if( getKey (Qt::Key_P))break;}

    float ax = 0 , ay = 0 , pv=player->speed;
    if(boomcool<21)boomcool++;
    if(id==1)
    {
        if( getKey (Qt::Key_D) ) {ax += 50/pv;player->settype(4);physics->setVelocity(6*pv,0);}
        if( getKey (Qt::Key_A) ) {ax -= 50/pv;player->settype(3);physics->setVelocity(-6*pv,0);}
        if( getKey (Qt::Key_S) ) {ay += 50/pv;player->settype(2);physics->setVelocity(0,6*pv);}
        if( getKey (Qt::Key_W) ) {ay -= 50/pv;player->settype(1);physics->setVelocity(0,-6*pv);}
        if( getKey (Qt::Key_Q) && boomcool>20 ) {
            boomcool=0;
            if(player->strong==1) player->moveable^=1;
            if(player->strong>=2)
            {
                if(player->moveable==1){player->moveable=0;pushable[id]=1;}
                else if(pushable[id]==1)pushable[id]=0;
                else player->moveable=1;
            }
        }
        if( getKey (Qt::Key_Space) &&player->booms>0 && boomcool>20 ) {
            if(player->super)
            {
                player->booms-=5;
                for(int tm=1;tm<=5;tm++)
                {
                    auto newboom = new GameObject();
                    ImageTransformBuilder()
                        .setPos(QPointF(physics->rex(), physics->rey()))
                        .setImage("://boom")
                        .setAlignment(Qt::AlignCenter)
                        .addToGameObject(newboom);
                    newboom->addComponent(new Physics);
                    newboom->addComponent(new Boom((physics->revx()+rand()%1000)*2,(physics->revy()+rand()%1000)*2,player));
                    attachGameObject(newboom);
                }
                player->super--;
            }else{
                player->booms--;
                auto newboom = new GameObject();
                ImageTransformBuilder()
                    .setPos(QPointF(physics->rex(), physics->rey()))
                    .setImage("://boom")
                    .setAlignment(Qt::AlignCenter)
                    .addToGameObject(newboom);
                newboom->addComponent(new Physics);
                newboom->addComponent(new Boom(2*player->moveable*physics->revx(),2*player->moveable*physics->revy(),player));
                attachGameObject(newboom);
                boomcool=0;
            }
        }
    }else if(id==2){
        if( getKey (Qt::Key_L) ) {ax += 50/pv;player->settype(4);physics->setVelocity(6*pv,0);}
        if( getKey (Qt::Key_J) ) {ax -= 50/pv;player->settype(3);physics->setVelocity(-6*pv,0);}
        if( getKey (Qt::Key_K) ) {ay += 50/pv;player->settype(2);physics->setVelocity(0,6*pv);}
        if( getKey (Qt::Key_I) ) {ay -= 50/pv;player->settype(1);physics->setVelocity(0,-6*pv);}
        if( getKey (Qt::Key_U) && boomcool>20 ) {
            boomcool=0;
            if(player->strong==1) player->moveable^=1;
            if(player->strong>=2)
            {
                if(player->moveable==1){player->moveable=0;pushable[id]=1;}
                else if(pushable[id]==1)pushable[id]=0;
                else player->moveable=1;
            }
        }
        if( getKey (Qt::Key_Return) &&player->booms>0&& boomcool>20) {
            if(player->super)
            {
                player->booms-=5;
                for(int tm=1;tm<=5;tm++)
                {
                    auto newboom = new GameObject();
                    ImageTransformBuilder()
                        .setPos(QPointF(physics->rex(), physics->rey()))
                        .setImage("://boom")
                        .setAlignment(Qt::AlignCenter)
                        .addToGameObject(newboom);
                    newboom->addComponent(new Physics);
                    newboom->addComponent(new Boom((physics->revx()+rand()%100)*10,(physics->revy()+rand()%100)*10,player));
                    attachGameObject(newboom);
                }
                player->super--;
            }else{
                player->booms--;
                auto newboom = new GameObject();
                ImageTransformBuilder()
                    .setPos(QPointF(physics->rex(), physics->rey()))
                    .setImage("://boom")
                    .setAlignment(Qt::AlignCenter)
                    .addToGameObject(newboom);
                newboom->addComponent(new Physics);
                newboom->addComponent(new Boom(2*player->moveable*physics->revx(),2*player->moveable*physics->revy(),player));
                attachGameObject(newboom);
                boomcool=0;
            }
        }
    }
    userpx[player->id]=physics->rex()/40+2;
    userpy[player->id]=physics->rey()/40+2;
    //qDebug()<<userpx<<" "<<userpy<<Qt::endl;

    int tpx=physics->rex();
    int tpy=physics->rey();
    int px=(tpx+20)/40+2;
    int py=tpy/40+2;

    physics ->setaty ( ax,ay ) ;
}
