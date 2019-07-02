#ifndef CONNECT_BASE_H
#define CONNECT_BASE_H

#include <QObject>

class Connect_Base : public QObject
{
    Q_OBJECT

public:
   explicit Connect_Base(QObject *parent = 0);
    Q_INVOKABLE
    void execqueru();

};

#endif // CONNECT_BASE_H
