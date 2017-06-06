
#include <QApplication>
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include "key.h"
#include "keyboard.h"
#include "gamewindow.h"
#include <QTimer>
#include <QQueue>
#include "score.h"
#include <QDebug>
#include "game_client.h"
#include <vector>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QDesktopWidget>
int currentTime = 0;
int songLength = 0;
extern Keyboard * k;



extern gamewindow * paper;
game_client * game;


void runGame();
void readNotes(std::vector<double> noteTimingList,std::vector<double> noteLocationlist, QQueue<key> &notes);

int main(int argc, char *argv[])
{

    /* reads file */
    QFile f(":/textFiles/narutaru.txt");
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

      QApplication a(argc, argv);
      int screen_width = QApplication::desktop()->width();
          int screen_height = QApplication::desktop()->height();

      game = new game_client();

   /*  int i = 0;       // tests by randomly generating notes with random timing and location


     std:: vector<int> v;
     for (int i = 1; i < 100; i++){
         int k = rand() % 2;
         if (k ==1) {v.push_back(i*200); qDebug()<< i*200;}
     }

     */
     QQueue<key> notes;

     readNotes(timings,locations, notes);


     game->showTitleScreen();


     return a.exec();

}
void readNotes(std::vector<double> noteTimingList,std::vector<double> noteLocationlist, QQueue<key> &notes){

   for (int i = 0; i < noteTimingList.size(); i++){
       key k = key(noteTimingList.at(i), noteLocationlist.at(i));
       qDebug() << k.location;
       notes.enqueue(k);
   }

}

void test(){
    qDebug() << "test";
}
