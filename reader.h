#ifndef READER_H
#define READER_H
#include<QObject>
#include<QDebug>

class Reader:public QObject
{
    Q_OBJECT
public:
    Reader(){}

    void receivenewspaper(const QString & name)
    {
        qDebug()<<"receives newspaper:"<<name;
    }
};


#endif // READER_H

