#ifndef BULLETITEM_H
#define BULLETITEM_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QRectF>

class bulletItem : public QGraphicsItem
{
public:
    bulletItem();
    ~bulletItem();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void getPos(int x,int y){pos_x = x, pos_y =y ;}

private:

    int pos_x=0;
    int pos_y=0;
};

#endif // BULLETITEM_H
