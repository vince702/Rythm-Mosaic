#include "keyboard.h"
#include "indicator.h"
#include <QDebug>
#include <QTimer>
#include <QPoint>
#include <QQueue>




int key1x = 50;
int key2x = 150;
int key3x = 250;
int key4x = 350;
int keyboardY = 450;
int key1y = 100;
int key2y = 200;
int key3y = 300;
int key4y = 400;
int keyRadius = 80;

int score =0;
int combo = 0;




Keyboard::Keyboard()
{
  scoreDisplay = new score::score();
  bpm = 60;

}

Keyboard::Keyboard(QQueue<key> noteList)
{
   notes.swap(noteList);
   scoreDisplay = new score::score();
   bpm = 60; // default 1 beat / sec

}
//coordinates of hitboxes





void Keyboard::drawKeyboard(QGraphicsScene * scene)
{


    scene->addItem(scoreDisplay);

    QGraphicsRectItem * hooprA1 = new QGraphicsRectItem();
    hooprA1->setRect(key1x,key1y,keyRadius,keyRadius);
    QGraphicsRectItem * hooprA2 = new QGraphicsRectItem();
    hooprA2->setRect(key2x,key1y,keyRadius,keyRadius);
    QGraphicsRectItem * hooprA3 = new QGraphicsRectItem();
    hooprA3->setRect(key3x,key1y,keyRadius,keyRadius);
    QGraphicsRectItem * hooprA4 = new QGraphicsRectItem();
    hooprA4->setRect(key4x,key1y,keyRadius,keyRadius);

    QGraphicsRectItem * hooprB1 = new QGraphicsRectItem();
    hooprB1->setRect(key1x,key2y,keyRadius,keyRadius);
    QGraphicsRectItem * hooprB2 = new QGraphicsRectItem();
    hooprB2->setRect(key2x,key2y,keyRadius,keyRadius);
    QGraphicsRectItem * hooprB3 = new QGraphicsRectItem();
    hooprB3->setRect(key3x,key2y,keyRadius,keyRadius);
    QGraphicsRectItem * hooprB4 = new QGraphicsRectItem();
    hooprB4->setRect(key4x,key2y,keyRadius,keyRadius);

    QGraphicsRectItem * hooprC1 = new QGraphicsRectItem();
    hooprC1->setRect(key1x,key3y,keyRadius,keyRadius);
    QGraphicsRectItem * hooprC2 = new QGraphicsRectItem();
    hooprC2->setRect(key2x,key3y,keyRadius,keyRadius);
    QGraphicsRectItem * hooprC3 = new QGraphicsRectItem();
    hooprC3->setRect(key3x,key3y,keyRadius,keyRadius);
    QGraphicsRectItem * hooprC4 = new QGraphicsRectItem();
    hooprC4->setRect(key4x,key3y,keyRadius,keyRadius);

    QGraphicsRectItem * hooprD1 = new QGraphicsRectItem();
    hooprD1->setRect(key1x,key4y,keyRadius,keyRadius);
    QGraphicsRectItem * hooprD2 = new QGraphicsRectItem();
    hooprD2->setRect(key2x,key4y,keyRadius,keyRadius);
    QGraphicsRectItem * hooprD3 = new QGraphicsRectItem();
    hooprD3->setRect(key3x,key4y,keyRadius,keyRadius);
    QGraphicsRectItem * hooprD4 = new QGraphicsRectItem();
    hooprD4->setRect(key4x,key4y,keyRadius,keyRadius);



    QGraphicsRectItem * topBar = new QGraphicsRectItem(0,0,700,50);
    QGraphicsRectItem * board = new QGraphicsRectItem(0,0,700,600);

    scene->addItem(topBar);
    scene->addItem(board);

    scene->addItem(hooprA1);
    scene->addItem(hooprA2);
    scene->addItem(hooprA3);
    scene->addItem(hooprA4);

    scene->addItem(hooprB1);
    scene->addItem(hooprB2);
    scene->addItem(hooprB3);
    scene->addItem(hooprB4);

    scene->addItem(hooprC1);
    scene->addItem(hooprC2);
    scene->addItem(hooprC3);
    scene->addItem(hooprC4);

    scene->addItem(hooprD1);
    scene->addItem(hooprD2);
    scene->addItem(hooprD3);
    scene->addItem(hooprD4);


}

void Keyboard::keyPressEvent(QKeyEvent * event){
    if (event->key() == Qt::Key_A){
        //create hitbox
        hit * hitbox = new hit(45,450,60,60);
        qDebug() << "hello";
        scene()->addItem(hitbox);
        QPoint p = QCursor::pos();

    }

}
void Keyboard::playNotes(){

    if (notes.empty() == false)  {



  key  *note = new key(notes.dequeue());

  int notex = rand() % 4; // temporarily randomly spawn the notes
  int notey = rand() % 4;// ^^^^^^^

  if (notex == 0) notex = key1x;
  if (notex == 1) notex = key2x;
  if (notex == 2) notex = key3x;
  if (notex == 3) notex = key4x;

  if (notey == 0) notey = key1y;
  if (notey == 1) notey = key2y;
  if (notey == 2) notey = key3y;
  if (notey == 3) notey = key4y;

  indicator* INDICATOR = new indicator(notex-10, notey-10, keyRadius + 20, keyRadius +20);
  INDICATOR->setBrush(Qt::white);
  scene() -> addItem(INDICATOR);


  note->setRect(notex, notey,keyRadius,keyRadius);
  note->setBrush(Qt::white);
  QTimer * timer = new QTimer;
   key::connect(timer, SIGNAL(timeout()),note,SLOT(updateTimingWindow()));
   timer->start(100);   // .1 seconds per interval, has .3 seconds until note needs to be striken

  scene() -> addItem(note);



 }

 if (notes.empty())  {

     qDebug() << "song ended";


 }

}



