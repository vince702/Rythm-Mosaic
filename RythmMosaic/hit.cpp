#include "hit.h"
#include <QGraphicsEllipseItem>
#include <QTimer>

#include <QDebug>
hit::hit(int x, int y, int width, int length){
    setRect(x,y,width, length);
    QTimer * timer = new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(end()));
    timer->start(75);
}

void hit::end(){
    qDebug() << "ended";
    delete this;
}
