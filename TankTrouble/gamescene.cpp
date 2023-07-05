#include "gamescene.h"


gameScene::gameScene(QObject *parent) : QGraphicsScene(parent)
{
    initItem();

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &gameScene::moveTank);
    movingUp = false;
    movingDown = false;
    leftRotate = false;
    rightRotate = false;
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
    leftRotate = false;
    rightRotate = false;
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
    else if (event->key() == Qt::Key_A){
        leftRotate = true;
        startMoving();
    }
    else if (event->key() == Qt::Key_D){
        rightRotate = true;
        startMoving();
    }
    else if (event->key() == Qt::Key_J){
        shoot();
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
    else if (event->key() == Qt::Key_A){
        leftRotate = false;
    }
    else if (event->key() == Qt::Key_D){
        rightRotate = false;
    }

}

void gameScene::shoot()
{
    bulletItem *bullet = initBullet();
    static int count=0;
    qreal bulletAngle = tank->rotation();
    qreal radians = qDegreesToRadians(bulletAngle);
    QTimer* bulletTimer;
    bulletTimer = new QTimer(this);
    bulletTimer->setInterval(10);

    moveBullet(bullet,radians);

    connect(bulletTimer, &QTimer::timeout, this, [=]() {
        if (count++ >= 100) {
            bulletTimer->stop();
            delete bullet;
            delete bulletTimer;
        }

    } );
    bulletTimer->start();
}
bulletItem* gameScene::initBullet()
{
    QPointF currentPosition = this -> tank->pos();
    bulletItem *bullet;
    bullet = new bulletItem;
    addItem(bullet);
    bullet -> setPos(currentPosition.x(),currentPosition.y());
    return bullet;
    //bullet -> getPos(currentPosition.x(),currentPosition.y());
}



void gameScene::moveBullet(bulletItem* bullet,qreal radians)
{
    qreal stepSize = 1;

    // 获取当前角度，并转化为弧度制
    QPointF currentPosition = bullet->pos();
    qreal dx = stepSize * qSin(radians);
    qreal dy = -stepSize * qCos(radians);
    bullet->setPos(currentPosition.x() + dx, currentPosition.y() + dy);
}

void gameScene::moveTank()
{
    //移动速度
    qreal stepSize = 5;

    // 获取当前角度，并转化为弧度制
    qreal tankAngle = tank->rotation();
    qreal radians = qDegreesToRadians(tankAngle);

    QPointF currentPosition = tank->pos();
    qreal dx = stepSize * qSin(radians);
    qreal dy = -stepSize * qCos(radians);
    //qDebug() << tankAngle << "dx" << dx << "dy" << dy;

    //tank -> prepare();

    if (movingUp) {
        tank->setPos(currentPosition.x() + dx, currentPosition.y() + dy);
    }
    else if (movingDown) {
        tank->setPos(currentPosition.x() - dx, currentPosition.y() - dy);
    }
    if(leftRotate){
        tank->rotate(-stepSize);
    }
    else if(rightRotate){
        tank->rotate(stepSize);
    }
}

gameScene::~gameScene()
{
    timer->stop();
    delete timer;
}






