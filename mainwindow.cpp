#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox> //5/17

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked); //5/17 Connects onButtonClicked() to the UI

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked() { //5/17 also dragged button into UI
    QMessageBox::information(this, "Hello World!", "You clicked the button!"); //Opens a message box called "Hello World!" with the message "You..."
}
