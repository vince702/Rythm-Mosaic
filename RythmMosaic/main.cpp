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


extern Keyboard * k;
extern gamewindow * paper;

void runGame();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int i = 0;
    game_client * game = new game_client();
    while(true) {
        game->start();
        i++;
        if (i == 1) break;
    }



    return a.exec();

}




void test(){
    qDebug() << "test";
}
