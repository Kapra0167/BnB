#include "boom.h"
#include "player.h"
#include "aicontroller.h"
#include "framework/imagetransform.h"
#include "framework/gameobject.h"
#include "framework/gamescene.h"
extern int mp[100][100];
extern int userpx[5];
extern int userpy[5];
extern int commend[100][100];
extern int commend2[100][100];
extern int thinktime[5];
short boommp[100][100];
int pushable[10];

Boom::Boom(float vx,float vy,Player* owner) : Component(),vx(vx),vy(vy),owner(owner) {}

void Boom::onAttach() {
  imagetransform = this->gameObject->getComponent<ImageTransform>();
  physics = this->gameObject->getComponent<Physics>();
  physics->setVelocity(this->vx,this->vy);
  assert(imagetransform != nullptr );

}
void Boom::onUpdate(float deltaTime){

    int x=(imagetransform->pos().x()+20)/40+2;
    int y=imagetransform->pos().y()/40+2;
    for(int pid=1;pid<=4;pid++)
    if(pushable[pid]&&abs(userpx[pid]-x)<2&&abs(userpy[pid]-y)<2)physics->setVelocity((-userpx[pid]+x)*30,(-userpy[pid]+y)*30);
    //qDebug()<<abs(userpx[pid]-x)<<" "<<abs(userpy[pid]-y)<<Qt::endl;
    //if(boommp[x][y]>=2)physics->setVelocity(50,50);
        if(clock--<0)destory(this->gameObject);
        if(clock%108==4) this->imagetransform->setImage(":/bm1/b1-4");
        else if(clock%108==8) this->imagetransform->setImage(":/bm1/b1-2");
        else if(clock%108==12) this->imagetransform->setImage(":/bm1/b1-1");
        else if(clock%108==16) this->imagetransform->setImage(":/bm1/b1-3");
        else if(clock%108==20) this->imagetransform->setImage(":/bm1/b1-5");
        else if(clock%108==24) this->imagetransform->setImage(":/bm1/b1-6");
        else if(clock%108==28) this->imagetransform->setImage(":/bm1/b1-7");
        else if(clock%108==32) this->imagetransform->setImage(":/bm1/b1-8");
        else if(clock%108==36) this->imagetransform->setImage(":/bm1/b1-9");
        else if(clock%108==40) this->imagetransform->setImage(":/bm1/b1-10");
        else if(clock%108==44) this->imagetransform->setImage(":/bm1/b1-14");
        else if(clock%108==48) this->imagetransform->setImage(":/bm1/b1-13");
        else if(clock%108==52) this->imagetransform->setImage(":/bm1/b1-12");
        else if(clock%108==56) this->imagetransform->setImage(":/bm1/b1-11");
        else if(clock%108==60) this->imagetransform->setImage(":/bm1/b1-12");
        else if(clock%108==64) this->imagetransform->setImage(":/bm1/b1-13");
        else if(clock%108==68) this->imagetransform->setImage(":/bm1/b1-14");
        else if(clock%108==72) this->imagetransform->setImage(":/bm1/b1-10");
        else if(clock%108==76) this->imagetransform->setImage(":/bm1/b1-9");
        else if(clock%108==80) this->imagetransform->setImage(":/bm1/b1-8");
        else if(clock%108==84) this->imagetransform->setImage(":/bm1/b1-7");
        else if(clock%108==88) this->imagetransform->setImage(":/bm1/b1-6");
        else if(clock%108==92) this->imagetransform->setImage(":/bm1/b1-5");
        else if(clock%108==96) this->imagetransform->setImage(":/bm1/b1-3");
        else if(clock%108==100) this->imagetransform->setImage(":/bm1/b1-1");
        else if(clock%108==104) this->imagetransform->setImage(":/bm1/b1-2");

        if(thinktime[3]==2)
        {
            this->pw = owner->pw;

            int up=x-pw;
            int down=x+pw;
            int lf=y-pw;
            int rt=y+pw;
            if(up<=1)up=2;
            if(down>=21)down=21;
            if(lf<=1)lf=2;
            if(rt>=16)rt=16;

                for(int i=x+1;i<=down;i++)//预警
                {
                   if(mp[i][y]==0)commend[i][y]+=(100-(i-down));
                   else break;
                }
                for(int i=x+1;i>=up;i--)
                {
                   if(mp[i][y]==0)commend[i][y]+=(100-(up-i));
                   else break;
                }
                for(int i=y+1;i<=rt;i++)
                {
                   if(mp[x][i]==0)commend[x][i]+=(100-(i-rt));
                   else break;
                }
                for(int i=y+1;i>=lf;i--)
                {
                    if(mp[x][i]==0)commend[x][i]+=(100-(lf-i));
                    else break;
                }
                if(mp[x][y]==0)commend[x][y]+=100;
        }
        if(thinktime[4]==2)
        {
            this->pw = owner->pw;

            int up=x-pw;
            int down=x+pw;
            int lf=y-pw;
            int rt=y+pw;
            if(up<=1)up=2;
            if(down>=21)down=21;
            if(lf<=1)lf=2;
            if(rt>=16)rt=16;

                for(int i=x+1;i<=down;i++)//预警
                {
                   if(mp[i][y]==0)commend2[i][y]+=(100-(i-down));
                   else break;
                }
                for(int i=x+1;i>=up;i--)
                {
                   if(mp[i][y]==0)commend2[i][y]+=(100-(up-i));
                   else break;
                }
                for(int i=y+1;i<=rt;i++)
                {
                   if(mp[x][i]==0)commend2[x][i]+=(100-(i-rt));
                   else break;
                }
                for(int i=y+1;i>=lf;i--)
                {
                    if(mp[x][i]==0)commend2[x][i]+=(100-(lf-i));
                    else break;
                }
                if(mp[x][y]==0)commend2[x][y]+=100;
        }
}

