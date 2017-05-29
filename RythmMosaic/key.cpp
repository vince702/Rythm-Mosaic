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

key::key(const key &k)
{
this->status = k.status; //0-1 = perfect, 1-2 = good, 2-3 = ok, 3+ = bad/miss
this->duration = k.duration;
}


void key::keyPressEvent(QKeyEvent *event){

}

void key::updateTimingWindow(){
status ++;
if (status == 2){
    this->setBrush(Qt::green);
}
if (status ==6){
    this->setBrush(Qt::yellow);
}
if (status == 9){
    delete this;
}
}
