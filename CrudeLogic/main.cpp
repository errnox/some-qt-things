#include "mainwindow.h"
#include "graphics.h"
#include "view.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QCursor>

#include <QBrush>
#include <QPen>
#include <QColor>
#include <QGraphicsRectItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    w.setWindowState(Qt::WindowMaximized);

    w.setMenuBar(NULL);
    w.setStatusBar(NULL);

    QGraphicsScene scene;
    scene.addText("Hello there!");

    QGraphicsTextItem *movable = new QGraphicsTextItem;
    movable->setPos(50, 50);
    movable->setPlainText("This text is movable. Try it!");
    movable->setFlag(QGraphicsItem::ItemIsMovable);
    movable->setCursor(QCursor(Qt::PointingHandCursor));
    scene.addItem(movable);

    QPen rectPen(QColor(0, 255, 0, 0));
    QBrush rectBrush(QColor(0, 0, 255, 255));
    QGraphicsRectItem *rect = scene.addRect(50, 50, 120, 120, rectPen,
                                           rectBrush);
    rect->setFlag(QGraphicsItem::ItemIsMovable);

    View view;
    view.setScene(&scene);
    view.setAlignment(Qt::AlignLeft | Qt::AlignTop);
//    view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setMouseTracking(true);
    view.show();

    w.setCentralWidget(&view);

//    Graphics graphics(scene, view);

    return a.exec();
}
