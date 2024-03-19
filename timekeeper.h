#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H
#include <QElapsedTimer>
#include <QString>

class TimeKeeper {
public:
    static TimeKeeper *instance;
    static TimeKeeper* getInstance();
    ~TimeKeeper();
    TimeKeeper(const TimeKeeper &other) = delete;
    TimeKeeper operator=(const TimeKeeper &other) = delete;

    void start();
    QString finish();

private:
    explicit TimeKeeper();

    double time;
    const char* ext;
    QElapsedTimer timer;
};

#endif // TIMEKEEPER_H
