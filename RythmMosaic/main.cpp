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

gamewindow* paper;
Keyboard* k;


void runGame();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int i = 0;
    while(true) {
        runGame();
        i++;
        if (i == 1) break;
    }



    return a.exec();

}


void runGame(){
    paper = new gamewindow();

    QQueue<key> notes;;
    key *s = new key();


    for (int i = 0; i < 5; i++){
    notes.enqueue(key());
    }


    k = new Keyboard(notes);
    k->drawKeyboard(paper);




    QGraphicsRectItem * topBar = new QGraphicsRectItem(0,0,500,50);
    qDebug() << "hello";



    paper->addItem(k);
    k->setFlag(QGraphicsItem::ItemIsFocusable);
    k->setFocus();
    QGraphicsView *view = new QGraphicsView(paper);
    view->show();


    QTimer * timer = new QTimer();
    Keyboard::connect(timer, SIGNAL(timeout()),k,SLOT(playNotes()));
    timer->start(900);
}

void test(){
    qDebug() << "test";
}
