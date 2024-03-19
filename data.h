#ifndef DATA_H
#define DATA_H
#include <QVariantList>
#include <QString>
#include <QVector>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QThread>
#include <QDate>

/**
 * @brief Types of data, which containing in Data class
 */
enum DataType
{
    FLY     , ///< 1th field
    DATE    , ///< 2nd field
    NAME    , ///< 3td field
    PLACE   , ///< 4th field
};

/**
 * @brief The Data class
 *
 * Wrapper for 4 fields.
 * Class for comparing in right order, between its fields
 */
class Data
{
public:

    explicit Data(int fly = -1, const QString &sDate = "", const QString &name = "", int place = -1);

    QString toString() const;
    QVariant at(int index) const;
    bool operator== (const Data &other) const;
    bool operator!= (const Data &other) const;
    bool operator< (const Data &other)  const;
    bool operator<= (const Data &other) const;
    bool operator> (const Data &other)  const;
    bool operator>= (const Data &other) const;

private:
    QDate date(const QString &dateString) const;

    int fly;        ///< number of flight
    int place;      ///< number of place in airplane
    QString sDate;  ///< date in format 'dd/mm/yyyy'
    QString name;   ///< name in format 'Some Person'
};

using data_t = QVector<Data>;

#endif // DATA_H
