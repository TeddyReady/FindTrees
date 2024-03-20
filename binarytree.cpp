#include "binarytree.h"

BinaryNode::BinaryNode(const Data &_data, bool isRed)
    : data(_data), left(nullptr), right(nullptr), isRed(isRed)
{}

BinaryNode::~BinaryNode()
{
    if (left)
        delete left;

    if (right)
        delete right;
}

int BinaryNode::key()
{
    return data.at(PLACE).toInt();
}

BinaryTree::BinaryTree(const data_t &_data)
    : data(_data), root(nullptr)
{}

BinaryTree::~BinaryTree()
{
    if (root)
        delete root;
}

void BinaryTree::buildTree()
{
    TimeKeeper::getInstance()->start();

    for (int i = 0; i < data.size(); ++i)
        insert(data.at(i));

    qDebug().noquote() << QString("Binary tree was built by %1").arg(TimeKeeper::getInstance()->finish());
}

Data BinaryTree::find(const int &date)
{
    if (root == nullptr)
        buildTree();

    TimeKeeper::getInstance()->start();

    BinaryNode **currentNode = &root;

    while (*currentNode)
    {
        BinaryNode &node = **currentNode;
        if (date < node.key())
            currentNode = &node.left;
        else if (date > node.key())
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

void BinaryTree::insert(const Data &_data)
{
    BinaryNode **currentNode = &root;

    while (*currentNode)
    {
        BinaryNode &node = **currentNode;
        if (_data.at(PLACE).toInt() < node.key())
            currentNode = &node.left;
        else
            currentNode = &node.right;
    }

    *currentNode = new BinaryNode(_data);
}
