#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QtGui>
#include <QKeyEvent>
#include <QObject>

#include "tankitem.h"

class gameScene : public QGraphicsScene
{

    Q_OBJECT

public:
    void initItem();
    explicit gameScene(QObject *parent = nullptr);
    ~gameScene();

public slots:
    void moveTank();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    bool isKeyPressed(int key);
    QTimer *timer;
    bool movingUp;
    bool movingDown;

    void startMoving();
    void stopMoving();

private :
    tankItem *tank;
};

#endif // GAMESCENE_H
