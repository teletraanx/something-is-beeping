#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox> //5/17
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked); //5/17 Connects onButtonClicked() to the UI

    QGraphicsScene *scene = new QGraphicsScene(this); //5/19 also dragged a Graphics View into the UI
    ui->graphicsView->setScene(scene); //5/19

    //5/19v
    QFont font("Arial", 16);

    for (int i = 0; i < 5; ++i)
    {
        int x = i * 60;
        QGraphicsRectItem * rect = scene->addRect(x, 0, 50, 50, QPen(Qt::black), QBrush(Qt::lightGray));
        rects.append(rect);

        QGraphicsTextItem *label = scene->addText(QString::number(values[i]), font);
        label->setDefaultTextColor(Qt::black);

        QRectF rectBounds = rect->rect();
        QRectF textBounds = label->boundingRect();
        label->setPos(x + (rectBounds.width() - textBounds.width()) / 2,
                      (rectBounds.height() - textBounds.height()) /2);

        labels.append(label);
    }
    //5/19^
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::onButtonClicked() { //5/17 also dragged button into UI
    //QMessageBox::information(this, "Hello World!", "You clicked the button!"); //Opens a message box called "Hello World!" with the message "You..."

    //5/19
    if (sortIndex >= values.size()) {
        QMessageBox::information(this, "Done", "Insertion sort complete!");
        return;
    }

    int key = values[sortIndex];
    int j = sortIndex - 1;

    while (j >= 0 && values[j] > key) {
        values[j + 1] = values[j];
        j--;
    }
    values[j + 1] = key;

    // Update visuals
    for (int i = 0; i < values.size(); ++i) {
        labels[i]->setPlainText(QString::number(values[i]));

        QRectF textBounds = labels[i]->boundingRect();
        labels[i]->setPos(i * 60 + (50 - textBounds.width()) / 2,
                          (50 - textBounds.height()) / 2);
        rects[i]->setRect(i * 60, 0, 50, 50);
    }

    sortIndex++;
}
