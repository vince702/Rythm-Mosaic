#include "game_client.h"

gamewindow* paper;
Keyboard* k;
QGraphicsView *view;
extern int currentTime;
game_client::game_client()
{
paper = new gamewindow();

}

void game_client::showTitleScreen(){

     view->close();
     QQueue<key> notes;
     start(notes);

}

void game_client::start(QQueue<key> notes){

    paper->clear();
    currentTime = 0;

    key *s = new key();


    /*
    for (int i = 1; i < 11; i++){
    notes.enqueue(key(i*100));
    }
    */

    notes.enqueue(key(1000));
    notes.enqueue(key(1500));
    notes.enqueue(key(2500));
    notes.enqueue(key(3000));
    notes.enqueue(key(4400));



    k = new Keyboard(notes);
    k->drawKeyboard(paper);




    QGraphicsRectItem * topBar = new QGraphicsRectItem(0,0,550,70);
    qDebug() << "hello";



    paper->addItem(k);
    k->setFlag(QGraphicsItem::ItemIsFocusable);
    k->setFocus();

    view = new QGraphicsView(paper);
    view->show();


    QTimer * timer = new QTimer();
    Keyboard::connect(timer, SIGNAL(timeout()),k,SLOT(playNotes()));
    timer->start(1);

}
