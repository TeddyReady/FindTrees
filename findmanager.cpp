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
    qDebug().noquote() << binaryTree(data.at(2).at(PLACE)).toString() << "\n";
    qDebug().noquote() << rbTree(data.at(2).at(PLACE)).toString() << "\n";
}

Data FindManager::binaryTree(const QVariant &key)
{
    BinaryTree tree(data);

    return tree.find(key.toInt());
}

Data FindManager::rbTree(const QVariant &key)
{
//    data_t data;
//    std::vector<int> digits({24, 5, 1, 15, 3, 8, 13, 16});
//    for (size_t i = 0; i < digits.size(); ++i)
//        data.append(Data(1, "", "", digits.at(i)));

    RBTree tree(data);

    return tree.find(key.toInt());
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
    qDebug().noquote() << "Begin data generating...";
    data.clear();

    for (int i = count; i >=0; --i)
        data.append(Data(gen->bounded(100, 1000), QString("11/%1/2023").arg(gen->bounded(1, 13)), getRandomName(), gen->bounded(1, 100000)));

    qDebug().noquote() << "Data uploaded!" << "\n";
}

/**
 * @brief FindManager::getRandomName
 * @return Random name for data
 */
QString FindManager::getRandomName() const
{
    QString result;
    switch (gen->bounded(0, 6)) {
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

    switch (gen->bounded(0, 4)) {
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
