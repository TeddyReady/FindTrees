#ifndef FindManager_H
#define FindManager_H
#include "rbtree.h"

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
    QString getRandomName(int i) const;

    Data binaryTree(const QVariant &key);
    Data rbTree(const QVariant &key);
    Data hashTable(const QVariant &key);

    QVector<Data> data;
};

#endif // FindManager_H
