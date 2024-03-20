#include "timekeeper.h"

/**
 * @brief TimeKeeper::instance
 */
TimeKeeper* TimeKeeper::instance = nullptr;

/**
 * @brief TimeKeeper::TimeKeeper
 */
TimeKeeper::TimeKeeper()
    : time(0)
{}

/**
 * @brief TimeKeeper::~TimeKeeper
 */
TimeKeeper::~TimeKeeper() {}

/**
 * @brief TimeKeeper::getInstance
 * @return TimeKeeper pointer
 */
TimeKeeper* TimeKeeper::getInstance()
{
    if (not instance)
        instance = new TimeKeeper;

    return instance;
}

/**
 * @brief TimeKeeper::start
 *
 * Start time monitoring
 */
void TimeKeeper::start()
{
    time = 0;
    ext = "";
    timer.restart();
}

/**
 * @brief TimeKeeper::finish
 * @return time string with ms or sec
 *
 * Finish time monitoring
 */
QString TimeKeeper::finish()
{
    time = timer.elapsed();
    ext = (time < 1000) ? "ms" : "sec";
    time = (time < 1000) ? time : static_cast<double>(time / 1000);

    return QString("%1 %2").arg(time).arg(ext);
}
