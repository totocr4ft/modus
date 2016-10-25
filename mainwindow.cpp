#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->addItem("asdasd");
    m = new Modus;
    connect(m,SIGNAL(log(MSG_TYPE,QString)),this,SLOT(on_log(MSG_TYPE,QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_log(MSG_TYPE t, QString msg){
 if(t != SYS) ui->listWidget->addItem(msg);
}

void MainWindow::on_pushButton_3_clicked()
{
  m->user->login(ui->e_name->text(),ui->e_pass->text());
}

void MainWindow::on_pushButton_4_clicked()
{
  m->user->logout();
}
