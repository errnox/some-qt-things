#include "mainwindow.h"
#include "view.h"

#include <QApplication>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QGraphicsScene scene;
    scene.addText("This is a test.");

    View view;
    view.setScene(&scene);
    view.show();

    w.setCentralWidget(&view);

    return a.exec();
}
