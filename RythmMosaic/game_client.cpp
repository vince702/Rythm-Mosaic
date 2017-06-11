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
int songDuration = 90000; //default length of beatmap is around 1:30
extern int playing;


extern int currentTime;
game_client::game_client()
{
paper = new gamewindow();

}


/***************************************************************
 * Generic Function to Add Keys from any vector of times and locations
 * *************************************************************/

template<typename InputIterator, typename Container>
void convertToKeys( InputIterator v1Start,InputIterator v2Start,InputIterator v1End, InputIterator v2End, Container &c ){
    while ( v1Start != v1End ){
       try {c.enqueue(key(*v1Start, *v2Start));}
        catch(std::exception &e ){
            try{
            c.push_back(key(*v1Start, *v2Start));}
            catch(std::exception &e){
                qDebug() << "invalid container";
            }
        }

        v1Start++;
        v2Start++;
    }
    return;
}

/****************************************************************/


void game_client::showTitleScreen(){

    auto populateTitleScreen = [](){};

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

    playing = 1;  // signifies that a beatmap has started to be played
    menuScreenSong->stop();

    if (view) view->close();
    paper->clear();  // clears the window for a new game

   QQueue<key> notes;


    QString textFileName = "";

    if (songNumber == 0) { textFileName = ":/textFiles/narutaru.txt";

       // QPixmap m(":/images/narutaru.png");
          // paper->setBackgroundBrush(m);   // meh, don't like changing backgrounds too be honest. Feels weird.
    }

    if (songNumber == 1) { textFileName = ":/textFiles/WaretaRingo.txt";

      //  QPixmap m(":/images/shinsekai.jpg");
           //paper->setBackgroundBrush(m);
    }




    /**********************************************************
                           LAMBDA FUNCTIONS
    **************************************************************/

    QFile f(textFileName);
    f.open(QIODevice::ReadOnly);

    std:: vector<double> timings;
    std:: vector<double> locations;

    /*  reads data from file, adds to a vector of timings and location, each entry represents the time played
        of the note, and where on the grid it will be played  */
        auto dataToVector = [&f,&timings,&locations](int &beatmapDuration){
         QTextStream s(&f);
       int songLength = 0;
       s >> beatmapDuration;
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

      f.close();
     };

     //reads the data from the timing and location list to creat a key, and adds to queue of keys to be played
      auto getNotes = [&notes](std::vector<double> &noteTimingList,std::vector<double> &noteLocationList){

          convertToKeys(noteTimingList.begin(), noteLocationList.begin(),noteTimingList.end(),noteLocationList.end(),notes);
      };




     //calling lambda functions
      dataToVector(songDuration);
      getNotes(timings,locations);


     /****************************************************/


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
