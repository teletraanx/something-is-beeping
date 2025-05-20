#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "animatedrectitem.h"
#include <QPropertyAnimation>
#include <QMessageBox> //5/17
#include <QGraphicsScene>
#include <QFont>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked); //5/17 Connects onButtonClicked() to the UI

    //----------for drawing 5 rectangles and numbering them--------------
    QGraphicsScene *scene = new QGraphicsScene(this); //5/19 also dragged a Graphics View into the UI
    ui->graphicsView->setScene(scene); //5/19

    //5/19v
    QFont font("Arial", 16);

    for (int i = 0; i < 5; ++i)
    {
        int x = i * 60;

        // Create our custom animated rect item
        AnimatedRectItem *item = new AnimatedRectItem(QRectF(0, 0, 50, 50));
        item->setPos(x, 0);

        item->setBrush(Qt::lightGray);
        item->setPen(QPen(Qt::black));

        // Set the label
        item->label->setPlainText(QString::number(values[i]));
        item->label->setDefaultTextColor(Qt::black);
        item->label->setFont(font);

        QRectF textBounds = item->label->boundingRect();
        item->label->setPos((50 - textBounds.width()) / 2,
                            (50 - textBounds.height()) / 2);

        scene->addItem(item);
        items.append(item);
    }
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::onButtonClicked() { //5/17 also dragged button into UI
    //QMessageBox::information(this, "Hello World!", "You clicked the button!"); //Opens a message box called "Hello World!" with the message "You..."

    //5/19--------Insertion Sort-----------
    if (sortIndex >= values.size()) {
        QMessageBox::information(this, "Done", "Insertion sort complete!");
        return;
    }

    int key = values[sortIndex];
    int j = sortIndex - 1;

    //clear previous highlights
    if (highlightedItem) highlightedItem->setBrush(Qt::lightGray);
    if (comparedItem) comparedItem->setBrush(Qt::lightGray);

    //highlight current key
    highlightedItem = items[sortIndex];
    highlightedItem->setBrush(Qt::green); //key being inserted

    //highlight comparison (if in bounds)
    if (j >= 0) {
        comparedItem = items[j];
        comparedItem->setBrush(Qt::yellow); //being compared
    }

    while (j >= 0 && values[j] > key) { //perform the sort step (full insertion step per click)
        values[j + 1] = values[j];
        j--;
    }
    values[j + 1] = key;

    // Update visuals
    for (int i = 0; i < values.size(); ++i) {
        AnimatedRectItem *item = items[i];
        item->label->setPlainText(QString::number(values[i]));

        QRectF textBounds = item->label->boundingRect();
        item->label->setPos((50 - textBounds.width()) / 2,
                            (50 - textBounds.height()) / 2);

        QPointF newPos(i * 60, 0);
        QPropertyAnimation *animation = new QPropertyAnimation(item, QByteArray("pos"));
        animation->setDuration(300);
        animation->setEndValue(newPos);
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
    sortIndex++;
}

