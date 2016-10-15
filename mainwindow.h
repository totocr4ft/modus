#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mo_core.h>
#include <mo_module.h>
#include <common_helper.h>
#include <mo_module.h>
#include <common_file_downloader.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Modus_NR_module * m;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_log(MSG_TYPE t, QString msg);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
