#ifndef MO_CORE_H
#define MO_CORE_H
#include <QObject>
#include <mo_include.h>
#include <mo_user.h>
#include <mo_module.h>

class Modus : public QObject{
    Q_OBJECT
 private:
    QMap<QString,Modus_NR_module> * avail;
    QMap<QString,Modus_R_module> * running;
 public:
   Modus_user * user;
   Modus();
   ~Modus();
 signals:
  void log(MSG_TYPE tp, QString msg);
 private slots:
  void on_log(MSG_TYPE tp, QString msg);
};



#endif // MO_CORE_H
