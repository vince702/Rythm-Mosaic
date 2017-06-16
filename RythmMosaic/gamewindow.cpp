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
 extern int playing;
 std::unique_ptr<hit> hitbox;


gamewindow::gamewindow(QObject *parent) :
    QGraphicsScene(parent)
{
    this->setBackgroundBrush(Qt::darkBlue);
}


void gamewindow::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{



    int radius = 20;
    std::unique_ptr<int> k (new int);
   std::unique_ptr<hit> hitbox(new hit(mouseEvent->scenePos().x() - radius, mouseEvent->scenePos().y() - radius, radius*2, radius*2));
    this->addItem(hitbox);
    hitbox->setBrush(Qt::yellow);

    qDebug() << currentTime - 550;
    QGraphicsScene::mousePressEvent(mouseEvent);


}


