#include "indicator.h"
#include <QTimer>
extern int currentTime;

indicator::indicator(){

}

void indicator::update(){
    emit clicked();
}


