#ifndef MO_QUERIES_H
#define MO_QUERIES_H
#include <mo_include.h>

Tresultset * auth_user(QString uname, QString pass);
Tresultset * get_module_data(int mid);
Tresultset * get_user_comps(QString userid);

#endif // MO_QUERIES_H
