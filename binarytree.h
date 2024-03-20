#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "data.h"
#include "timekeeper.h"

class BinaryNode
{
public:
    explicit BinaryNode(const Data &_data, bool isRed = true);
    ~BinaryNode();
    QString key();

    Data data;
    BinaryNode *left, *right;
    bool isRed;
};

class BinaryTree
{
public:
    explicit BinaryTree(const data_t &_data);
    ~BinaryTree();

    Data find(const QString &date);

protected:
    void buildTree();
    virtual void insert(const Data &_data);

    data_t data;
    BinaryNode *root;
    QElapsedTimer delay;
};

#endif // BINARYTREE_H
