#include "mainwindow.h"
#include <QApplication>
#include <mo_core.h>
#include <mo_user.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Modus * motest = new Modus;
    motest->user->login("toto","t");
    motest->user->logout();


    return a.exec();
}
