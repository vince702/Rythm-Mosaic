#ifndef HIT_H
#define HIT_H



#include <QGraphicsEllipseItem>
#include <QObject>


class hit: public QObject, public QGraphicsEllipseItem{


Q_OBJECT


 public:
    int status = 0;


    hit(int x, int y, int width, int length);

public slots:
    void end();


};

#endif // HIT_H
