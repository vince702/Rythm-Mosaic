#include "gamewindow.h"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include "qmath.h"
#include "hit.h"

gamewindow::gamewindow(QObject *parent) :
    QGraphicsScene(parent)
{
    this->setBackgroundBrush(Qt::cyan);
}

void gamewindow::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    qDebug() << Q_FUNC_INFO << mouseEvent->scenePos();
    QGraphicsScene::mouseDoubleClickEvent(mouseEvent);
}

void gamewindow::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    qDebug() << Q_FUNC_INFO << mouseEvent->scenePos();
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void gamewindow::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    qDebug() << Q_FUNC_INFO << mouseEvent->scenePos();
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void gamewindow::mouseReleaseEvent(QGraphicsSceneMouseEvent * me)
{
    qDebug() << Q_FUNC_INFO << me->scenePos();
    int radius = 20;
    hit * hitbox = new hit(me->scenePos().x() - radius, me->scenePos().y() - radius, radius*2, radius*2);
    this->addItem(hitbox);
    hitbox->setBrush(Qt::yellow);


    QGraphicsScene::mouseReleaseEvent(me);
}
