#include "widget.h"
#include <QApplication>
#include<QLabel>
#include<QSpinBox>
#include<QSlider>
#include<QHBoxLayout>
#include"newspaper.h"
#include"reader.h"
#include"mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
/*自定义信号与槽功能代码*************************************************
    Newspaper newspaper("Newspaper A");
    Reader reader;
    QObject::connect(&newspaper,&Newspaper::newpaper,
                     &reader,&Reader::receivenewspaper);
    newspaper.send();
自定义信号与槽功能代码***************************************************/

/*测试自动layout功能部分代码*********************************************
    QWidget window;
    window.setWindowTitle("Enter your age");
    QSpinBox *spinBox=new QSpinBox(&window);
    QSlider *slider=new QSlider(Qt::Horizontal,&window);
    spinBox->setRange(0,130);
    slider->setRange(0,130);

    QObject::connect(slider,&QSlider::valueChanged,spinBox,&QSpinBox::setValue);
    void(QSpinBox::*spinBoxSignal)(int)=&QSpinBox::valueChanged;
    //QSpinBox的valudechanged函数有多个重载，直接引用无法找到函数入口，因此有上述显式定义spinBoxSignal为函数指针
    QObject::connect(spinBox,spinBoxSignal,slider,&QSlider::setValue);
    spinBox->setValue(50);

    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    window.setLayout(layout);
    window.show();
测试自动layout功能部分代码**********************************************/

    MainWindow win;
    win.show();
    return app.exec();
}
