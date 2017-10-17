#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent=0 );
    ~MainWindow();
private:
    void openFile();
    void saveFile();
    void messageboxtest();
    QAction *openAction;
    QAction *saveAction;
    QTextEdit *textEdit;
};
#endif // MAINWINDOW_H
