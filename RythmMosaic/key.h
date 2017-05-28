#ifndef KEY_H
#define KEY_H
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
class key: public QObject, public QGraphicsRectItem
{

    Q_OBJECT

public:
    int status;
    int duration;
    key();
    void keyPressEvent(QKeyEvent *event);

public slots:
     void updateTimingWindow();




};

#endif // KEY_H
