#include "gamescene.h"


gameScene::gameScene(QObject *parent) : QGraphicsScene(parent)
{
    initItem();

    timer_1 = new QTimer(this);
    timer_2 = new QTimer(this);
    connect(timer_1, &QTimer::timeout, this, &gameScene::moveTank_1);
    connect(timer_2, &QTimer::timeout, this, &gameScene::moveTank_2);
}

void gameScene::startMoving() {
    if (!timer_2->isActive() && tankStatus_2) {
        timer_2->start(16); // 每16毫秒触发一次定时器
    }
    if (!timer_1->isActive() && tankStatus_1) {
        timer_1->start(16);
    }

}

void gameScene::stopMoving()
{
    if(tankStatus_1 == false){
    timer_1->stop();
    movingUp_1 = false;
    movingDown_1 = false;
    leftRotate_1 = false;
    rightRotate_1 = false;
    }
    if(tankStatus_2 == false){
    timer_2->stop();
    movingUp_2 = false;
    movingDown_2 = false;
    leftRotate_2 = false;
    rightRotate_2 = false;}
}

void gameScene::initItem()
{
    tank_1 = new tankItem;
    tank_1 -> setPos(100,100);
    tank_2 = new tankItem;
    tank_2 -> setPos(600,600);

    this -> addItem(tank_1);
    this -> addItem(tank_2);
}

void gameScene::initStatus()
{
    movingUp_1 = false;
    movingDown_1 = false;
    leftRotate_1 = false;
    rightRotate_1 = false;
    movingUp_2 = false;
    movingDown_2 = false;
    leftRotate_2 = false;
    rightRotate_2 = false;
}

void gameScene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W) {
        movingUp_1 = tankStatus_1 = true;
        startMoving();
    }
    else if (event->key() == Qt::Key_S) {
        movingDown_1 = tankStatus_1= true;
        startMoving();
    }
    else if (event->key() == Qt::Key_A){
        leftRotate_1 = tankStatus_1= true;
        startMoving();
    }
    else if (event->key() == Qt::Key_D){
        rightRotate_1 = tankStatus_1= true;
        startMoving();
    }
    else if (event->key() == Qt::Key_C){
        shoot(1);
    }
    else if (event->key() == Qt::Key_I) {
        movingUp_2 = tankStatus_2 = true;
        startMoving();
    }
    else if (event->key() == Qt::Key_K) {
        movingDown_2 = tankStatus_2 = true;
        startMoving();
    }
    else if (event->key() == Qt::Key_J){
        leftRotate_2 = tankStatus_2 = true;
        startMoving();
    }
    else if (event->key() == Qt::Key_L){
        rightRotate_2 = tankStatus_2 = true;
        startMoving();
    }
    else if (event->key() == Qt::Key_P){
        shoot(2);
    }
}

void gameScene::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W) {
        tankStatus_1 = false;
        stopMoving();
        movingUp_1 = false;
    }
    else if (event->key() == Qt::Key_S) {
        tankStatus_1 = false;
        stopMoving();
        movingDown_1 = false;
    }
    else if (event->key() == Qt::Key_A){
        tankStatus_1 = false;
        stopMoving();
        leftRotate_1 = false;
    }
    else if (event->key() == Qt::Key_D){
        tankStatus_1 = false;
        stopMoving();
        rightRotate_1 = false;
    }
    else if (event->key() == Qt::Key_I) {
        tankStatus_2 = false;
        stopMoving();
        movingUp_2 = false;
    }
    else if (event->key() == Qt::Key_K) {
        movingDown_2 = false;
        tankStatus_2 = false;
        stopMoving();
    }
    else if (event->key() == Qt::Key_J){
        leftRotate_2 = false;
        tankStatus_2 = false;
        stopMoving();
    }
    else if (event->key() == Qt::Key_L){
        rightRotate_2 = false;
        tankStatus_2 = false;
        stopMoving();
    }

}

