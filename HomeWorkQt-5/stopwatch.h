#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QTimer>
#include <QTime>

class Stopwatch : QObject
{
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);

    QString get_time();
    QTimer* get_timer();
    void start();
    void stop();
    bool timer_is_active();
    void clear();
    QString new_circle();
private:
    QTimer* timer;
    QTime time;
    QTime circle_time;
    int circle_counter;
};

#endif // STOPWATCH_H
