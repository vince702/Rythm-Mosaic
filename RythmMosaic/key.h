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
    key();
    key(const key &k);
    void keyPressEvent(QKeyEvent *event);
    key& operator=(const key& );
public slots:
     void updateTimingWindow();




};

#endif // KEY_H
