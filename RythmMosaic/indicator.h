#ifndef INDICATOR_H
#define INDICATOR_H

#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QGraphicsScene>

extern int currentTime;
class indicator: public QObject, public QGraphicsRectItem
{

    Q_OBJECT

public:
    indicator();
    void update();


public: signals:
    void clicked();

};



#endif // INDICATOR_H
