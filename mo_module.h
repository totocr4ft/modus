#ifndef MO_MODULE_H
#define MO_MODULE_H
#include <mo_include.h>
#include <common_file_downloader.h>

class Modus_module: public QObject{
    Q_OBJECT
   protected:
    QString f_path;
    QString exe_n;
    QString u_name;
    QString mod_name;
    QString modid;
    QString current_ver;
    QString new_ver;
    QString tab;
    QString last_er;
    bool valid;
    void log(MSG_TYPE t, QString msg);
  public:
    const QString full_path() {return f_path;}
    const QString executable_name() {return exe_n;}
    const QString unique_name() {return u_name;}
    const QString module_name() {return mod_name;}
    const QString module_id() {return modid;}
    virtual QString current_version()=0;
    virtual QString new_version()=0;
    const QString place() {return tab;}
    const QString last_error() {return last_er;}
    const bool is_valid() {return valid;}
  signals:
    void on_log(MSG_TYPE t, QString msg);
};

class Modus_NR_module : public Modus_module{
      Q_OBJECT
public:
    Modus_NR_module(int mid=0);
    ~Modus_NR_module(){}
    QString current_version(){}
    QString new_version(){}
    QString update_server = "http://modus.ddns.net";
   void check_update();
private:
    Url_downloader * downloader;
    void do_update();
    bool runnable;
    bool auto_upd=false;
signals:
    void new_version_found();
    void update_started();
    void update_finished();
    void update_error();
    void updateReady();
private slots:
    void chk_ready(QByteArray * reply);
};

class Modus_R_module : public Modus_module{
      Q_OBJECT
private:
    void check_update(){}
    void do_update(){}
    QString current_version(){}
    QString new_version(){}
    QString runid;
    QDateTime started;
    QProcess * proc;
public:
    Modus_R_module(Modus_NR_module * modul);
    ~Modus_R_module(){}
signals:
    void stopped();
    void starting();
};


#endif // MO_MODULE_H
