#ifndef MO_CORE_H
#define MO_CORE_H
#include <QObject>
#include <mo_include.h>
#include <mo_user.h>

class Modus : public QObject{
    Q_OBJECT
 private:
 public:
   Modus_user * user;
   Modus();
   ~Modus();
 private slots:
  void on_log(MSG_TYPE tp, QString msg);
};



#endif // MO_CORE_H
