#include "aicontroller.h"
#include "framework/transformbuilder.h"

extern int mp[100][100];
extern int userpx[5];
extern int userpy[5];
extern int commend[100][100];
extern int commend2[100][100];
extern int thinktime[5];
AiController::AiController(int id) : Component(),id(id) {}

void AiController::onAttach()
{
    physics = this->gameObject->getComponent<Physics>();
    assert(physics != nullptr );

    player = this->gameObject->getComponent<Player>();
    assert(player != nullptr );
}
void AiController :: onUpdate (float deltaTime)
{
    int answer;
    answer=cul();
    if(answer<0)answer=lastanswer;
    lastanswer=answer;

    boomcool[id]++;
    if(boomcool[id]>30001)boomcool[id]=0;
    float ax = 0 , ay = 0 , pv=player->speed;
        if( answer==4 ) {ax += 15/pv;player->settype(4);physics->setVelocity(12*pv,0);}
        if( answer==3 ) {ax -= 15/pv;player->settype(3);physics->setVelocity(-12*pv,0);}
        if( answer==2 ) {ay += 15/pv;player->settype(2);physics->setVelocity(0,12*pv);}
        if( answer==1 ) {ay -= 15/pv;player->settype(1);physics->setVelocity(0,-12*pv);}
        if( player->booms>0 && boomcool[id]%150==1 && nearwall()) {
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
                newboom->addComponent(new Boom(0.8*player->moveable*physics->revx(),0.8*player->moveable*physics->revy(),player));
                attachGameObject(newboom);
            }
        }
    userpx[player->id]=physics->rex()/40+2;
    userpy[player->id]=physics->rey()/40+2;

    //qDebug()<<userpx<<" "<<userpy<<Qt::endl;
    physics ->setaty ( ax,ay ) ;
}
bool AiController :: move_able(int px,int py,int type)
{
    if (type == 1)py--;
    else if (type == 2)py++;
    else if (type == 3)px--;
    else if (type == 4)px++;
    return mp[px][py]==0||mp[px][py]>2;
}
int AiController :: breath(int y,int x)
{
    int ans=0;
    if(mp[y+1][x]==0||mp[y+1][x]>3)ans++;
    if(mp[y-1][x]==0||mp[y-1][x]>3)ans++;
    if(mp[y][x+1]==0||mp[y][x+1]>3)ans++;
    if(mp[y][x-1]==0||mp[y][x-1]>3)ans++;
    return ans;
}
bool AiController :: nearwall()
{
    int tpx=physics->rex();
    int tpy=physics->rey();
    int px=(tpx+20)/40+2;
    int py=tpy/40+2;
    int dis1=abs(px-userpx[1])+abs(py-userpy[1]);
    int dis2=abs(px-userpx[2])+abs(py-userpy[2]);
    return mp[px+1][py]==2||mp[px-1][py]==2||mp[px][py+1]==2||mp[px][py-1]==2||dis1<=4||dis2<=4;
}
int AiController :: danger(int px,int py,int type)
{
    if (type == 1)py--;
    else if (type == 2)py++;
    else if (type == 3)px--;
    else if (type == 4)px++;

    if(mp[px][py]>=10)return 1000;
    if(mp[px][py]==1||mp[px][py]==2)return 2000;
    else return commend[px][py]-breath(px,py)*2;
}
int AiController :: danger2(int px,int py,int type)
{
    if (type == 1)py--;
    else if (type == 2)py++;
    else if (type == 3)px--;
    else if (type == 4)px++;

    if(mp[px][py]>=10)return 1000;
    if(mp[px][py]==1||mp[px][py]==2)return 2000;
    else return commend2[px][py]-breath(px,py)*2;
}
int AiController :: cul()
{
    int answer;
    int try1,try2;
    int tpx=physics->rex();
    int tpy=physics->rey();
    int px=(tpx+20)/40+2;
    int py=tpy/40+2;
    int dis1=abs(px-userpx[1])+abs(py-userpy[1]);
    int dis2=abs(px-userpx[2])+abs(py-userpy[2]);
    //简单粗暴的算法，谁近就抓谁，同时攻击性十足。

    if(dis1<=dis2)
    {
        if(px<userpx[1])try1=4;
        else if(px>userpx[1])try1=3;
        else try1=0;
        if(py<userpy[1])try2=2;
        else if(py>userpy[1])try2=1;
        else try2=0;
    }else{
        if(px<userpx[2])try1=4;
        else if(px>userpx[2])try1=3;
        else try1=0;
        if(py<userpy[2])try2=2;
        else if(py>userpx[2])try2=1;
        else try2=0;
    }int elsetry=rand()%4+1;
    if(!this->move_able(px,py,try1)||try1==0)
        if(!this->move_able(px,py,try2)||try2==0)
            if(!this->move_able(px,py,elsetry))
                        answer=0;
            else answer=elsetry;
        else answer=try2;
    else answer=try1;
    thinktime[id]++;
    if(thinktime[id]>=4)thinktime[id]=1;
    if(thinktime[id]!=3)return -1;
    if(id==3&&danger(px,py,answer)>0)
    {
        int minx=1000000;
        int mini;
        for(int i=0;i<=4;i++)if(minx>danger(px,py,i)){minx=danger(px,py,i);mini=i;}
        if(minx<2000)answer=mini;
    }else  if(id==4&&danger2(px,py,answer)>0)
    {
        int minx=1000000;
        int mini;
        for(int i=0;i<=4;i++)if(minx>danger(px,py,i)){minx=danger2(px,py,i);mini=i;}
        if(minx<2000)answer=mini;
    }
    //if(id==4)qDebug()<<px<<py<<answer<<commend2[px][py]<<commend2[px][py-1]<<commend2[px][py+1]<<commend2[px-1][py]<<commend2[px+1][py];

    if(id==3&&thinktime[id]==3)for(int i=1;i<=100;i++)for(int j=1;j<=100;j++)commend[i][j]=0;
    if(id==4&&thinktime[id]==3)for(int i=1;i<=100;i++)for(int j=1;j<=100;j++)commend2[i][j]=0;

    pickcool[id]++;
    if(pickcool[id]>=5&&mp[px+1][py]>2&&mp[px+1][py]<10){answer=4;pickcool[id]=0;}
    else if(pickcool[id]>=5&&mp[px][py+1]>2&&mp[px][py+1]<10){answer=2;pickcool[id]=0;}
    else if(pickcool[id]>=5&&mp[px-1][py]>2&&mp[px-1][py]<10){answer=3;pickcool[id]=0;}
    else if(pickcool[id]>=5&&mp[px][py-1]>2&&mp[px][py-1]<10){answer=1;pickcool[id]=0;}

    else if(pickcool[id]>=5&&mp[px+2][py]>2&&mp[px+2][py]<10){answer=4;pickcool[id]=0;}
    else if(pickcool[id]>=5&&mp[px][py+2]>2&&mp[px][py+2]<10){answer=2;pickcool[id]=0;}
    else if(pickcool[id]>=5&&mp[px-2][py]>2&&mp[px-2][py]<10){answer=3;pickcool[id]=0;}
    else if(pickcool[id]>=5&&mp[px][py-2]>2&&mp[px][py-2]<10){answer=1;pickcool[id]=0;}
    return answer;
}