void gameScene::shoot(int x)
{
    bulletItem *bullet = initBullet(x);
    int* count = new int(0);

    tankItem * tank;
    if(x==1)tank = tank_1;
    else tank = tank_2;

    qreal bulletAngle = tank->rotation();
    qreal radians = qDegreesToRadians(bulletAngle);
    QTimer* bulletTimer;
    bulletTimer = new QTimer(this);
    bulletTimer->setInterval(10);

    connect(bulletTimer, &QTimer::timeout, this, [=]() {
        moveBullet(bullet,radians);
        checkBulletTankCollision(bullet);
        if (++(*count) >= 500) {
            int index = bullets.indexOf(bullet);
            if (index != -1) {
                removeItem(bullet);
                delete bullet;
                delete timers[index];
                bullets.removeAt(index);
                timers.removeAt(index);
                delete count;
            }

            //bulletTimer->stop();
            //removeItem(bullet);
            //delete bullet;
            //delete bulletTimer;
        }
    });
    count = 0;
    bullets.append(bullet);
    timers.append(bulletTimer);
    bulletTimer->start();
}

void gameScene::checkBulletTankCollision(bulletItem* bullet)
{
    QMessageBox msg;
    if(bullet -> collidesWithItem(tank_1))
    {

    msg.setWindowTitle("坦克动荡");
    msg.setIcon(QMessageBox::Information);
    msg.setText("恭喜玩家2胜利！");
    msg.setStandardButtons(QMessageBox::Yes);
    msg.exec();
    }
    else if (bullet -> collidesWithItem(tank_2))
    {
    msg.setWindowTitle("坦克动荡");
    msg.setIcon(QMessageBox::Information);
    msg.setText("恭喜玩家1胜利！");
    msg.setStandardButtons(QMessageBox::Yes);
    msg.exec();
    }
}

bulletItem* gameScene::initBullet(int x)
{
    int stepSize = 70;
    tankItem * tank;
    if(x==1)tank = tank_1;
    else tank = tank_2;

    QPointF currentPosition = tank->pos();
    bulletItem *bullet;
    bullet = new bulletItem;
    addItem(bullet);
    qreal tankAngle = tank->rotation();
    qreal radians = qDegreesToRadians(tankAngle);
    qreal dx = stepSize * qSin(radians);
    qreal dy = -stepSize * qCos(radians);
    bullet -> setPos(currentPosition.x()+dx,currentPosition.y()+dy);
    return bullet;
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

void gameScene::moveTank_1()
{
    //移动速度
    qreal stepSize = 5;

    // 获取当前角度，并转化为弧度制
    qreal tankAngle = tank_1->rotation();
    qreal radians = qDegreesToRadians(tankAngle);

    QPointF currentPosition = tank_1->pos();
    qreal dx = stepSize * qSin(radians);
    qreal dy = -stepSize * qCos(radians);
    //qDebug() << tankAngle << "dx" << dx << "dy" << dy;

    //tank -> prepare();

    if (movingUp_1) {
        tank_1->setPos(currentPosition.x() + dx, currentPosition.y() + dy);
    }
    else if (movingDown_1) {
        tank_1->setPos(currentPosition.x() - dx, currentPosition.y() - dy);
    }
    if(leftRotate_1){
        tank_1->rotate(-stepSize);
    }
    else if(rightRotate_1){
        tank_1->rotate(stepSize);
    }
}

void gameScene::moveTank_2()
{
    //移动速度
    qreal stepSize = 5;

    // 获取当前角度，并转化为弧度制
    qreal tankAngle = tank_2->rotation();
    qreal radians = qDegreesToRadians(tankAngle);

    QPointF currentPosition = tank_2->pos();
    qreal dx = stepSize * qSin(radians);
    qreal dy = -stepSize * qCos(radians);
    //qDebug() << tankAngle << "dx" << dx << "dy" << dy;

    //tank -> prepare();

    if (movingUp_2) {
        tank_2->setPos(currentPosition.x() + dx, currentPosition.y() + dy);
    }
    else if (movingDown_2) {
        tank_2->setPos(currentPosition.x() - dx, currentPosition.y() - dy);
    }
    if(leftRotate_2){
        tank_2->rotate(-stepSize);
    }
    else if(rightRotate_2){
        tank_2->rotate(stepSize);
    }
}

gameScene::~gameScene()
{
    timer_1->stop();
    timer_2->stop();
    delete timer_1;
    delete timer_2;
}






