#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>

class View: public QGraphicsView
{
public:
    View();
    void mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
};

#endif // VIEW_H
