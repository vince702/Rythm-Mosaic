#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>


class button :public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    int trackNumber;
    button(QString word, int trackNo, QGraphicsItem* parent = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

 signals:
    void clicked();
  private:
    QGraphicsTextItem* text;


};

#endif // BUTTON_H
