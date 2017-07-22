#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    a.setStyleSheet("\
#dialogButton {\
  color: rgba(10, 64, 255, 200);\
}\
\
*[errorState=\"true\"] {\
  color: rgba(255, 0, 0, 255);\
}\
");

    return a.exec();
}
