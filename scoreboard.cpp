#include "scoreboard.h"
#include "framework/transform.h"
#include "framework/gamescene.h"
#include <QFont>
#include <cstring>
bool extern gameover;
Scoreboard::Scoreboard(Player* owner) : Component(),owner(owner) {}

void Scoreboard::onAttach(){
    mytest = new QGraphicsSimpleTextItem(transform);
    this->transform = this->gameObject->getComponent<Transform>();
    Q_ASSERT(this->transform != nullptr);
}
QString s2q(const std::string &s)
{
return QString(QString::fromLocal8Bit(s.c_str()));
}
void Scoreboard::onUpdate(float deltaTime)
{
    if(owner->Health==0||gameover){destory(this->gameObject);return;}
    auto transform0=new Transform(transform->pos());

    mytest = new QGraphicsSimpleTextItem(transform0);
    QFont font1("Microsoft YaHei", 20, 60, true);
    mytest -> setFont(font1);
    mytest -> setText(s2q(std::to_string(owner->Health))+"   "+s2q(std::to_string(owner->pw))+"    "+s2q(std::to_string(int((owner->speed-0.5)/0.12)))+"   "+s2q(std::to_string(owner->booms)));

    auto scoreboard = new GameObject();
    scoreboard->addComponent(new Scoreboard(this->owner));
    scoreboard->addComponent(transform0);

    this->gameObject->sss()->attachGameObject(scoreboard);

    destory(this->gameObject);
}
