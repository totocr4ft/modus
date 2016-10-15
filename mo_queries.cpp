#include <mo_queries.h>

Tresultset * auth_user(QString uname, QString pass){
TdataBase db;
Tparams p;
p.append(uname);
p.append(pass);
return db.run_query(" select * from users where user_name = :uname and pass = md5(:pass) " , p );
}

Tresultset * get_module_data(int mid){
TdataBase db;
Tparams p;
p.append(QString::number(mid));
return db.run_query(" select * from modules where module_id=:mid " , p );
}

Tresultset * get_user_comps(QString userid){
TdataBase db;
Tparams p;
p.append(userid);
return db.run_query(" select * from user_company u "
                    " left join company c on c.cid = u.cid where uid=:uid " , p );
}

Tresultset * get_user_modules(QString usr_id, QString cid){
TdataBase db;
Tparams p;
p.append(usr_id);
p.append(cid);
return db.run_query(" select * from modules as m where m.tp = 1 and m.module_id in "
                    " ( select distinct(module_id) from module_perm as p where id in "
                    " ( select perm_id from user_perm where user_id = :id and cid = :cid  ) )  " , p );
}
