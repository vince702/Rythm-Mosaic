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
    this->location = k.location;
}

key::key(const int time){

    status = 0;
    duration = 0;
    this->location = 0;
    this->time = time;
}

key::key(const int time, const int location){

    status = 0;
    duration = 0;
    this->time = time;
    this->location = location;
}

void key::keyPressEvent(QKeyEvent *event){
   //make it in the future , so that pressing a key is an option instead of only clicking the mouse
    //to strike a note
}

void key::updateTimingWindow(){

if (status == 2){
    this->setBrush(Qt::green);//time to strike the note
}

if (status >= 6 && duration == 0){
     //miss a note = reset combo
    try{
    delete this;}
    catch(std::exception &e){return;};


    k->scoreDisplay->resetCombo();
}
if (status >= 6 && duration== 1){
     //miss a note = reset combo
    k->scoreDisplay->increase();
    k->scoreDisplay->increaseCurrentCombo();
    try{
    delete this;}
    catch(std::exception &e){return;};
}
status ++;



}
