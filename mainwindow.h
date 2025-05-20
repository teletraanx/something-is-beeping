#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include "animatedrectitem.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onButtonClicked(); //5/17
    //void animateRectMove(QGraphicsItem* item, QPointF newPos);

private:
    Ui::MainWindow *ui;
    QVector<int> values = {5, 2, 8, 1, 4}; //for insertion sort and labeling rectangles
     QVector<AnimatedRectItem*> items;
    int sortIndex = 1; //Start from 1 like in insertion sort

    AnimatedRectItem *highlightedItem = nullptr;
    AnimatedRectItem *comparedItem = nullptr;


};
#endif // MAINWINDOW_H
