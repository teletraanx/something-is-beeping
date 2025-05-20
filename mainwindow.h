#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

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

private:
    Ui::MainWindow *ui;
    //5/19
    QVector<QGraphicsRectItem*> rects;
    QVector<QGraphicsTextItem*> labels;
    QVector<int> values = {5, 2, 8, 1, 4};
    int sortIndex = 1; //Start from 1 like in insertion sort
};
#endif // MAINWINDOW_H
