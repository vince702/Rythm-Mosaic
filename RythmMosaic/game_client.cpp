#include "game_client.h"
#include "hit.h"
#include <QFile>
#include <QTextStream>
#include <QMediaPlayer>
#include <vector>
#include "button.h"
#include <QGraphicsTextItem>
gamewindow* paper;
Keyboard* k;
QGraphicsView *view;
QMediaPlayer * menuScreenSong = new QMediaPlayer();
int songNumber = 0;
extern int playing;

extern int currentTime;
game_client::game_client()
{
paper = new gamewindow();

}

void convertNotes(std::vector<double> noteTimingList,std::vector<double> noteLocationlist, QQueue<key> &notes);
void game_client::showTitleScreen(){






     if (view) view->close();

     QGraphicsTextItem* title = new QGraphicsTextItem(QString("Rythm Mosaic \n"));
     QFont titleFont("Arial",50);
       title->setFont(titleFont);
       title->setDefaultTextColor(Qt::yellow);
       int txPos = 30 ;
       int tyPos = 50;
       title->setPos(txPos,tyPos);
       paper->addItem(title);


       QGraphicsTextItem* instructions = new QGraphicsTextItem(QString("How to Play:\n"
                                                                       " *Click the squares as they light up green \n"
                                                                       " *Hit as many notes in a row to keep a combo\n"
                                                                       " *Missed note = loss in combo \n"));
       QFont instructionFont("Arial",20);
         instructions->setFont(instructionFont);
         instructions->setDefaultTextColor(Qt::yellow);
         int ixPos = 30 ;
         int iyPos = 110;
         instructions->setPos(ixPos,iyPos);
         paper->addItem(instructions);


         QPixmap m(":/images/lake.jpg");
            paper->setBackgroundBrush(m);

         menuScreenSong->setMedia(QUrl("qrc:/songs/next to you.mp3"));
           menuScreenSong->play();

         button* playButton = new button(QString("Naru Taru"),0);
         int bxPos = this->width() - playButton->boundingRect().width()/2;
         int byPos = 200;
         playButton->setPos(bxPos,byPos);
         playButton->setPos(bxPos,byPos);
         playButton->setOpacity(Qt::transparent);
             connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
             paper->addItem(playButton);

             button* play1Button = new button(QString("Wareta Ringo"),1);
             int wxPos = this->width() - playButton->boundingRect().width()/2;
             int wyPos = 100;
             play1Button->setPos(wxPos,wyPos);
             play1Button->setPos(wxPos,wyPos);
                 connect(play1Button,SIGNAL(clicked()),this,SLOT(start()));
                 paper->addItem(play1Button);


         // create the quit button
         button* quitButton = new  button(QString("Quit"),0);

         int qxPos = this->width() - quitButton->boundingRect().width()/2;
         int qyPos = 450;

         quitButton->setPos(qxPos,qyPos);
         connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
         paper->addItem(quitButton);
         QGraphicsRectItem * topBar = new QGraphicsRectItem(0,0,750,550);
         paper->addItem(topBar);
         view = new QGraphicsView(paper);
         view->show();























}



void game_client::start(){

playing = 1;
menuScreenSong->stop();



    if (view) view->close();
    paper->clear();

   QQueue<key> notes;

    double songLength;
    QString textFileName = "";

    if (songNumber == 0) { textFileName = ":/textFiles/narutaru.txt";

       // QPixmap m(":/images/narutaru.png");

          // paper->setBackgroundBrush(m);
    }

    if (songNumber == 1) { textFileName = ":/textFiles/WaretaRingo.txt";

      //  QPixmap m(":/images/shinsekai.jpg");
           //paper->setBackgroundBrush(m);
    }


        QFile f(textFileName);

    f.open(QIODevice::ReadOnly);
    QTextStream s(&f);
    std:: vector<double> timings;
    std:: vector<double> locations;
    s >> songLength;
    while ( !s.atEnd() ) {
      double d;
      double f;
      s >> d;
      s >> f;
      timings.push_back(d);
      locations.push_back(f);

      qDebug() << d << "  " << f;

    }
    timings.pop_back();
    qDebug() << timings.at(timings.size() -1);
    qDebug() << locations.at(locations.size() -1);



   /*  int i = 0;       // tests by randomly generating notes with random timing and location


     std:: vector<int> v;
     for (int i = 1; i < 100; i++){
         int k = rand() % 2;
         if (k ==1) {v.push_back(i*200); qDebug()<< i*200;}
     }

     */
      auto getNotes = [&notes](std::vector<double> noteTimingList,std::vector<double> noteLocationlist){


          for (int i = 0; i < noteTimingList.size(); i++){
              notes.enqueue(key(noteTimingList.at(i), noteLocationlist.at(i)));
          }


      };


     getNotes(timings,locations);











    /*
    for (int i = 1; i < 11; i++){
    notes.enqueue(key(i*100));
    }
    */




    k = new Keyboard(notes);
    k->drawKeyboard(paper);



    QMediaPlayer * currentSong = new QMediaPlayer();

    if (songNumber == 0) currentSong->setMedia(QUrl("qrc:/songs/narutaru op.mp3"));
    if (songNumber == 1) currentSong->setMedia(QUrl("qrc:/songs/WaretaRingo.mp3"));
    currentSong->play();


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
