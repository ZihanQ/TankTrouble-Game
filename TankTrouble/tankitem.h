#ifndef TANKITEM_H
#define TANKITEM_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QRectF>

class tankItem : public QGraphicsItem
{
public:
    tankItem();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void moveTank(int dx,int dy);

    void rotate(qreal angle){setRotation(rotation() + angle);}

};

#endif // TANKITEM_H
