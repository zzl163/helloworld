#include <QAction>
#include<QMenuBar>
#include<QMessageBox>
#include<QStatusBar>
#include<QToolBar>
#include<QStatusBar>
#include<QDialog>
#include<QFileDialog>
#include<QtDebug>

#include"mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction=new QAction(QIcon(":/images/doc-open"),tr("&open..."),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("open an existing file"));

    saveAction=new QAction(QIcon(":/images/doc-save"),tr("&save..."),this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip("save a file");

    connect(openAction,&QAction::triggered,this,&MainWindow::openFile);
    connect(saveAction,&QAction::triggered,this,&MainWindow::saveFile);

    QMenu *file=menuBar()->addMenu(tr("& File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolbar =addToolBar(tr("& File"));
    toolbar->addAction(openAction);
    toolbar->addAction(saveAction);

    textEdit=new QTextEdit(this);
    setCentralWidget(textEdit);
    statusBar();

    //this->setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//隐藏最大化窗口按钮
    //setFixedSize(this->width(),this->height());//不可手动调整窗口大小
}
MainWindow::~MainWindow()
{

}

/*
void MainWindow::open()
{
    if(QMessageBox::Yes == QMessageBox::question(this,
                                                 tr("Question"),
                                                 tr("Are you ok?"),
                                                 QMessageBox::Yes|QMessageBox::No,
                                                 QMessageBox::Yes))
    {
        QMessageBox::information(this,tr("Hmmmm..."),tr("I'm glad to hear that!"));
        qDebug()<<"I'm glad to hear that!";
    }
    else{
        QMessageBox::information(this,tr("Hmmmm..."),tr("I'm sorry!"));
        qDebug()<<"I'm sorry!";
    }
    //qDebug函数生效要保证头文件包含qtdebug，同时pro文件最后加上CONFIG += console

    QDialog dialog(this);//this指针锁定当前对话框的父节点
    dialog.setWindowTitle(tr("Hello dialog!"));
    dialog.exec();
    qDebug()<<dialog.result();

}*/

void MainWindow::openFile()
{
    QString path=QFileDialog::getOpenFileName(this,
                                              tr("open file"),
                                              ".",
                                              tr("text file(*.txt)"));
    if(!path.isEmpty())
    {
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            QMessageBox::warning(this,tr("read file"),
                                 tr("cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }
    else {
        QMessageBox::warning(this,tr("path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::saveFile()
{
    QString path=QFileDialog::getSaveFileName(this,
                                              tr("open file"),
                                              ".",
                                              tr("text files(*.txt)"));
    if(!path.isEmpty()){
        QFile file(path);
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QMessageBox::warning(this,tr("write file"),
                                 tr("cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out<<textEdit->toPlainText();
        file.close();
        QMessageBox::information(this,tr("sucess..."),tr("file saved sucessfully!"));
    }else{
        QMessageBox::warning(this,tr("path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::messageboxtest()
{
    QMessageBox msgBOX;
    msgBOX.setText(QObject::tr("the document has been modified."));
    msgBOX.setInformativeText(QObject::tr("Do you want to save your changes?"));
    msgBOX.setDetailedText(QObject::tr("Differences here..."));
    msgBOX.setStandardButtons(QMessageBox::Save|
                              QMessageBox::Discard
                              |QMessageBox::Cancel);
    msgBOX.setDefaultButton(QMessageBox::Save);
    int ret =msgBOX.exec();
    switch (ret) {
    case QMessageBox::Save:
        qDebug()<<"save document!";
        break;
    case QMessageBox::Discard:
        qDebug()<<"discard document!";
        break;
    case QMessageBox::Cancel:
        qDebug()<<"close document!";
        break;
    }
}
