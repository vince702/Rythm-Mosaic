#include "hit.h"
#include "keyboard.h"
#include <QGraphicsEllipseItem>
#include <QTimer>
#include "key.h"
#include <QDebug>
#include <QMediaPlayer>
extern Keyboard * k;
extern int currentTime;
extern int playing; //whether or not menu has already been loaded
QTimer * timer;
hit::hit(int x, int y, int width, int length){
    QMediaPlayer * currentSong = new QMediaPlayer();
    currentSong->setMedia(QUrl("qrc:/songs/clap.wav"));
    currentSong->play();
    setRect(x,y,width, length);





    timer   = new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(end()));
    timer->start(0);



}



void hit::end(){
   QList<QGraphicsItem *> colliding_items = collidingItems();


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

  if (k && playing == 1 ) k->scoreDisplay->resetCombo();
delete this;
  return;
}
