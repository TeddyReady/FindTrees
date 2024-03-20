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
    gen = QRandomGenerator::global();
    uploadData(count);

    int index = static_cast<int>(data.size() / 2);

    qDebug().noquote() << binaryTree(data.at(index).at(DATE)).toString() << "\n";
    qDebug().noquote() << rbTree(data.at(index).at(DATE)).toString() << "\n";
    qDebug().noquote() << hashTable(data.at(index).at(DATE)).toString() << "\n";
    qDebug().noquote() << stdMap(data.at(index).at(DATE)).toString() << "\n";
}

/**
 * @brief FindManager::binaryTree
 * @param key
 * @return founded data
 *
 * Constructs a BinaryTree and try to find data from them
 */
Data FindManager::binaryTree(const QVariant &key)
{
    BinaryTree tree(data);

    return tree.find(key.toString());
}

/**
 * @brief FindManager::rbTree
 * @param key
 * @return founded data
 *
 * Constructs a RBTree and try to find data from them
 */
Data FindManager::rbTree(const QVariant &key)
{
//    data_t data;
//    std::vector<int> digits({24, 5, 1, 15, 3, 8, 13, 16});
//    for (size_t i = 0; i < digits.size(); ++i)
//        data.append(Data(1, "", "", digits.at(i)));

    RBTree tree(data);

    return tree.find(key.toString());
}

/**
 * @brief FindManager::hashTable
 * @param key
 * @return founded data
 *
 * Constructs a HashTable and try to find data from them
 */
Data FindManager::hashTable(const QVariant &key)
{
    HashTable table(data);

    qDebug().noquote() << "Number of errors in this HashTable: " << table.calculateErrors();

    return table.find(key.toString());
}

/**
 * @brief FindManager::stdMap
 * @param key
 * @return founded data
 *
 * Constructs a QMultiMap<QString, Data> and try to find data from them
 */
Data FindManager::stdMap(const QVariant &key)
{
    TimeKeeper::getInstance()->start();
    QMultiMap<QString, Data> map;

    foreach (auto blk, data)
        map.insert(blk.at(DATE).toString(), blk);
    qDebug().noquote() << QString("QMultiMap was built by %1").arg(TimeKeeper::getInstance()->finish());

    TimeKeeper::getInstance()->start();
    auto tmp = map.values(key.toString());
    qDebug().noquote() << QString("Find data in QMultiMap: %1").arg(TimeKeeper::getInstance()->finish());
    return tmp.first();
}

/**
 * @brief FindManager::uploadData
 * @param count - number of generating data
 *
 * Generate data for sort
 */
void FindManager::uploadData(int count)
{
    qDebug().noquote() << "Begin data generating...";
    data.clear();

    for (int i = count; i >=0; --i)
        data.append(
            Data(gen->bounded(100, 1000),
            QString("%1/%2/%3").arg(gen->bounded(1, 31)).arg(gen->bounded(1, 13)).arg(gen->bounded(2000, 2025)),
            getRandomName(),
            gen->bounded(1000, 10000))
        );

    qDebug().noquote() << "Data uploaded!" << "\n";
}

/**
 * @brief FindManager::getRandomName
 * @return Random name for data
 */
QString FindManager::getRandomName() const
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    const int randomStringLength = gen->bounded(4, 11);

    QString randomString;
    for (int i = 0; i < randomStringLength; ++i)
    {
        int index = gen->bounded(0, possibleCharacters.length());
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }

    return randomString;
}
