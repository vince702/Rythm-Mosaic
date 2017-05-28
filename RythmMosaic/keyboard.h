#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include "key.h"
#include "hit.h"
#include "mainwindow.h"
#include <QObject>


class Keyboard:  public QObject,public QGraphicsEllipseItem {

Q_OBJECT

public:
    Keyboard();
    void drawKeyboard(QGraphicsScene * scene);
    void keyPressEvent(QKeyEvent * event);

public slots:
    void playNotes();


};

#endif // KEYBOARD_H

