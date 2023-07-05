#include "bulletitem.h"

bulletItem::bulletItem()
{
    setPos(0,0);
}

QRectF bulletItem::boundingRect() const
{
    // 定义坦克绘制区域的边界矩形
    return QRectF(-1, -1, 2, 2);
}

void bulletItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(Qt::darkYellow);
    painter->drawEllipse(-1, -1, 2, 2);

}

bulletItem::~bulletItem(){

}
