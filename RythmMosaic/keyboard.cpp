#include "keyboard.h"
#include "indicator.h"
#include <QDebug>
#include <QTimer>
#include <QPoint>
#include <QQueue>
#include "game_client.h"


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
int playing = 1; // tests whether or not song is playing

extern int currentTime;
extern int songNumber;
extern int songDuration;

int score =0;
int combo = 0;

extern game_client * game;
extern gamewindow * paper;

Keyboard::Keyboard()
{
  try {
         scoreDisplay = new score::score();
     }
     catch( std::exception &e ) {

         scoreDisplay = nullptr;
     }

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


    paper->addItem(scoreDisplay);

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
    QGraphicsRectItem * board = new QGraphicsRectItem(0,0,700,550);

    paper->addItem(topBar);
    paper->addItem(board);

    paper->addItem(hooprA1);
    paper->addItem(hooprA2);
    paper->addItem(hooprA3);
    paper->addItem(hooprA4);

    paper->addItem(hooprB1);
    paper->addItem(hooprB2);
    paper->addItem(hooprB3);
    paper->addItem(hooprB4);

    paper->addItem(hooprC1);
    paper->addItem(hooprC2);
    paper->addItem(hooprC3);
    paper->addItem(hooprC4);

    paper->addItem(hooprD1);
    paper->addItem(hooprD2);
    paper->addItem(hooprD3);
    paper->addItem(hooprD4);


}

void Keyboard::keyPressEvent(QKeyEvent * event){
    if (event->key() == Qt::Key_A){
        //create hitbox
        hit * hitbox = new hit(45,450,60,60);
        qDebug() << "hello";
        paper->addItem(hitbox);
        QPoint p = QCursor::pos();

    }

}
void Keyboard::playNotes(){
     currentTime++;

    if (notes.empty() == false && currentTime == notes.front().time-200)  {

        double notex = 0; // temporarily randomly spawn the notes
        double notey= 0;// ^^^^^^^


        if (notes.front().location == 1){
          notex = key1x;
          notey = key1y;
        }
        if (notes.front().location == 2){
            notex = key2x;
            notey = key1y;
        }

        if (notes.front().location == 3){
            notex = key3x;
            notey = key1y;
        }

        if (notes.front().location == 4){
            notex = key4x;
            notey = key1y;
        }

        if (notes.front().location == 5){
            notex = key1x;
            notey = key2y;
        }

        if (notes.front().location == 6){
            notex = key2x;
            notey = key2y;
        }

        if (notes.front().location == 7){
            notex = key3x;
            notey = key2y;
        }

        if (notes.front().location == 8){
            notex = key4x;
            notey = key2y;
        }

        if (notes.front().location == 9){
            notex = key1x;
            notey = key3y;
        }

        if (notes.front().location == 10){
            notex = key2x;
            notey = key3y;
        }

        if (notes.front().location == 11){
            notex = key3x;
            notey = key3y;
        }

        if (notes.front().location == 12){
            notex = key4x;
            notey = key3y;
        }

        if (notes.front().location == 13){
            notex = key1x;
            notey = key4y;
        }

        if (notes.front().location == 14){
            notex = key2x;
            notey = key4y;
        }

        if (notes.front().location == 15){
            notex = key3x;
            notey = key4y;
        }

        if (notes.front().location == 16){
            notex = key4x;
            notey = key4y;
        }

//qDebug() << "suw";

  key  *note;

  try {
         note = new key(notes.dequeue());
     }
     catch( std::exception &e ) {
         qDebug() << "error";  // optional
         note = nullptr;                  // REQUIRED!
     }





  note->setRect(notex, notey,keyRadius,keyRadius);
  note->setBrush(Qt::white);
  QTimer * timer1 = new QTimer;
  paper -> addItem(note);
   key::connect(timer1, SIGNAL(timeout()),note,SLOT(updateTimingWindow()));
   int intervalLength = 100;
   timer1->start(intervalLength);   // .1 seconds per interval, has .3 seconds until note needs to be striken



// note deleted after updateTimingWindow() comes to an end

 }

 if ( currentTime >= songDuration)  {

     qDebug() << "song ended";

     paper->clear();

     playing = 0;
     currentTime =0;

     game->showTitleScreen();

 }


}



