#include "hashtable.h"

/**
 * @brief HashTable::HashTable
 * @param _data - array of data
 */
HashTable::HashTable(const data_t &_data)
{
    TimeKeeper::getInstance()->start();
    data.resize(_data.size());

    for (int i = 0; i < _data.size(); ++i)
        insert(_data.at(i));

    qDebug().noquote() << QString("HashTable was built by %1").arg(TimeKeeper::getInstance()->finish());
}

/**
 * @brief HashTable::~HashTable
 */
HashTable::~HashTable() {}

/**
 * @brief HashTable::find
 * @param date
 * @return founded data
 */
Data HashTable::find(const QString &date)
{
    TimeKeeper::getInstance()->start();

    int index = hash(date);

    foreach (auto _data, data.at(index))
        if (_data.at(DATE).toString() == date)
        {
            qDebug().noquote() << QString("Find data in HashTable: %1").arg(TimeKeeper::getInstance()->finish());
            return _data;
        }

    qDebug().noquote() << QString("Data not found!: %1").arg(TimeKeeper::getInstance()->finish());
    return Data();
}

/**
 * @brief HashTable::insert
 * @param _data
 *
 * Inserts new element into HashTable
 */
void HashTable::insert(const Data &_data)
{
    data[hash(_data.at(DATE).toString())].append(_data);
}

/**
 * @brief HashTable::hash
 * @param key
 * @return index for HashTable internal storage
 *
 * Computing special hash-string and returns index
 */
int HashTable::hash(const QString &key) const
{
    size_t i = 0;
    int levelCounter = 0;
    foreach (auto symbol, key)
    {
        levelCounter += 1;
        i += static_cast<int>(symbol.toLatin1());

        if (levelCounter % 3)
            i *= levelCounter;
    }

    return i % data.size();
}

/**
 * @brief HashTable::calculateErrors
 * @return number of collisius of this dataset
 */
int HashTable::calculateErrors()
{
    int errors = 0;
    foreach (auto item, data)
        if (item.size() > 1)
            errors += item.size() - 1;

    return errors;
}
