#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tgt_page.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ok_pushButton_pressed()
{
    int num = ui->num_tgt_spinBox->value();
    tabwidget = new QTabWidget();
    if(num > 0)
     {
        for(int i=1; i<= num; i++)
        {
            t1 = new tgt_page();
//            tabwidget->addTab(t1, QString("Target %0").arg(tabwidget->count() + 1));
            tabwidget->addTab(t1, QString("Target %0").arg(i));
            ui->verticalLayout->addWidget(tabwidget, 0);
//            QVBoxLayout * size = new QVBoxLayout;
//            size->geometry();
//            tabwidget->show();
        }
     }

}

