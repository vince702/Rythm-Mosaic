#include "hit.h"
#include "keyboard.h"
#include <QGraphicsEllipseItem>
#include <QTimer>
#include "key.h"
#include <QDebug>
extern Keyboard * k;

hit::hit(int x, int y, int width, int length){
    setRect(x,y,width, length);

    QTimer * timer = new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(end()));
    timer->start(20);

}

void hit::end(){
   QList<QGraphicsItem *> colliding_items = collidingItems();
  for (int i = 0,n = colliding_items.size(); i < n; ++i){
     if (typeid(*(colliding_items[i])) == typeid(key)){

         k->scoreDisplay->increase();
         k->scoreDisplay->increaseCurrentCombo();
         delete colliding_items[i];
         delete this;
         return;


     }

   }
   k->scoreDisplay->resetCombo();
   delete this;
}
