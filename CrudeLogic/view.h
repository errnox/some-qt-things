#ifndef VIEW_H
#define VIEW_H

#include "graphics.h"

#include <QGraphicsView>
#include <QMouseEvent>

class View: public QGraphicsView
{
public:
    View();
    void draw();
    void drawCircleAtPos(int x, int y);
    void drawRectAtPos(int x, int y);
//    void mousePressEvent(QMouseEvent *event);
//    virtual void mouseMoveEvent(QMouseEvent *event);
};

#endif // VIEW_H
