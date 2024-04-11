#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pb_circle->setEnabled(false);
    ui->tl_time->setText("00:00:0");

    sw = new Stopwatch(this);
    connect(sw->get_timer(), &QTimer::timeout, this, &MainWindow::slot_timer_alarm);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_timer_alarm() {
    ui->tl_time->setText(sw->get_time());
}



void MainWindow::on_pb_start_stop_clicked()
{
    if (sw->timer_is_active()) {
        sw->stop();
        ui->pb_start_stop->setText("Start");
        ui->pb_circle->setEnabled(false);
    }
    else {
        sw->start();
        ui->pb_start_stop->setText("Stop");
        ui->pb_circle->setEnabled(true);
    }
}


void MainWindow::on_pb_clear_clicked()
{
    sw->clear();
    ui->tl_time->setText("00:00:0");
    ui->tb_circles->clear();
}


void MainWindow::on_pb_circle_clicked()
{
    ui->tb_circles->append(sw->new_circle());
}




















