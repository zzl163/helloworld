#include <QAction>
#include<QMenuBar>
#include<QMessageBox>
#include<QStatusBar>
#include<QToolBar>
#include<QStatusBar>
#include<QDialog>
#include<QDebug>

#include"mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction=new QAction(QIcon(":/images/doc-test"),tr("&open..."),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("open an existing file"));
    connect(openAction,&QAction::triggered,this,&MainWindow::open);

    QMenu *file=menuBar()->addMenu(tr("& File"));
    file->addAction(openAction);

    QToolBar *toolbar =addToolBar(tr("& File"));
    toolbar->addAction(openAction);

    statusBar();

    this->setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//隐藏最大化窗口按钮
    setFixedSize(this->width(),this->height());//不可手动调整窗口大小

}
MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    //QMessageBox::information(this,tr("Information"),tr("open"));
    QDialog dialog(this);//this指针锁定当前对话框的父节点
    dialog.setWindowTitle(tr("Hello dialog!"));
    dialog.exec();
    qDebug()<<dialog.result();
}
