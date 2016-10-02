#include <mo_queries.h>

Tresultset * auth_user(QString uname, QString pass){
TdataBase db;
Tparams p;
p.append(uname);
p.append(pass);
return db.run_query(" select * from users where user_name = :uname and pass = md5(:pass) " , p );
}
