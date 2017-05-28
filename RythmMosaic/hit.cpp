#include "hit.h"
#include <QGraphicsEllipseItem>
#include <QTimer>

#include <QDebug>
hit::hit(int x, int y, int width, int length){
    setRect(x,y,width, length);

    QTimer * timer = new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(end()));
    timer->start(50);

}

void hit::end(){
   delete this;
}
