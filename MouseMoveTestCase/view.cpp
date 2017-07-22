#include "view.h"

#include <QDebug>
#include <QGraphicsView>
#include <QMouseEvent>

View::View()
{

}

void View::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "Mouse press: " << e->globalPos();
}

void View::mouseMoveEvent(QMouseEvent *e)
{
    qDebug() << "Mouse move: " << e->globalPos();
}
