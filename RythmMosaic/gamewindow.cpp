#include "gamewindow.h"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsPathItem>
#include <QPainterPath>

#include "hit.h"



gamewindow::gamewindow(QObject *parent) :
    QGraphicsScene(parent)
{
    this->setBackgroundBrush(Qt::cyan);
}

void gamewindow::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent)
{

}

void gamewindow::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent)
{

    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void gamewindow::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    qDebug() << Q_FUNC_INFO << mouseEvent->scenePos();

    int radius = 20;
    hit * hitbox = new hit(mouseEvent->scenePos().x() - radius, mouseEvent->scenePos().y() - radius, radius*2, radius*2);
    this->addItem(hitbox);
    hitbox->setBrush(Qt::yellow);

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void gamewindow::mouseReleaseEvent(QGraphicsSceneMouseEvent * me)
{
    qDebug() << Q_FUNC_INFO << me->scenePos();



    QGraphicsScene::mouseReleaseEvent(me);
}
