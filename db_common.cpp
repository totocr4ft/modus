#include <db_common.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtDebug>
#include <QStringList>

TdataBase::TdataBase(QString u_name, QString pass, QString database, QString host){

  qDebug() << "Connecting Database " << database << "Host: " << host;
  Connection = QSqlDatabase::addDatabase("QMYSQL");
  Connection.setUserName(u_name);
  Connection.setPassword(pass);
  Connection.setDatabaseName(database);
  Connection.setHostName(host);
  if(!Connection.open()){
      qDebug() << " ERROR: " << Connection.lastError().text();
  }
  else
     { qDebug() << " Success! "; }

};

Tresultset * TdataBase::run_query(QString qstr, Tparams params){
int i,y=0;

    QSqlQuery q;
    q.prepare(qstr);
    if(params.length() > 0){
      for(i=0;i<=params.length()-1;){
          q.bindValue(i, params.at(i));
          i++;
      }
    }
    q.exec();
    if(!q.isActive()){
       return 0;
    }
    Tresultset * Res = new Tresultset ;
    Tresult Temp;
    while(q.next()){
        for(i=0;i<q.record().count(); i++){
          Temp.insert(q.record().fieldName(i), q.value(i).toString());
        }
        Res->append(Temp);
        y++;
    }
    return Res;
};

Tresultset * TdataBase::run_query(QString qstr){
int i,y=0;

    QSqlQuery q;
    q.prepare(qstr);
    q.exec();
    if(!q.isActive()){
       return 0;
    }
    Tresultset * Res = new Tresultset ;
    Tresult Temp;
    while(q.next()){
        for(i=0;i<q.record().count(); i++){
          Temp.insert(q.record().fieldName(i), q.value(i).toString());
        }
        Res->append(Temp);
        y++;
    }
    return Res;
};

