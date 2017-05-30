#ifndef GAME_CLIENT_H
#define GAME_CLIENT_H
#include <QGraphicsView>
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



class game_client: public QGraphicsView
{

    Q_OBJECT
public:
    game_client();
    void showTitleScreen();
    void start(QQueue<key> notes);

};

#endif // GAME_CLIENT_H
