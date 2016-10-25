#ifndef MO_USER_H
#define MO_USER_H
#include <mo_include.h>

struct MUserPerm{
  bool p_database = false;
  bool p_user = false;
  bool p_new_user = false;
  bool p_mod_user = false;
  bool p_settings = false;
  bool p_main_perms = false;
  bool p_module_perms = false;
  bool p_company = false;
  bool p_modules = false;
  bool mod_updates = false;
};

class Modus_user : public QObject{
    Q_OBJECT
private:
    MUserPerm perms;
    QString login_name = "";
    QString l_in = "";
    QString userid = "";
    bool l_state = false;
    QString full_n="";
    QString nick = "";
    QString last_er = "";
    void log(MSG_TYPE tp, QString msg);
    QVector<QStringList> cids;
public:
    Modus_user(){setObjectName("User management");}
    ~Modus_user(){}
    const QString fullname() {return full_n;}
    const QString nickname() {return nick;}
    bool is_logged_in() {return l_state;}
    const QString user_id() {return userid;}
    const QString last_error() {return last_er;}
    const QVector<QStringList> available_companies(){return cids;}
    bool login(QString name, QString pass);
    void ReFresh();
    void logout();
signals:
    void logged_out();
    void logged_in();
    void on_log(MSG_TYPE tp, QString msg);
};

#endif // MO_USER_H
