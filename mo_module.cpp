#include <mo_module.h>
#include <mo_queries.h>
#include <db_common.h>
#include <mo_include.h>
#include <common_file_downloader.h>
#include <common_helper.h>



//-------------------LOG----------------->>
void Modus_module::log(MSG_TYPE t, QString msg){
qDebug() << objectName() << " " << msg;
emit on_log(t,msg);
}
//--------------------------------------->>

Modus_NR_module::~Modus_NR_module(){
  delete downloader;
}

Modus_NR_module::Modus_NR_module(int mid){
 if(mid!=0){
 Tresultset * res = get_module_data(mid);
 if(res->length() > 0)
  {
   QString appath = QCoreApplication::applicationDirPath();
   downloader = new Url_downloader();
   connect(downloader,SIGNAL(download_ready(QByteArray*)),this,SLOT(chk_ready(QByteArray*)));
   connect(downloader,SIGNAL(on_log(MSG_TYPE,QString)),this,SIGNAL(on_log(MSG_TYPE,QString)));
   connect(downloader,SIGNAL(download_error(qint8)),this,SLOT(upd_er(qint8)));
   modid = res->at(0).value("module_id");
   mod_name = res->at(0).value("module_name");
   exe_n = res->at(0).value("path");
   tab = res->at(0).value("tab");
   u_name = res->at(0).value("unique");
   setObjectName(mod_name);
//Check dir, file , etc...
   QDir d;
   if(! d.exists(appath+"/MODULES")){
       d.mkdir(appath+"/MODULES");
    }
   if(! d.exists(appath+"/MODULES/"+modid)){
       d.mkdir(appath+"/MODULES/"+modid);
    }
  QString fullpath = appath+"/MODULES/"+modid+"/"+exe_n;
  f_path = fullpath;
  QFile f;
   if(!f.exists(fullpath)){
    auto_update();
   }else
       {
       check_update();
       }
   valid = true;
  }
 delete res;
 }
}


//------------------------------------------------------------------------>>
//                               MODUL UPDATER
//------------------------------------------------------------------------>>

void Modus_NR_module::upd_er(qint8 er){
  upd_error = er;
  log(LOG,"["+mod_name+"]Auto update failed, error code:" + QString::number(er) );
  emit update_error();
}

void Modus_NR_module::auto_update(){
    log(LOG,"["+mod_name+"]Auto update started" );
    auto_upd = true;
    check_update();
}

void Modus_NR_module::do_update(){
   if(new_ver != "")
    {
      emit update_started();
      log(LOG, "["+mod_name+"]Updating....");
      downloader->Url = update_server+"/MODULES/"+unique_name()+"/"+new_ver+"/"+exe_n;
      downloader->filename = f_path;
      downloader->download();
      auto_upd = false;
    }
}

void Modus_NR_module::check_update(){
    current_ver = getVersionString(f_path);
    qDebug() << current_ver;
    downloader->Url = update_server+"/MODULES/"+unique_name()+"/ver.php";
    downloader->download();
}

void Modus_NR_module::chk_ready(QByteArray *reply){

if(reply->length() < 10){
   new_ver = *downloader->get_file_data();
   if(new_ver != current_ver ) {
       emit new_version_found();
       log(LOG,"["+mod_name+"]New version found: " +new_ver +" old version: " + current_ver);
   }
   if(auto_upd){ do_update(); }
  }else{
       if(downloader->filename != ""){
        emit update_finished();
        log(LOG,"["+mod_name+"]Update success to version: " +new_ver);
        downloader->filename = "";
       }
      }
upd_error = 0;
}














































