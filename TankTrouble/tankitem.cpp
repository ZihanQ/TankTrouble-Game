#include "tankitem.h"

tankItem::tankItem()
{
    // 设置图形项的位置
    setPos(250, 250);
}

QRectF tankItem::boundingRect() const
{
    // 定义坦克绘制区域的边界矩形
    return QRectF(-20, -30, 40, 60);
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

    // 绘制坦克的炮塔
    painter->setBrush(Qt::darkRed);
    painter->drawEllipse(-5, -30, 10, 10);
}


