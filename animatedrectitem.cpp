#include "animatedrectitem.h"

AnimatedRectItem::AnimatedRectItem(const QRectF &rect, QGraphicsItem *parent)
    : QGraphicsRectItem(rect, parent)
{
    label = new QGraphicsTextItem(this); // attach label to the rect
}
