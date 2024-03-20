#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "data.h"
#include "timekeeper.h"

/**
 * @brief The BinaryNode class
 *
 * Class, which represents element of binary or rb tree
 */
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

/**
 * @brief The BinaryTree class
 *
 * Binary tree structure
 */
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
