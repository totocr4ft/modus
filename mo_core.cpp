#include <mo_core.h>
#include <mo_user.h>
#include <QDateTime>

Modus::Modus(){
  user = new Modus_user;
  connect(user,SIGNAL(on_log(MSG_TYPE,QString)),SLOT(on_log(MSG_TYPE, QString)));
}

Modus::~Modus(){
  delete user;
}

void Modus::on_log(MSG_TYPE tp , QString msg){
  qDebug() << QDateTime::currentDateTime().date().toString() << QDateTime::currentDateTime().time().toString()
           << " Type: "  <<  tp
           << "Sender: " << sender()->objectName()
           << " Message: " << msg;
}

