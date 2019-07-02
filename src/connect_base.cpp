#include "connect_base.h"
#include <QSqlDatabase>
#include <QSqlQuery>

Connect_Base::Connect_Base(QObject *parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("192.168.254.147");
    db.setPort(5432);
    db.setDatabaseName("Gpsbase");
    db.setUserName("postgres");
    db.setPassword("");
    db.open();
    //if

}

void Connect_Base::execqueru()
{
    QSqlQuery test;
        test.exec("insert into locations (longitudem, latitude, livetime ) values ('80','100', '2003-04-12 04:05:06');");
//    return true;
}
