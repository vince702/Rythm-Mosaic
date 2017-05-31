#include "hit.h"
#include "keyboard.h"
#include <QGraphicsEllipseItem>
#include <QTimer>
#include "key.h"
#include <QDebug>
#include <QMediaPlayer>
extern Keyboard * k;

hit::hit(int x, int y, int width, int length){
    QMediaPlayer * currentSong = new QMediaPlayer();
    currentSong->setMedia(QUrl("qrc:/songs/clap.wav"));
    currentSong->play();
    setRect(x,y,width, length);

    QTimer * timer = new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(end()));
    timer->start(.01);


}

void hit::end(){
   QList<QGraphicsItem *> colliding_items = collidingItems();
   /*
  for (int i = 0,n = colliding_items.size(); i < n; ++i){
     if (typeid(*(colliding_items[i])) == typeid(key)){

         k->scoreDisplay->increase();
         k->scoreDisplay->increaseCurrentCombo();
         (*(colliding_items[i])).status = 10;

         delete colliding_items[i];
         delete this;
         return;


     }

   }
   */

  foreach(QGraphicsItem * i , colliding_items)
  {
      key * item = dynamic_cast<key *>(i);
      if (item)
      {
          scene()->removeItem(item);
          delete this;

          item->duration = 1;

          return;
      }
  }
   k->scoreDisplay->resetCombo();
   delete this;
}
