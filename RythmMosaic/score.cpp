#include "score.h"
#include <QFont>

score::score(QGraphicsItem * parent) : QGraphicsTextItem(parent)
{

 hitcount = 0;
 currentCombo = 0;
 acc = 0;

 setPlainText(QString("HIT_COUNT: ") +  QString::number(hitcount) + "              "
              + QString("COMBO: ") +  QString::number(currentCombo) + "              "
              + QString("MAX COMBO: ") +  QString::number(acc));


 setDefaultTextColor(Qt::red);
 setFont(QFont("arial", 15));


}

void score::increase(){

   hitcount++;
   setPlainText(QString("HIT_COUNT: ") +  QString::number(hitcount) + "              "
                + QString("CURRENT COMBO: ") +  QString::number(currentCombo) + "              "
                + QString("MAX COMBO: ") +  QString::number(maxCombo));

}

void score::increaseCurrentCombo(){

   currentCombo++;
   if (currentCombo > maxCombo) maxCombo++;
   setPlainText(QString("HIT_COUNT: ") +  QString::number(hitcount) + "              "
                + QString("CURRENT COMBO: ") +  QString::number(currentCombo) + "              "
                + QString("MAX COMBO: ") +  QString::number(maxCombo));

}

void score::resetCombo(){
    currentCombo = 0;
    setPlainText(QString("HIT_COUNT: ") +  QString::number(hitcount) + "              "
                 + QString("CURRENT COMBO: ") +  QString::number(currentCombo) + "              "
                 + QString("MAX COMBO: ") +  QString::number(maxCombo));
}

