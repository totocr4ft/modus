#include "mainwindow.h"
#include <QApplication>
#include <mo_core.h>
#include <mo_module.h>
#include <common_helper.h>
#include <mo_module.h>
#include <common_file_downloader.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationVersion("1000");
    MainWindow w;
    w.show();
   /* Modus * m = new Modus;
    m->user->login("toto","t");
    qDebug() << m->user->available_companies();
    */
  /*  Url_downloader d("http://modus.ddns.net/MODULES/m_jelentkezes/1005/jelentkezes.exe","D:/jelentkezes.exe");
    d.filename = "D:/jelentkezes1.exe";
    d.download();*/

    return a.exec();
}
