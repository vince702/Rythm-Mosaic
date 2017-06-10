#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>


extern int songNumber;


button::button(QString word, int trackNo, QGraphicsItem * parent) : QGraphicsRectItem(parent)
{
setRect(0,0,200,50);
QBrush brush;
brush.setStyle(Qt::SolidPattern);
brush.setColor(Qt::darkMagenta);
setBrush(brush);
QGraphicsTextItem* text = new QGraphicsTextItem(word,this);
int x = rect().width()/2 - text->boundingRect().width()/2;
int y = rect().height()/2 - text->boundingRect().height()/2;
text->setPos(x,y);
setAcceptHoverEvents(true);
trackNumber = trackNo;
}

void button::mousePressEvent(QGraphicsSceneMouseEvent * event){
    emit clicked();
}

void button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
    songNumber = this->trackNumber;
}

void button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkMagenta);
    setOpacity(Qt::transparent);
    setBrush(brush);
     songNumber = this->trackNumber;
}
