#include "widget.h"
#include <QApplication>
#include<QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    //QLabel label("hello world!");
    //label.show();
    //insert one line to test git!
    //test branch dev.
    return a.exec();
}
