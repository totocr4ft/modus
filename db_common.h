#ifndef DB_COMMON_H
#define DB_COMMON_H
#include <mo_include.h>

typedef QVector<QMap<QString, QString>> Tresultset;
typedef QMap<QString, QString> Tresult;
typedef QVector<QString> Tparams;

class TdataBase{
public:
   QSqlDatabase Connection;
   TdataBase( QString u_name = "admin", QString pass="theforce1", QString database = "modus", QString host = "192.168.0.43");
   ~TdataBase(){ Connection.close(); }
   Tresultset * run_query(QString qstr, Tparams params);
   Tresultset * run_query(QString qstr);
};

#endif // DB_COMMON_H
