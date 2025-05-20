#ifndef ANIMATEDRECTITEM_H
#define ANIMATEDRECTITEM_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

class AnimatedRectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    AnimatedRectItem(const QRectF &rect, QGraphicsItem *parent = nullptr);

    QGraphicsTextItem *label; // label attached to this rect
};

#endif // ANIMATEDRECTITEM_H
