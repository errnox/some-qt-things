#include <QString>
#include <QMessageBox>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->horizontalSlider->setValue(0);

    ui->lineEdit->setText(QString("Hello there!"));

    ui->calendarWidget->setVisible(false);

    ui->colorsComboBox->addItem("red");
    ui->colorsComboBox->addItem("green");
    ui->colorsComboBox->addItem("blue");
    ui->colorsComboBox->addItem("yellow");
    ui->colorsComboBox->addItem("magenta");
    ui->colorsComboBox->addItem("cyan");

    ui->colorLabel->setText(ui->colorsComboBox->currentText());

    ui->completionComboBox->setEditable(true);
    ui->completionComboBox->addItem("apple");
    ui->completionComboBox->addItem("banana");
    ui->completionComboBox->addItem("orange");
    ui->completionComboBox->addItem("pear");
    ui->completionComboBox->addItem("peach");
    ui->completionComboBox->addItem("strawberry");
    ui->completionComboBox->addItem("grape");

    ui->selectedVehicleLabel->setText(
                "<i>No vehicle has been selected yet.</i>");

    ui->selectVehicleBtn->setStyleSheet(
                "* {\
  background-color: #7CBBFF;\
  color: #FFFFFF;\
  border-radius: 0;\
  border: 1px solid rgba(0, 0, 0, 0.2);\
}\
\
*:hover {\
  background-color: #FFFFFF;\
  color: #FF0000;\
}\
\
*:hover:pressed {\
  background-color: #AEAEAE;\
  color: #FFFFFF;\
}\
");

  ui->dialogButton->setObjectName("dialogButton");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushBtn_clicked()
{
    ui->lineEdit->setText("The button has been clicked.");
}

void MainWindow::on_dialogButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Hello there!");
    msgBox.exec();
}

void MainWindow::on_toggleCalendarBtn_clicked()
{
    if (ui->calendarWidget->isVisible()) {
        ui->calendarWidget->setVisible(false);
        ui->toggleCalendarBtn->setText("Show Calenda&r");
    } else {
        ui->calendarWidget->setVisible(true);
        ui->toggleCalendarBtn->setText("Hide Calenda&r");
    }
}

void MainWindow::on_colorsComboBox_currentIndexChanged(
        const QString &color)
{
    ui->colorLabel->setText(color);
}

void MainWindow::on_completionComboBox_editTextChanged(
        const QString &text)
{
    if (text.isEmpty()) {
        ui->completionLabel->setText("<i>The input is empty.</i>");
    } else {
        ui->completionLabel->setText(text);
    }
}

void MainWindow::on_selectVehicleBtn_clicked()
{
    QStringList vehicles;
    vehicles << "car" << "truck" << "train" << "bicycle";

    QString selectedVehicle = QInputDialog::getItem(
                this, "Vehicle Selection", "Select a vehicle", vehicles);
    if (selectedVehicle.isEmpty()) {
        ui->selectedVehicleLabel->setText(
                    "<i>No vehicle has been selected yet.</i>");

        ui->selectedVehicleLabel->setProperty("errorState", true);
        ui->selectedVehicleLabel->style()->unpolish(
                    ui->selectedVehicleLabel);
        ui->selectedVehicleLabel->style()->polish(
                    ui->selectedVehicleLabel);
    } else {
        ui->selectedVehicleLabel->setText("<b>" + selectedVehicle
                                          + "</b>");

        ui->selectedVehicleLabel->setProperty("errorState", false);
        ui->selectedVehicleLabel->style()->unpolish(
                    ui->selectedVehicleLabel);
        ui->selectedVehicleLabel->style()->polish(
                    ui->selectedVehicleLabel);
    }
}
