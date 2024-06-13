#include "physics.h"
#include "player.h"
#include "wall.h"
#include "framework/gamescene.h"
extern int mp[100][100];
extern short boommp[100][100];
extern int pushable[10];
Physics::Physics(){}

void Physics::onAttach(){
    this->transform = this->gameObject->getComponent<Transform>();
    Q_ASSERT(this->transform != nullptr);
}

void Physics::onUpdate(float deltaTime)
{

    auto findplayer=this->gameObject->getComponent<Player>();
    if(findplayer!=nullptr)
    {

        vx+=deltaTime*(ax-1.2*vx);
        vy+=deltaTime*(ay-1.2*vy);
        int px=transform->pos().x()+deltaTime  *vx;
        int py=transform->pos().y()+deltaTime  *vy-10;
        int h=100,v=0,v2=0,v3=0;
            if(mp[(h-v+px)/40][(h+py)/40]>=2
            ||(mp[(h+v+px)/40][(h+py)/40]>=2)
            ||(mp[(h+px)/40][(h-v+py)/40]>=2)
            ||(mp[(h+px)/40][(h+v+py)/40]>=2))
    {
                                if(mp[(h-v+px)/40][(h+py)/40]==3){findplayer->speed+=0.12;mp[(h-v+px)/40][(h+py)/40]=0;return;}
                                if(mp[(h+v+px)/40][(h+py)/40]==3){findplayer->speed+=0.12;mp[(h+v+px)/40][(h+py)/40]=0;return;}
                                if(mp[(h+px)/40][(h-v+py)/40]==3){findplayer->speed+=0.12;mp[(h+px)/40][(h-v+py)/40]=0;return;}
                                if(mp[(h+px)/40][(h+v+py)/40]==3){findplayer->speed+=0.12;mp[(h+px)/40][(h+v+py)/40]=0;return;}

                                if(mp[(h-v+px)/40][(h+py)/40]==4){findplayer->pw++;mp[(h-v+px)/40][(h+py)/40]=0;return;}
                                if(mp[(h+v+px)/40][(h+py)/40]==4){findplayer->pw++;mp[(h+v+px)/40][(h+py)/40]=0;return;}
                                if(mp[(h+px)/40][(h-v+py)/40]==4){findplayer->pw++;mp[(h+px)/40][(h-v+py)/40]=0;return;}
                                if(mp[(h+px)/40][(h+v+py)/40]==4){findplayer->pw++;mp[(h+px)/40][(h+v+py)/40]=0;return;}

                                if(mp[(h-v+px)/40][(h+py)/40]==5){findplayer->booms++;mp[(h-v+px)/40][(h+py)/40]=0;return;}
                                if(mp[(h+v+px)/40][(h+py)/40]==5){findplayer->booms++;mp[(h+v+px)/40][(h+py)/40]=0;return;}
                                if(mp[(h+px)/40][(h-v+py)/40]==5){findplayer->booms++;mp[(h+px)/40][(h-v+py)/40]=0;return;}
                                if(mp[(h+px)/40][(h+v+py)/40]==5){findplayer->booms++;mp[(h+px)/40][(h+v+py)/40]=0;return;}

                                if(mp[(h-v+px)/40][(h+py)/40]==6){findplayer->strong++;mp[(h-v+px)/40][(h+py)/40]=0;return;}
                                if(mp[(h+v+px)/40][(h+py)/40]==6){findplayer->strong++;mp[(h+v+px)/40][(h+py)/40]=0;return;}
                                if(mp[(h+px)/40][(h-v+py)/40]==6){findplayer->strong++;mp[(h+px)/40][(h-v+py)/40]=0;return;}
                                if(mp[(h+px)/40][(h+v+py)/40]==6){findplayer->strong++;mp[(h+px)/40][(h+v+py)/40]=0;return;}

                                if(mp[(h-v+px)/40][(h+py)/40]==7){findplayer->Health+=50;mp[(h-v+px)/40][(h+py)/40]=0;return;}
                                if(mp[(h+v+px)/40][(h+py)/40]==7){findplayer->Health+=50;mp[(h+v+px)/40][(h+py)/40]=0;return;}
                                if(mp[(h+px)/40][(h-v+py)/40]==7){findplayer->Health+=50;mp[(h+px)/40][(h-v+py)/40]=0;return;}
                                if(mp[(h+px)/40][(h+v+py)/40]==7){findplayer->Health+=50;mp[(h+px)/40][(h+v+py)/40]=0;return;}

                                if(mp[(h-v+px)/40][(h+py)/40]==8){findplayer->super++;mp[(h-v+px)/40][(h+py)/40]=0;return;}
                                if(mp[(h+v+px)/40][(h+py)/40]==8){findplayer->super++;mp[(h+v+px)/40][(h+py)/40]=0;return;}
                                if(mp[(h+px)/40][(h-v+py)/40]==8){findplayer->super++;mp[(h+px)/40][(h-v+py)/40]=0;return;}
                                if(mp[(h+px)/40][(h+v+py)/40]==8){findplayer->super++;mp[(h+px)/40][(h+v+py)/40]=0;return;}

                /*if(mp[(h-v+px)/40][(h+py)/40]==9){pushable[findplayer->id]=true;mp[(h-v+px)/40][(h+py)/40]=0;}
                if(mp[(h+v+px)/40][(h+py)/40]==9){pushable[findplayer->id]=true;mp[(h+px)/40][(h+v+py)/40]=0;}
                if(mp[(h+px)/40][(h-v+py)/40]==9){pushable[findplayer->id]=true;mp[(h+px)/40][(h-v+py)/40]=0;}
                if(mp[(h+px)/40][(h+v+py)/40]==9){pushable[findplayer->id]=true;mp[(h+px)/40][(h+v+py)/40]=0;}*/

           if(mp[(h-v2+px)/40][(h+py)/40]>2
           ||(mp[(h+v2+px)/40][(h+py)/40]>2)
           ||(mp[(h+px)/40][(h-v2+py)/40]>2)
           ||(mp[(h+px)/40][(h+v2+py)/40]>2))
                {
                        if(mp[(h-v2+px)/40][(h+py)/40]<=1000
                            ||(mp[(h+v2+px)/40][(h+py)/40]<=1000)
                            ||(mp[(h+px)/40][(h-v2+py)/40]<=1000)
                            ||(mp[(h+px)/40][(h+v2+py)/40]<=1000))
                        {
                            int maxpw=1;
                            if(boommp[(h-v2+px)/40][(h+py)/40]>maxpw)maxpw=boommp[(h-v2+px)/40][(h+py)/40];
                            if(boommp[(h+v2+px)/40][(h+py)/40]>maxpw)maxpw=boommp[(h+v2+px)/40][(h+py)/40];
                            if(boommp[(h+px)/40][(h-v2+py)/40]>maxpw)maxpw=boommp[(h+px)/40][(h-v2+py)/40];
                            if(boommp[(h+px)/40][(h+v2+py)/40]>maxpw)maxpw=boommp[(h+px)/40][(h+v2+py)/40];
                            findplayer->beHit(maxpw);
                        }
                }
    }


            if(mp[(h-v3+px)/40][(h+py)/40]==1
            ||(mp[(h+v3+px)/40][(h+py)/40]==1)
            ||(mp[(h+px)/40][(h-v3+py)/40]==1)
            ||(mp[(h+px)/40][(h+v3+py)/40]==1)
            ||(mp[(h-v3+px)/40][(h+py)/40]==2)
            ||(mp[(h+v3+px)/40][(h+py)/40]==2)
            ||(mp[(h+px)/40][(h-v3+py)/40]==2)
            ||(mp[(h+px)/40][(h+v3+py)/40]==2))
    {vx*=-0.1;vy*=-0.1;}
    //判断移动合法性
    transform->moveBy(deltaTime  *vx , deltaTime  *vy);
    }else{

        vx+=deltaTime*(ax-1.2*vx);
        vy+=deltaTime*(ay-1.2*vy);
        int px=transform->pos().x()+deltaTime*vx;
        int py=transform->pos().y()+deltaTime*vy-12;
        int h=100,v=18;
                if(mp[(h-v+px)/40][(h+py)/40]==1
                ||(mp[(h+v+px)/40][(h+py)/40]==1)
                ||(mp[(h+px)/40][(h-v+py)/40]==1)
                ||(mp[(h+px)/40][(h+v+py)/40]==1)
                ||(mp[(h-v+px)/40][(h+py)/40]==2)
                ||(mp[(h+v+px)/40][(h+py)/40]==2)
                ||(mp[(h+px)/40][(h-v+py)/40]==2)
                ||(mp[(h+px)/40][(h+v+py)/40]==2))
        {
                    if(vx<0)
                    {
                        if(mp[(h-v+px)/40][(h+py)/40]==1||mp[(h-v+px)/40][(h+py)/40]==2)
                           vx*=-0.45;
                    }else{
                        if(mp[(h+v+px)/40][(h+py)/40]==1||mp[(h+v+px)/40][(h+py)/40]==2)
                            vx*=-0.45;
                    }
                    if(vy<0)
                    {
                        if(mp[(h+px)/40][(h-v+py)/40]==1||mp[(h+px)/40][(h-v+py)/40]==2)
                           vy*=-0.45;
                    }else{
                        if(mp[(h+px)/40][(h+v+py)/40]==1||mp[(h+px)/40][(h+v+py)/40]==2)
                           vy*=-0.45;
                    }
        }
        //判断移动合法性
        transform->moveBy(deltaTime  *vx , deltaTime  *vy);
    }
}

void Physics::setVelocity(int x,int y)
{
    vx=vx+x;
    vy=vy+y;
}
void Physics::setaty(float vx,float vy)
{
    this->ax=vx;
    this->ay=vy;
}
