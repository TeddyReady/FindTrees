#include "timekeeper.h"

TimeKeeper* TimeKeeper::instance = nullptr;

TimeKeeper::TimeKeeper()
    : time(0)
{}

TimeKeeper::~TimeKeeper() {}

TimeKeeper* TimeKeeper::getInstance()
{
    if (not instance)
        instance = new TimeKeeper;

    return instance;
}

void TimeKeeper::start()
{
    time = 0;
    ext = "";
    timer.restart();
}

QString TimeKeeper::finish()
{
    time = timer.elapsed();
    ext = (time < 1000) ? "ms" : "sec";
    time = (time < 1000) ? time : static_cast<double>(time / 1000);

    return QString("%1 %2").arg(time).arg(ext);
}
