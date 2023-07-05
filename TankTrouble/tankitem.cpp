#include "tankitem.h"

tankItem::tankItem()
{
    // 设置图形项的位置
    setPos(250, 250);
}

QRectF tankItem::boundingRect() const
{
    // 定义坦克绘制区域的边界矩形
    //return QRectF(pos().x()-15, pos().y()-25, 30, 40);
    return QRectF(-15, -25, 30, 40);
}

void tankItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // 绘制坦克的外观
    painter ->setRenderHint(QPainter::Antialiasing);

    // 绘制坦克的底座
    painter->setBrush(Qt::darkGreen);
    painter->drawRect(-15, -25, 30, 40);
    //painter->drawRect(pos().x()-15, pos().y()-25, 30, 40);

    // 绘制坦克的炮塔
    painter->setBrush(Qt::darkRed);
    //painter->drawEllipse(pos().x()-5, pos().y()-30, 10, 10);
    painter->drawEllipse(-5, -30, 10, 10);
    painter->setBrush(Qt::darkBlue);
    //painter->drawRect(pos().x()-1,pos().y()-50,2,25);
    painter->drawRect(-1,-50,2,25);
}



