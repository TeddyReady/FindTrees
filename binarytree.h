#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "data.h"
#include "timekeeper.h"

class BinaryNode
{
public:
    explicit BinaryNode(const Data &_data);
    ~BinaryNode();
    QString key();

    Data data;
    BinaryNode *left, *right;
};

class BinaryTree
{
public:
    explicit BinaryTree(const data_t &_data);
    ~BinaryTree();
    Data find(const QString &date);

private:
    void insert(const Data &_data);

    BinaryNode *root;
    QElapsedTimer delay;
};

#endif // BINARYTREE_H
