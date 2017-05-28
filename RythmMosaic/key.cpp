#include "key.h"
#include "hit.h"
#include <iostream>
#include <QDebug>
#include <QGraphicsScene>
key::key()
{
status = 0; //0-1 = perfect, 1-2 = good, 2-3 = ok, 3+ = bad/miss
duration = 0;
}

void key::keyPressEvent(QKeyEvent *event){

}

void key::updateTimingWindow(){
status ++;
if (status == 3){
    this->setBrush(Qt::yellow);
}
if (status ==4){
    this->setBrush(Qt::red);
}
if (status == 5){
    delete this;
}
}