void Boom::onDetach() {
    int x=(imagetransform->pos().x()+20)/40+2;
    int y=imagetransform->pos().y()/40+2;


    this->pw = owner->pw;
    int t0=1000,t1=1003,t2=1004,t3=1005,t4=1006,t5=1007,t6=1008,t7=1009;
    int up=x-pw;
    int down=x+pw;
    int lf=y-pw;
    int rt=y+pw;
    if(up<=1)up=2;
    if(down>=21)down=21;
    if(lf<=1)lf=2;
    if(rt>=16)rt=16;
/*
    for(int i=x+1;i<=down;i++)//预警返还
    {
        if(mp[i][y]==0)boommp2[i][y]-=down-i+1;
        else if(mp[i][y]>=1)break;
     }
    for(int i=x+1;i>=up;i--)
    {
       if(mp[i][y]==0)boommp2[i][y]-=up-i+1;
       else if(mp[i][y]>=1)break;
     }
    for(int i=y+1;i<=rt;i++)
    {
       if(mp[x][i]==0)boommp2[x][i]-=rt-i+1;
       else if(mp[x][i]>=1)break;

    }
    for(int i=y;i>=lf;i--)
    {
       if(mp[x][i]==0)boommp2[x][i]-=lf-i+1;
       else if(mp[x][i]>=1)break;
    }*/
    for(int i=x+1;i<=down;i++)//分开两端光束，使其在硬墙断开
    {
        if(mp[i][y]<=0)mp[i][y]=t0;
        else if(mp[i][y]==1)break;
        else if(mp[i][y]==2&&(rand()%5<=1))mp[i][y]=t1;
        else if(mp[i][y]==2&&(rand()%4==1))mp[i][y]=t2;
        else if(mp[i][y]==2&&(rand()%4==1))mp[i][y]=t5;
        else if(mp[i][y]==2&&(rand()%6==2))mp[i][y]=t3;
        //else if(mp[i][y]==2&&(rand()%9==2))mp[i][y]=t7;
        else if(mp[i][y]==2&&(rand()%9==2))mp[i][y]=t4;
        else if(mp[i][y]==2&&(rand()%9==2))mp[i][y]=t6;
        else if(mp[i][y]==2)mp[i][y]=t0;
        if(boommp[i][y]>1)boommp[i][y]+=(1.0/boommp[i][y]);
        else boommp[i][y]++;
     }
    for(int i=x+1;i>=up;i--)
    {
       if(mp[i][y]<=0)mp[i][y]=t0;
       else if(mp[i][y]==1)break;
       else if(mp[i][y]==2&&(rand()%5<=1))mp[i][y]=t1;
       else if(mp[i][y]==2&&(rand()%4==1))mp[i][y]=t2;
       else if(mp[i][y]==2&&(rand()%6==2))mp[i][y]=t3;
       else if(mp[i][y]==2&&(rand()%9==2))mp[i][y]=t4;
       //else if(mp[i][y]==2&&(rand()%9==2))mp[i][y]=t7;
       else if(mp[i][y]==2&&(rand()%4==1))mp[i][y]=t5;
       else if(mp[i][y]==2&&(rand()%9==2))mp[i][y]=t6;
       else if(mp[i][y]==2)mp[i][y]=t0;
       if(boommp[i][y]>1)boommp[i][y]+=(1.0/boommp[i][y]);
       else boommp[i][y]++;
     }
    for(int i=y+1;i<=rt;i++)
    {
       if(mp[x][i]<=0)mp[x][i]=t0;
       else if(mp[x][i]==1)break;
       else if(mp[x][i]==2&&(rand()%5<=1))mp[x][i]=t1;
       else if(mp[x][i]==2&&(rand()%4==1))mp[x][i]=t2;
       else if(mp[x][i]==2&&(rand()%4==1))mp[i][y]=t5;
       else if(mp[x][i]==2&&(rand()%6==2))mp[x][i]=t3;
       //else if(mp[i][y]==2&&(rand()%9==2))mp[i][y]=t7;
       else if(mp[x][i]==2&&(rand()%9==5))mp[x][i]=t4;
       else if(mp[x][i]==2&&(rand()%9==5))mp[x][i]=t6;
       else if(mp[x][i]==2)mp[x][i]=t0;
       if(boommp[x][i]>1)boommp[x][i]+=(1.0/boommp[x][i]);
       else boommp[x][i]++;
    }
    for(int i=y;i>=lf;i--)
    {
       if(mp[x][i]<=0)mp[x][i]=t0;
       else if(mp[x][i]==1)break;
       else if(mp[x][i]==2&&(rand()%5<=1))mp[x][i]=t1;
       else if(mp[x][i]==2&&(rand()%4==1))mp[x][i]=t2;
       else if(mp[x][i]==2&&(rand()%4==1))mp[i][y]=t5;
       else if(mp[x][i]==2&&(rand()%6==2))mp[x][i]=t3;
       //else if(mp[i][y]==2&&(rand()%9==2))mp[i][y]=t7;
       else if(mp[x][i]==2&&(rand()%9==2))mp[x][i]=t4;
       else if(mp[x][i]==2&&(rand()%9==5))mp[x][i]=t6;
       else if(mp[x][i]==2)mp[x][i]=t0;
       if(boommp[x][i]>1)boommp[x][i]+=(1.0/boommp[x][i]);
       else boommp[x][i]++;
    }
    owner->booms++;
    /*char s[10];
    snprintf(s,sizeof(s),"%d",100*x+y);
    this->gameObject->sss()->getGameObject(s)->getComponent<Wall>()->befire();*/

}
