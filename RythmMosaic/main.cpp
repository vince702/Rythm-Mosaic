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

int currentTime = 0;
extern Keyboard * k;
extern gamewindow * paper;
game_client * game;


void runGame();

int main(int argc, char *argv[])
{

     int i = 0;
     QApplication a(argc, argv);
     game = new game_client();
     QQueue<key> notes;
     game->start(notes);





    return a.exec();

}




void test(){
    qDebug() << "test";
}
