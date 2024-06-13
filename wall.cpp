#include "wall.h"
#include "player.h"
#include "boom.h"

#include "framework/gameobject.h"
#include "framework/gamescene.h"
#include "framework/imagetransform.h"

#include <QGraphicsRectItem>
extern int mp[100][100];
extern int boommp[100][100];

Wall::Wall() : Component() {}

void Wall::onAttach()
{
    imagetransform = this->gameObject->getComponent<ImageTransform>();
    assert(imagetransform != nullptr );
}
void Wall::befire()
{
    this->imagetransform->setImage("://boom2");
    return;
}
QString s1q(const std::string &s)
{
return QString(QString::fromLocal8Bit(s.c_str()));
}
void Wall :: onUpdate (float deltaTime)
{
    type++;if(type>=100)type=0;
    int px=imagetransform->pos().x()/40+3;
    int py=imagetransform->pos().y()/40+2;
    int num=mp[px][py];
    if(num<=0){this->imagetransform->setImage("://wall0");if(type>=99)mp[px][py]=0;}
    else if(num==3)this->imagetransform->setImage("://prop1");//加速
    else if(num==4)this->imagetransform->setImage("://prop2");//威力
    else if(num==5)this->imagetransform->setImage("://prop3");//炸弹
    else if(num==6)this->imagetransform->setImage("://prop4");//发射
    else if(num==7)this->imagetransform->setImage("://prop5");//生命
    else if(num==8)this->imagetransform->setImage("://prop6");//超量
    else if(num==9)this->imagetransform->setImage("://prop7");//推动
    else if(num>=10)
    {
        mp[px][py]-=10;
        if(mp[px][py]<10)boommp[px][py]=0;
        if(type%3==1||num>=1000)return;
        if(num%150<=50)this->imagetransform->setImage(":/bming/bm5");
        else if(num%150<=100)this->imagetransform->setImage(":/bming/bm6");
        else if(num%150>=100)this->imagetransform->setImage(":/bming/bm7");
    }
    return;
}
