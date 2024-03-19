#include "binarytree.h"

BinaryNode::BinaryNode(const Data &_data)
    : data(_data), left(nullptr), right(nullptr)
{}

BinaryNode::~BinaryNode()
{
    if (left)
        delete left;

    if (right)
        delete right;
}

QString BinaryNode::key()
{
    return data.at(DATE).toString();
}

BinaryTree::BinaryTree(const data_t &_data)
    : root(nullptr)
{
    if (_data.empty())
        return;

    TimeKeeper::getInstance()->start();

    for (int i = 0; i < _data.size(); ++i)
        insert(_data.at(i));

    qDebug() << QString("Binary tree was built by %1").arg(TimeKeeper::getInstance()->finish());
}

BinaryTree::~BinaryTree()
{
    if (root)
        delete root;
}

Data BinaryTree::find(const QString &date)
{
    TimeKeeper::getInstance()->start();

    BinaryNode **currentNode = &root;

    while (*currentNode)
    {
        BinaryNode &node = **currentNode;
        if (node.key().compare(date) < 0)
            currentNode = &node.left;
        else if (node.key().compare(date) > 0)
            currentNode = &node.right;
        else
        {
            qDebug() << QString("Find data in binary tree: %1").arg(TimeKeeper::getInstance()->finish());
            return node.data;
        }
    }

    qDebug() << QString("Data not found!: %1").arg(TimeKeeper::getInstance()->finish());
    return Data();
}

void BinaryTree::insert(const Data &_data)
{
    BinaryNode **currentNode = &root;

    while (*currentNode)
    {
        BinaryNode &node = **currentNode;
        if (node.key().compare(_data.at(DATE).toString()) < 0)
            currentNode = &node.left;
        else
            currentNode = &node.right;
    }

    *currentNode = new BinaryNode(_data);
}
