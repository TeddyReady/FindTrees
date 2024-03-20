#ifndef FindManager_H
#define FindManager_H
#include <QRandomGenerator>
#include <QMultiMap>
#include "rbtree.h"
#include "hashtable.h"

/**
 * @brief The FindManager class
 *
 * Class for sorting and generating data (Data)
 */
class FindManager
{
public:
    explicit FindManager(int count = 100);

private:
    void uploadData(int count);
    QString getRandomName() const;

    Data binaryTree(const QVariant &key);
    Data rbTree(const QVariant &key);
    Data hashTable(const QVariant &key);
    Data stdMap(const QVariant &key);

    QVector<Data> data;
    QRandomGenerator *gen;
};

#endif // FindManager_H
