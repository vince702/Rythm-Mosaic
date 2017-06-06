#include "gamewindow.h"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include "key.h"
#include "keyboard.h"
#include "hit.h"
#include <QTimer>
 extern int currentTime;


gamewindow::gamewindow(QObject *parent) :
    QGraphicsScene(parent)
{
    this->setBackgroundBrush(Qt::darkBlue);
}



void gamewindow::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    //qDebug() << Q_FUNC_INFO << mouseEvent->scenePos();

    int radius = 20;
    hit * hitbox = new hit(mouseEvent->scenePos().x() - radius, mouseEvent->scenePos().y() - radius, radius*2, radius*2);
    this->addItem(hitbox);
    hitbox->setBrush(Qt::yellow);
    qDebug() << currentTime - 550;
    QGraphicsScene::mousePressEvent(mouseEvent);



/*
    key  *note = new key(); // to adjust for note timing when creating beatmaps


     QTimer * timer1 = new QTimer;

     key::connect(timer1, SIGNAL(timeout()),note,SLOT(updateTimingWindow()));
     int intervalLength = 100;
     timer1->start(intervalLength);
     */



}

void gamewindow::mouseReleaseEvent(QGraphicsSceneMouseEvent * me)
{

    QGraphicsScene::mouseReleaseEvent(me);
}
