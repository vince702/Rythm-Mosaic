#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include "key.h"
#include "hit.h"
#include "mainwindow.h"
#include <QObject>
#include "indicator.h"
#include <QQueue>
#include "score.h"

class Keyboard:  public QObject,public QGraphicsEllipseItem {

Q_OBJECT

public:
    Keyboard();
    Keyboard(QQueue<key> noteList);
    void drawKeyboard(QGraphicsScene * scene);
    void keyPressEvent(QKeyEvent * event);
    score * scoreDisplay;
    int bpm = 60;
    QQueue<key> notes;

public slots:
    void playNotes();


};

#endif // KEYBOARD_H

