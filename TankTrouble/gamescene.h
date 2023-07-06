#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QtGui>
#include <QKeyEvent>
#include <QObject>
#include <QMessageBox>

#include "bulletitem.h"
#include "tankitem.h"

class gameScene : public QGraphicsScene
{

    Q_OBJECT

public:

    explicit gameScene(QObject *parent = nullptr);
    ~gameScene();

public slots:
    void moveTank_1();
    void moveTank_2();
    void moveBullet(bulletItem* bullet,qreal radians);
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    void initItem();
    void initStatus();
    void shoot(int x);
    void startMoving();
    void stopMoving();
    void checkBulletTankCollision(bulletItem* bullet);

    bulletItem* initBullet(int x);

    bool isKeyPressed(int key);
    QTimer *timer_1;
    QTimer *timer_2;

    QList<bulletItem*> bullets;
    QList<QTimer*> timers;

    bool movingUp_1;
    bool movingDown_1;
    bool leftRotate_1;
    bool rightRotate_1;

    bool movingUp_2;
    bool movingDown_2;
    bool leftRotate_2;
    bool rightRotate_2;



private :
    int num=0;
    bool tankStatus_1 = false;
    bool tankStatus_2 = false;
    tankItem *tank_1;
    tankItem *tank_2;

};

#endif // GAMESCENE_H
