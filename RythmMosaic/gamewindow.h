#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QList>

class gamewindow : public QGraphicsScene
{

    Q_OBJECT
public:
    explicit gamewindow(QObject *parent = 0);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
signals:
   void clicked();
public slots:

private:

};

#endif // GAMEWINDOW_H
