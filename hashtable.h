#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "timekeeper.h"
#include "data.h"

/**
 * @brief The HashTable class
 *
 * HashTable structure
 */
class HashTable
{
public:
    explicit HashTable(const data_t &_data);
    ~HashTable();

    Data find(const QString &date);
    int calculateErrors();
private:
    void insert(const Data &_data);
    int hash(const QString &key) const;

    QVector<QVector<Data>> data;
};

#endif // HASHTABLE_H
