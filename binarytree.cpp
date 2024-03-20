#include "binarytree.h"

/**
 * @brief BinaryNode::BinaryNode
 * @param _data - data for node
 * @param isRed - for RBTree
 */
BinaryNode::BinaryNode(const Data &_data, bool isRed)
    : data(_data), left(nullptr), right(nullptr), isRed(isRed)
{}

/**
 * @brief BinaryNode::~BinaryNode
 */
BinaryNode::~BinaryNode()
{
    if (left)
        delete left;

    if (right)
        delete right;
}

/**
 * @brief BinaryNode::key
 * @return key value
 */
QString BinaryNode::key()
{
    return data.at(DATE).toString();
}

/**
 * @brief BinaryTree::BinaryTree
 * @param _data vector of data
 */
BinaryTree::BinaryTree(const data_t &_data)
    : data(_data), root(nullptr)
{}

/**
 * @brief BinaryTree::~BinaryTree
 */
BinaryTree::~BinaryTree()
{
    if (root)
        delete root;
}

/**
 * @brief BinaryTree::buildTree
 *
 * Builds a binary tree
 */
void BinaryTree::buildTree()
{
    TimeKeeper::getInstance()->start();

    for (int i = 0; i < data.size(); ++i)
        insert(data.at(i));

    qDebug().noquote() << QString("Binary tree was built by %1").arg(TimeKeeper::getInstance()->finish());
}

/**
 * @brief BinaryTree::find
 * @param date - find date by this param
 * @return found data
 */
Data BinaryTree::find(const QString &date)
{
    if (root == nullptr)
        buildTree();

    TimeKeeper::getInstance()->start();

    BinaryNode **currentNode = &root;

    while (*currentNode)
    {
        BinaryNode &node = **currentNode;
        if (QString::compare(date, node.key()) < 0)
            currentNode = &node.left;
        else if (QString::compare(date, node.key()) > 0)
            currentNode = &node.right;
        else
        {
            qDebug().noquote() << QString("Find data in binary tree: %1").arg(TimeKeeper::getInstance()->finish());
            return node.data;
        }
    }

    qDebug().noquote() << QString("Data not found!: %1").arg(TimeKeeper::getInstance()->finish());
    return Data();
}

/**
 * @brief BinaryTree::insert
 * @param _data - some data
 *
 * Insert new element into BinaryTree
 */
void BinaryTree::insert(const Data &_data)
{
    BinaryNode **currentNode = &root;

    while (*currentNode)
    {
        BinaryNode &node = **currentNode;
        if (QString::compare(_data.at(DATE).toString(), node.key()) < 0)
            currentNode = &node.left;
        else
            currentNode = &node.right;
    }

    *currentNode = new BinaryNode(_data);
}
