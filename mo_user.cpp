#include <mo_user.h>
#include <mo_queries.h>

bool Modus_user::login(QString name, QString pass){
    if(l_state == true){
     return false;
     log(ER, "User already logged in");
    };

    Tresultset * res = auth_user(name,pass);
    if(res->length() > 0){
     full_n = res->at(0).value("fullname");
     nick = name;
     userid = res->at(0).value("ID");
     l_state = true;
     emit logged_in();
     log(LOG, "User: "+fullname()+" logged in!");
     return true;
    }else{
     return false;
     log(ER, "Authentication error");
    };

delete res;
}

void Modus_user::logout(){
    if(l_state == false){
     log(ER, "User already logged out");
    }else{
    full_n = "";
    nick   = "";
    userid = "";
    l_state = false;
    emit logged_out();
    emit log(LOG, "User logged out"); };
}

void Modus_user::log(MSG_TYPE tp, QString msg) {
    if(tp == ER){ last_er = msg;}
    emit on_log(tp,msg);
}




