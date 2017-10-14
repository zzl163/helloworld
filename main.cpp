#include "widget.h"
#include <QApplication>
#include<QLabel>
#include"newspaper.h"
#include"reader.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Newspaper newspaper("Newspaper A");
    Reader reader;
    QObject::connect(&newspaper,&Newspaper::newpaper,
                     &reader,&Reader::receivenewspaper);
    newspaper.send();
    Widget w;
    w.show();
    //QLabel label("hello world!");
    //label.show();
    //insert one line to test git!
    //test branch dev.
    return app.exec();
}
