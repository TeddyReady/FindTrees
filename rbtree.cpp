#include "rbtree.h"

RBTree::RBTree(const data_t &_data)
    : BinaryTree(_data)
{}

void RBTree::insert(const Data &_data)
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
//    qDebug() << "\nBALANCING";
    balanceTree(&root);
//    qDebug() << "BALANCED\n";

//    printTree(&root);
}

void RBTree::balanceTree(BinaryNode **node)
{
    if (*node == nullptr)
        return;

    balanceTree(&(*node)->left);
//    qDebug() << (*node)->key();
    balanceTree(&(*node)->right);

    /* First trouble: two left-hand red nodes */
    if ((*node)->left != nullptr && (*node)->left->left != nullptr
        && (*node)->left->isRed == (*node)->left->left->isRed)
    {
//        qDebug() << "TWO RED LEAFES";

        BinaryNode &tmp = **node;
        *node = (*node)->left;
        (*node)->isRed = false;
        tmp.left = (*node)->right;
        (*node)->right = &tmp;
        (*node)->right->isRed = true;
    }

    /* Second trouble: children are red */
    if ((*node)->left != nullptr && (*node)->right != nullptr &&
        (*node)->left->isRed && (*node)->right->isRed)
    {
//        qDebug() << "CHILDREN ARE RED";

        (*node)->left->isRed = false;
        (*node)->right->isRed = false;
        (*node)->isRed = true;
    }

    /* Third trouble: root is red */
    if ((*node) == root && (*node)->isRed)
    {
//        qDebug() << "ROOT IS RED";

        (*node)->isRed = false;
    }

    /* Fourth trouble: right child red */
    if ((*node)->right != nullptr && (*node)->right->isRed)
    {
//        qDebug() << "RIGHT CHILD IS RED";

        BinaryNode &tmp = **node;
        *node = (*node)->right;
        (*node)->isRed = false;
        tmp.right = (*node)->left;
        (*node)->left = &tmp;
        (*node)->left->isRed = true;
    }
}

void RBTree::printTree(BinaryNode **node)
{
    if (*node == nullptr)
        return;

    printTree(&(*node)->left);
    qDebug() << (*node)->key() << (*node)->isRed;
    printTree(&(*node)->right);
}
