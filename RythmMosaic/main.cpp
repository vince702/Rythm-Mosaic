#include "mainwindow.h"
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

int currentTime = 0;
extern Keyboard * k;
extern gamewindow * paper;
game_client * game;


void runGame();
void readNotes(std::vector<int> noteTimingList, QQueue<key> &notes);

int main(int argc, char *argv[])
{

    /* reads file */
    QFile f(":/textFiles/test.txt");
    f.open(QIODevice::ReadOnly);
    QTextStream s(&f);
    std:: vector<int> k;

    while ( !s.atEnd() ) {
      double d;
      s >> d;
      k.push_back(d);

    }
    k.pop_back();
    qDebug() << k.at(k.size() -1);

      QApplication a(argc, argv);
      game = new game_client();

   /*  int i = 0;       // tests by randomly generating notes with random timing and location


     std:: vector<int> v;
     for (int i = 1; i < 100; i++){
         int k = rand() % 2;
         if (k ==1) {v.push_back(i*200); qDebug()<< i*200;}
     }

     */
     QQueue<key> notes;

     readNotes(k,notes);


     game->start(notes);


     return a.exec();

}
void readNotes(std::vector<int> noteTimingList, QQueue<key> &notes){

   for (int i = 0; i < noteTimingList.size(); i++){
       notes.enqueue(key(noteTimingList.at(i)));
   }

}

void test(){
    qDebug() << "test";
}
