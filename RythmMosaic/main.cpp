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


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gamewindow * paper = new gamewindow();

    Keyboard * k = new Keyboard();
    k->drawKeyboard(paper);

    QGraphicsRectItem * topBar = new QGraphicsRectItem(0,0,500,50);
    std::cout << "Welcome";
    paper->addItem(k);
    k->setFlag(QGraphicsItem::ItemIsFocusable);
    k->setFocus();
    QGraphicsView *view = new QGraphicsView(paper);
    view->show();

    QTimer * timer = new QTimer();
    Keyboard::connect(timer, SIGNAL(timeout()),k,SLOT(playNotes()));
    timer->start(700);


    return a.exec();

}
