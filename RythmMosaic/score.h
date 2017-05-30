#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class score: public QGraphicsTextItem
{
public:
    score(QGraphicsItem * parent = 0);
    int hitcount = 0;
    int currentCombo = 0;
    int maxCombo = 0;
    int acc = 0;


    void increase();
    void increaseCurrentCombo();
    void resetCombo();
};

#endif // SCORE_H
