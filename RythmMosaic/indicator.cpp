#include "indicator.h"
#include <QTimer>

indicator::indicator(int x, int y, int width, int length){
    setRect(x,y, width, length);

    QTimer * timerIndicator = new QTimer;
    connect(timerIndicator, SIGNAL(timeout()),this,SLOT(shrink()));
    timerIndicator->start(400);

}

void indicator::shrink(){

    countdown--;



    setRect(x,y, width, length);


    if (this->countdown = 0) delete this;

}
