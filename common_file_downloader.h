#ifndef COMMON_FILE_DOWNLOADER_H
#define COMMON_FILE_DOWNLOADER_H
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDir>
#include <mo_include.h>

class Url_downloader: public QObject{
        Q_OBJECT
   private:
    QByteArray *data;
    QNetworkAccessManager * ht;
    void log(MSG_TYPE l, QString t );
   public:
    Url_downloader();
    Url_downloader(QString url);
    Url_downloader(QString url,QString target_file);
    ~Url_downloader(){delete data; delete ht;}
    QString Url;
    QString filename;
    QByteArray * get_file_data(){return data;}
    bool download();
    bool save_to_file(QString fname);
   signals:
    void download_ready(QByteArray * data);
    void download_error(qint8 er);
    void download_started();
    void on_log(MSG_TYPE l, QString t );
   private slots:
    void save_data(QNetworkReply * _reply);
    void progress(qint64 a, qint64 b);
};

#endif // COMMON_FILE_DOWNLOADER_H
