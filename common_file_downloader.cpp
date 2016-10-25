#include <common_file_downloader.h>

Url_downloader::Url_downloader(){
data = new QByteArray;
ht = new QNetworkAccessManager(this);
connect(ht,SIGNAL(finished(QNetworkReply*)),SLOT(save_data(QNetworkReply*)));
}

Url_downloader::Url_downloader(QString url){
data = new QByteArray;
ht = new QNetworkAccessManager(this);
connect(ht,SIGNAL(finished(QNetworkReply*)),SLOT(save_data(QNetworkReply*)));
if(url!=""){
Url = url;
download();
 }
}

Url_downloader::Url_downloader(QString url,QString target_file){
data = new QByteArray;
ht = new QNetworkAccessManager(this);
connect(ht,SIGNAL(finished(QNetworkReply*)),SLOT(save_data(QNetworkReply*)));
if(url!=""){
Url = url;
filename = target_file;
download();
 }
}

//******************************************************************************

bool Url_downloader::download(){
    if(Url == ""){
        log(ER,"No url specified");
        return false;
    }
    data->clear();
    log(SYS,"Downloading url : " + Url );
    QNetworkReply * reply = ht->get(QNetworkRequest(QUrl(Url)));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),SLOT(progress(qint64,qint64)));
return true;
}

void Url_downloader::save_data(QNetworkReply * _reply){
 if(_reply->error() == 0)
  {
   log(SYS,"Downloading finished");
   *data = _reply->readAll();
   log(SYS, QString::number( data->length()) + " Bytes received ");
   if(filename != "")
     {
      log(SYS,"Writing data to file: " + filename);
      QFile file(filename);
      file.open(QIODevice::WriteOnly);
      file.write(*data);
      file.close();
     }
    emit download_ready(data);
  }else
     {
      log(SYS,"Download error");
      emit download_error(_reply->error());
     }


_reply->deleteLater();

}

void Url_downloader::log(MSG_TYPE l, QString t){
emit on_log(l,t);
qDebug() << t;
}

void Url_downloader::progress(qint64 a, qint64 b){
qDebug() << a << " -> " <<b;
}
