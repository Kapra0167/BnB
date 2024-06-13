#include "stoper.h"
#include <QTime>
#include <QCoreApplication>

#include "framework/gamescene.h"
#include "framework/imagetransform.h"
#include "framework/transformbuilder.h"

#include <player.h>
#include <wall.h>
#include <scoreboard.h>
#include <stoper.h>
#include <physics.h>
#include <usercontroller.h>
#include <aicontroller.h>
#include <QTime>
#include <QCoreApplication>
#include <QGraphicsRectItem>

#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>

extern int mp[100][100];
bool gamestart=false;
Stoper::Stoper() {}
void Stoper::onAttach() {
  auto transform = this->gameObject->getComponent<Transform>();
  Q_ASSERT(transform != nullptr);
  // Handle mouse event of text by this->transform
  transform->setFiltersChildEvents(true);
}
void Stoper::onClick(QGraphicsSceneMouseEvent *ev) {

    auto gameScene=this->gameObject->sss();
    auto background = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(400, 200))
        .setImage("://map")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(background);
    gameScene->attachGameObject(background);

  for(int i=1;i<=22;i++)
      for(int j=1;j<=17;j++)
      {
          char s[100];
          snprintf(s, sizeof(s), "%d", 100*i+j);
          if(mp[i][j]==0)
          {
              auto wall = new GameObject();
                  wall->setObjectName(s);
              ImageTransformBuilder()
                  .setPos(QPointF(i*40-100, j*40-80))
                  .setImage("://wall0")
                  .setAlignment(Qt::AlignLeft)
                  .addToGameObject(wall);
              wall->addComponent(new Wall);
              gameScene->attachGameObject(wall);
          }else if(mp[i][j]==1)
          {
              auto wall = new GameObject();
              wall->setObjectName(s);
              ImageTransformBuilder()
                  .setPos(QPointF(i*40-100, j*40-80))
                  .setImage("://wall1")
                  .setAlignment(Qt::AlignLeft)
                  .addToGameObject(wall);
              wall->addComponent(new Wall);
              gameScene->attachGameObject(wall);
          }else if(rand()%3>0)
          {
              auto wall = new GameObject();
              wall->setObjectName(s);
              ImageTransformBuilder()
                  .setPos(QPointF(i*40-100, j*40-80))
                  .setImage("://wall3")
                  .setAlignment(Qt::AlignLeft)
                  .addToGameObject(wall);
              wall->addComponent(new Wall);
              gameScene->attachGameObject(wall);
          }else if(rand()%2==1)
          {
              auto wall = new GameObject();
              wall->setObjectName(s);
              ImageTransformBuilder()
                  .setPos(QPointF(i*40-100, j*40-80))
                  .setImage("://wall4")
                  .setAlignment(Qt::AlignLeft)
                  .addToGameObject(wall);
              wall->addComponent(new Wall);
              gameScene->attachGameObject(wall);
          }else
          {
              auto wall = new GameObject();
              wall->setObjectName(s);
              ImageTransformBuilder()
                  .setPos(QPointF(i*40-100, j*40-80))
                  .setImage("://wall5")
                  .setAlignment(Qt::AlignLeft)
                  .addToGameObject(wall);
              wall->addComponent(new Wall);
              gameScene->attachGameObject(wall);
          }
      }

  auto player1 = new GameObject();
  ImageTransformBuilder()
      .setPos(QPointF(30, 40))
      .setImage(":/p1s/p1s0")
      .setAlignment(Qt::AlignCenter)
      .addToGameObject(player1);
  player1->addComponent(new Physics);
  player1->addComponent(new Player(1));
  player1->addComponent(new UserController(1));
  gameScene->attachGameObject(player1);
  auto player2 = new GameObject();
  ImageTransformBuilder()
      .setPos(QPointF(560, 560))
      .setImage(":/p2s/p2s0")
      .setAlignment(Qt::AlignCenter)
      .addToGameObject(player2);
  player2->addComponent(new Physics);
  player2->addComponent(new Player(2));
  player2->addComponent(new UserController(2));
  gameScene->attachGameObject(player2);
  auto bot3 = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(600, 40))
        .setImage(":/bt3/bot3/0.png")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(bot3);
    bot3->addComponent(new Physics);
    bot3->addComponent(new Player(3));
    bot3->addComponent(new AiController(3));
    gameScene->attachGameObject(bot3);
    auto bot4 = new GameObject();
      ImageTransformBuilder()
          .setPos(QPointF(50, 560))
          .setImage(":/bt4/bot4/0.png")
          .setAlignment(Qt::AlignCenter)
          .addToGameObject(bot4);
      bot4->addComponent(new Physics);
      bot4->addComponent(new Player(4));
      bot4->addComponent(new AiController(4));
      gameScene->attachGameObject(bot4);

    auto boardground = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(-240, 220))
        .setImage("://board")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(boardground);
    gameScene->attachGameObject(boardground);

    auto pic5 = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(-215, 50))
        .setImage("://prop2")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(pic5);
    gameScene->attachGameObject(pic5);

    auto pic6 = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(-172, 50))
        .setImage("://prop1")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(pic6);
    gameScene->attachGameObject(pic6);

    auto pic7 = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(-130, 50))
        .setImage("://prop3")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(pic7);
    gameScene->attachGameObject(pic7);

    auto pic8 = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(-260, 50))
        .setImage("://prop5")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(pic8);
    gameScene->attachGameObject(pic8);

    auto pic1 = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(-320, 85))
        .setImage("://m1")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(pic1);
    gameScene->attachGameObject(pic1);

    auto pic2 = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(-320, 165))
        .setImage("://m2")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(pic2);
    gameScene->attachGameObject(pic2);

    auto pic3 = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(-320, 245))
        .setImage("://bm3")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(pic3);
    gameScene->attachGameObject(pic3);

    auto pic4 = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(-320, 325))
        .setImage("://bm4")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(pic4);
    gameScene->attachGameObject(pic4);

    auto board1 = new GameObject();
    TransformBuilder()
    .setPos(QPointF(-285, 65))
    .addToGameObject(board1);
    board1->addComponent(new Scoreboard(player1->getComponent<Player>()));
    gameScene->attachGameObject(board1);

    auto board2 = new GameObject();
    TransformBuilder()
    .setPos(QPointF(-285, 145))
    .addToGameObject(board2);
    board2->addComponent(new Scoreboard(player2->getComponent<Player>()));
    gameScene->attachGameObject(board2);

    auto board3 = new GameObject();
    TransformBuilder()
    .setPos(QPointF(-285, 225))
    .addToGameObject(board3);
    board3->addComponent(new Scoreboard(bot3->getComponent<Player>()));
    gameScene->attachGameObject(board3);

    auto board4 = new GameObject();
    TransformBuilder()
    .setPos(QPointF(-285, 305))
    .addToGameObject(board4);
    board4->addComponent(new Scoreboard(bot4->getComponent<Player>()));
    gameScene->attachGameObject(board4);

    gamestart=true;
    destory(this->gameObject);
}
