#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slot_timer_alarm();

    void on_pb_start_stop_clicked();

    void on_pb_clear_clicked();

    void on_pb_circle_clicked();

private:
    Ui::MainWindow *ui;
    Stopwatch* sw;
};
#endif // MAINWINDOW_H
