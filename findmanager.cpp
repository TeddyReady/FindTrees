#include "findmanager.h"

/**
 * @brief FindManager::FindManager
 * @param count - number of generated data
 * @param order - SortOrder::UP or SortOrder::DOWN
 *
 * Generate and sort data, check delay
 */
FindManager::FindManager(int count)
{
    uploadData(count);

    qDebug() << binaryTree("11/4/2023").toString();
}

Data FindManager::binaryTree(const QVariant &key)
{
    BinaryTree tree(data);

    return tree.find(key.toString());
}

Data FindManager::rbTree(const QVariant &key)
{

}

Data FindManager::hashTable(const QVariant &key)
{

}

/**
 * @brief FindManager::uploadData
 * @param count - number of generating data
 *
 * Generate data for sort
 */
void FindManager::uploadData(int count)
{
    qDebug() << "Begin data generating...";
    data.clear();

    for (int i = count; i >=0; --i)
        data.append(Data(i%3, QString("11/%1/2023").arg(i%8), getRandomName(i), i%4));

    qDebug() << "Data uploaded!";
}

/**
 * @brief FindManager::getRandomName
 * @param i - magic number for random
 * @return Random name for data
 */
QString FindManager::getRandomName(int i) const
{
    QString result;
    switch (i % 6) {
    case 0:
        result.append("Ilya ");
        break;
    case 1:
        result.append("Roman ");
        break;
    case 2:
        result.append("Vasiliy ");
        break;
    case 3:
        result.append("George ");
        break;
    case 4:
        result.append("Petr ");
        break;
    case 5:
        result.append("Gleb ");
        break;
    }

    switch (i % 4) {
    case 0:
        result.append("Kataev");
        break;
    case 1:
        result.append("Garkin");
        break;
    case 2:
        result.append("Ivanov");
        break;
    case 3:
        result.append("Samoilov");
        break;
    }
    return result;
}
