#include "key.h"
#include "hit.h"
#include <iostream>
#include <QDebug>
#include <QGraphicsScene>
#include "score.h"
#include "keyboard.h"

extern Keyboard * k;

key::key()
{
status = 0; //perfect, about to disappear, miss
duration = 0;
time = 0;
}

key::key(const key &k)
{
this->status = k.status; // ^^^^^^^
this->duration = k.duration;
 this->time = k.time;
}

key::key(const int time){

    status = 0;
    duration = 0;
    this->time = time;
}

void key::keyPressEvent(QKeyEvent *event){

}

void key::updateTimingWindow(){
status ++;
if (status == 2){
    this->setBrush(Qt::green);//time to strike the note
}
if (status ==6){
    this->setBrush(Qt::yellow); //signals note's about to dissappear
}
if (status == 9){
     //miss a note = reset combo
    delete this;
    k->scoreDisplay->resetCombo();
}
}
