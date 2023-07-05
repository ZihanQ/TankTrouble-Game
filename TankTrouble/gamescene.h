#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QtGui>
#include <QKeyEvent>
#include <QObject>

#include "bulletitem.h"
#include "tankitem.h"

class gameScene : public QGraphicsScene
{

    Q_OBJECT

public:
    void initItem();
    void shoot();
    bulletItem* initBullet();
    explicit gameScene(QObject *parent = nullptr);
    ~gameScene();

public slots:
    void moveTank();
    void moveBullet(bulletItem* bullet,qreal radians);
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    bool isKeyPressed(int key);
    QTimer *timer;


    bool movingUp;
    bool movingDown;
    bool leftRotate;
    bool rightRotate;

    void startMoving();
    void stopMoving();

private :
    tankItem *tank;

};

#endif // GAMESCENE_H
