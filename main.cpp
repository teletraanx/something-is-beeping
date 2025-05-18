#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();

    /*
    QPushButton button("Click me!");
    button.show();
    return app.exec();
*/
}
