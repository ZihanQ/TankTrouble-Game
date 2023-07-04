#include "gamescene.h"


gameScene::gameScene(QObject *parent) : QGraphicsScene(parent)
{
    initItem();
    //QTimer *timer = new QTimer(this);
    // connect(timer, &QTimer::timeout, this, &gameScene::moveTank);
    //timer->start(16); // 设置定时器周期，单位为毫秒
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &gameScene::moveTank);
    movingUp = false;
    movingDown = false;
}

void gameScene::startMoving() {
    if (!timer->isActive()) {
        timer->start(16); // 每16毫秒触发一次定时器
    }
}

void gameScene::stopMoving() {
    timer->stop();
    movingUp = false;
    movingDown = false;
}

void gameScene::initItem()
{
    tank = new tankItem;
    this -> addItem(tank);
}

void gameScene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W) {
        movingUp = true;
        startMoving();
    }
    else if (event->key() == Qt::Key_S) {
        movingDown = true;
        startMoving();
    }
}

void gameScene::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W) {
        movingUp = false;
    }
    else if (event->key() == Qt::Key_S) {
        movingDown = false;
    }
}

gameScene::~gameScene()
{
    timer->stop();
    delete timer;
}



void gameScene::moveTank()
{

    qreal stepSize = 10;
    QPointF currentPosition = tank->pos();

    if (movingUp) {
        tank->setPos(currentPosition.x(), currentPosition.y() - stepSize);
    }
    else if (movingDown) {
        tank->setPos(currentPosition.x(), currentPosition.y() + stepSize);
    }
}






