#include "game_client.h"
gamewindow* paper;
Keyboard* k;
game_client::game_client()
{

}

void game_client::start(){
    paper = new gamewindow();

    QQueue<key> notes;;
    key *s = new key();


    for (int i = 0; i < 5; i++){
    notes.enqueue(key());
    }


    k = new Keyboard(notes);
    k->drawKeyboard(paper);




    QGraphicsRectItem * topBar = new QGraphicsRectItem(0,0,500,50);
    qDebug() << "hello";



    paper->addItem(k);
    k->setFlag(QGraphicsItem::ItemIsFocusable);
    k->setFocus();
    QGraphicsView *view = new QGraphicsView(paper);
    view->show();


    QTimer * timer = new QTimer();
    Keyboard::connect(timer, SIGNAL(timeout()),k,SLOT(playNotes()));
    timer->start(900);
}
