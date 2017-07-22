#include "view.h"
#include "graphics.h"

#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QPointF>

View::View()
{
}

void View::draw()
{
    QPen pen(QColor(0, 0, 0, 140), 3, Qt::SolidLine, Qt::RoundCap,
             Qt::RoundJoin);
    QBrush brush(QColor(255, 50, 20, 140), Qt::SolidPattern);
    scene()->addRect(10, 20, 90, 120, pen, brush);

    QBrush gridBrush(QColor(30, 200, 30, 100), Qt::SolidPattern);
    QPen gridPen(QColor(0, 0, 0, 0), 1, Qt::SolidLine, Qt::SquareCap,
                 Qt::BevelJoin);
    int w = 15;
    int h = w;
    int xGap = 60+w;
    int yGap = 60+w;
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 20; ++y) {
                scene()->addRect(x*xGap, y*yGap, w, h, gridPen,
                                 gridBrush);

                QGraphicsTextItem *label = new QGraphicsTextItem;
                label->setPos(x*xGap+5, y*xGap+5);
                label->setPlainText(QString::number(x*xGap)
                                    + "|"
                                    + QString::number(y*yGap));
                scene()->addItem(label);
        }
    }

    centerOn(width()/2, height()/2);
}

void View::drawCircleAtPos(int x, int y)
{
    int w = 20;
    int h = w;

    QPen pen(QColor(0, 0, 0, 0), 1, Qt::SolidLine, Qt::SquareCap,
         Qt::BevelJoin);
    QBrush brush(QColor(50, 50, 180, 80), Qt::SolidPattern);

    scene()->addEllipse(x-(w/2), y-(h/2), w, h, pen, brush);
}

void View::drawRectAtPos(int x, int y)
{
    int w = 20;
    int h = w;

    QPen pen(QColor(0, 0, 0, 0), 1, Qt::SolidLine, Qt::SquareCap,
         Qt::BevelJoin);
    QBrush brush(QColor(180, 180, 50, 20), Qt::SolidPattern);

    scene()->addRect(x-(w/2), y-(h/2), w, h, pen, brush);
}

//void View::mousePressEvent(QMouseEvent *e)
//{
//    QPointF pos = mapToScene(e->pos());
//    if (e->button() == Qt::LeftButton) {
//        drawCircleAtPos(pos.x(), pos.y());
//    }
//    QGraphicsView::mousePressEvent(e);
//}

//void View::mouseMoveEvent(QMouseEvent *e)
//{
//    QPointF pos = mapToScene(e->pos());
//    drawRectAtPos(pos.x(), pos.y());
//}
