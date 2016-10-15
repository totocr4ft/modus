#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->addItem("asdasd");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   m = new Modus_NR_module(1);
   connect(m,SIGNAL(on_log(MSG_TYPE,QString)),SLOT(on_log(MSG_TYPE,QString)));
}

void MainWindow::on_pushButton_2_clicked()
{
  m->check_update();
}

void MainWindow::on_log(MSG_TYPE t, QString msg){
 ui->listWidget->addItem(msg);
}
