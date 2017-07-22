#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGraphicsScene>
#include <QGraphicsView>

class Graphics
{
private:
    QGraphicsScene *m_scene;
    QGraphicsView *m_view;
public:
    Graphics(QGraphicsScene &scene, QGraphicsView &view);
    void draw();
    void drawRectAtPos(int x, int y);
};

#endif // GRAPHICS_H
