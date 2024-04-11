#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject{parent} {
    timer = new QTimer(this);
    time.setHMS(0,0,0,0);
    circle_time.setHMS(0,0,0,0);
    circle_counter = 1;
}

QString Stopwatch::get_time() {
    time = time.addMSecs(100);
    circle_time = circle_time.addMSecs(100);
    return time.toString("mm:ss:z");
}

QTimer* Stopwatch::get_timer() {
    return timer;
}

void Stopwatch::start() {
    timer->start(100);
}

void Stopwatch::stop() {
    timer->stop();
}

bool Stopwatch::timer_is_active() {
    if (timer->isActive()) {
        return true;
    }
    else { return false; }
}

void Stopwatch::clear() {
    time.setHMS(0,0,0,0);
    circle_time.setHMS(0,0,0,0);
    circle_counter = 1;
}

QString Stopwatch::new_circle() {
    QString result{"Circle: " + QString::number(circle_counter) + ", time: " + circle_time.toString("mm:ss:z")};
    circle_time.setHMS(0,0,0,0);
    circle_counter++;
    return result;
}
