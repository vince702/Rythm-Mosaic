#include "game_client.h"
#include "hit.h"

#include <QMediaPlayer>
#include <vector>
gamewindow* paper;
Keyboard* k;
QGraphicsView *view;
extern int currentTime;
game_client::game_client()
{
paper = new gamewindow();

}

void convertNotes(std::vector<int> noteTimingList, QQueue<key> &notes);
void game_client::showTitleScreen(){

     view->close();
     QQueue<key> notes;


     std::vector<int> v;
     for (int i = 1; i < 10; i++){
         v.push_back(i * 500);
     }
     convertNotes(v,notes);

     start(notes);

}

void convertNotes(std::vector<int> noteTimingList, QQueue<key> &notes){

   for (int i = 0; i < noteTimingList.size(); i++){
       notes.enqueue(key(noteTimingList.at(i)));
   }

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




    k = new Keyboard(notes);
    k->drawKeyboard(paper);



    QMediaPlayer * currentSong = new QMediaPlayer();
    currentSong->setMedia(QUrl("qrc:/songs/narutaru op.mp3"));
    currentSong->play();

    QGraphicsRectItem * topBar = new QGraphicsRectItem(0,0,550,70);
    qDebug() << "hello";

    int radius = 20;
    hit * hitbox = new hit(0,0, radius*2, radius*2);
    paper->addItem(hitbox);
    hitbox->setBrush(Qt::yellow);

    paper->addItem(k);
    k->setFlag(QGraphicsItem::ItemIsFocusable);
    k->setFocus();

    view = new QGraphicsView(paper);
    view->show();


    QTimer * timer = new QTimer();
    Keyboard::connect(timer, SIGNAL(timeout()),k,SLOT(playNotes()));
    timer->start(1);



}
