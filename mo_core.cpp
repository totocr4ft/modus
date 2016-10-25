#include <mo_core.h>
#include <mo_user.h>
#include <QDateTime>

Modus::Modus(){
//-----------  USER  ------------------------>>
  user = new Modus_user;
  connect(user,SIGNAL(on_log(MSG_TYPE,QString)),SLOT(on_log(MSG_TYPE, QString)));

//-----------  AVAILABLE MODULES ------------>>
  avail = new QMap<QString, Modus_NR_module>;
}

Modus::~Modus(){
  delete user;
  delete avail;
}

void Modus::on_log(MSG_TYPE tp , QString msg){
  qDebug() << QDateTime::currentDateTime().date().toString() << QDateTime::currentDateTime().time().toString()
           << " Type: "  <<  tp
           << " Sender: " << sender()->objectName()
           << " Message: " << msg;
  emit log(tp,msg);
}

