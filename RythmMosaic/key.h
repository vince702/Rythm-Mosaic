#ifndef KEY_H
#define KEY_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
class key: public QObject, public QGraphicsRectItem
{

    Q_OBJECT

public:
    int status;
    int duration;
    int time;
    int location;
    key();
    key(const key &k);
    key(const int time);
    key(const int time, const int location);
    void keyPressEvent(QKeyEvent *event);
    key& operator=(const key& );
public slots:
     void updateTimingWindow();




};

#endif // KEY_H
