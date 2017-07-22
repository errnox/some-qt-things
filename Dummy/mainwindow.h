#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_dialogButton_clicked();

    void on_toggleCalendarBtn_clicked();

    void on_pushBtn_clicked();

    void on_colorsComboBox_currentIndexChanged(const QString &arg1);

    void on_completionComboBox_editTextChanged(const QString &arg1);

    void on_selectVehicleBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
