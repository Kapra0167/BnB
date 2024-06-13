#include "mainwindow.h"

#include "framework/gamescene.h"
#include "framework/imagetransform.h"
#include "framework/transformbuilder.h"

#include <player.h>
#include <introduce.h>
#include <wall.h>
#include <stoper.h>
#include <physics.h>
#include <usercontroller.h>
#include <aicontroller.h>
#include <QTime>
#include <QCoreApplication>
#include <QGraphicsRectItem>

#include "./ui_mainwindow.h"
extern int mp[100][100];
void delayfirst()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void loadScene(GameScene *gameScene)
{


    auto background = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(400, 300))
        .setImage("://scene")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(background);
    gameScene->attachGameObject(background);

    auto summonDummyBtn = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(500,200))
        .setImage("://bt1")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(summonDummyBtn);
    summonDummyBtn->addComponent(new Transform);
    summonDummyBtn->addComponent(new Stoper);
    gameScene->attachGameObject(summonDummyBtn);

    auto intro = new GameObject();
    ImageTransformBuilder()
        .setPos(QPointF(600,400))
        .setImage("://bt2")
        .setAlignment(Qt::AlignCenter)
        .addToGameObject(intro);
    intro->addComponent(new Transform);
    intro->addComponent(new Introduce(1));
    gameScene->attachGameObject(intro);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  gameScene = new GameScene();
  gameScene->setParent(this);
  auto view = new QGraphicsView(gameScene, this);
  view->setFrameStyle(QFrame::NoFrame);
  view->resize(1600,800);
  view->setSceneRect(QRect(0, 0, this->width(), this->height()));
  view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

  loadScene(gameScene);
}

MainWindow::~MainWindow() { delete ui; }
