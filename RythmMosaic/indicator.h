#ifndef INDICATOR_H
#define INDICATOR_H

#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QGraphicsScene>

class indicator: public QObject, public QGraphicsRectItem
{

    Q_OBJECT

public:
    indicator(int x, int y, int width, int length);
    int x= 0;
    int y= 0;
    int width=0;
    int length=0;
    int countdown = 100;

public slots:
    void shrink();

};



#endif // INDICATOR_H
