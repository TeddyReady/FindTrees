#include "data.h"

/**
 * @brief Data::Data
 * @param fly - number of flight
 * @param sDate - date in format 'dd/mm/yyyy'
 * @param name - name in format 'Some Person'
 * @param place - number of place in airplane
 */
Data::Data(int fly, const QString &sDate, const QString &name, int place)
    : fly(fly), place(place), sDate(sDate), name(name) {}

QString Data::toString() const
{
    return QString("Fly number %1, place %2, name of passenger %3, date %4")
        .arg(fly).arg(place).arg(name).arg(sDate);
}

/**
 * @brief Data::at
 * @param index - number of field (see DataType)
 * @return One of date fields in QVariant
 */
QVariant Data::at(int index) const
{
    QVariant item;
    switch (index)
    {
    case 0:
        item = QVariant(fly);
        break;
    case 1:
        item = QVariant(sDate);
        break;
    case 2:
        item = QVariant(name);
        break;
    case 3:
        item = QVariant(place);
        break;
    }
    return item;
}

/**
 * @brief Data::date
 * @param dateString - string in format 'dd/mm/yyyy'
 * @return data string converted in QDate
 */
QDate Data::date(const QString &dateString) const
{
    QStringList dateList = dateString.split("/");
    return QDate(dateList.at(2).toInt(), dateList.at(1).toInt(), dateList.at(0).toInt());
}

/**
 * @brief Data::operator ==
 * @param other
 * @return Result of compare
 */
bool Data::operator== (const Data &other) const
{
    return date(sDate) == date(other.sDate) && fly == other.fly && name.compare(other.name) == 0 && place == other.place;
}

/**
 * @brief Data::operator !=
 * @param other
 * @return Result of compare
 */
bool Data::operator!= (const Data &other) const
{
    return !(*this == other);
}

/**
 * @brief Data::operator <
 * @param other
 * @return Result of compare
 */
bool Data::operator< (const Data &other) const
{
    if (date(sDate) < date(other.sDate))
        return true;

    else if (date(sDate) == date(other.sDate) && fly < other.fly)
        return true;

    else if (date(sDate) == date(other.sDate) && fly == other.fly && name.compare(other.name) < 0)
        return true;

    else if (date(sDate) == date(other.sDate) && fly == other.fly && name.compare(other.name) == 0 && place < other.place)
        return true;

    return false;
}

/**
 * @brief Data::operator <=
 * @param other
 * @return Result of compare
 */
bool Data::operator<= (const Data &other) const
{
    return (*this < other) || (*this == other);
}

/**
 * @brief Data::operator >
 * @param other
 * @return Result of compare
 */
bool Data::operator> (const Data &other) const
{
    return !(*this <= other);
}

/**
 * @brief Data::operator >=
 * @param other
 * @return Result of compare
 */
bool Data::operator>= (const Data &other) const
{
    return !(*this < other);
}
