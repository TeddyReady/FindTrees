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
        if (node.key().compare(_data.at(DATE).toString()) < 0)
            currentNode = &node.left;
        else
            currentNode = &node.right;
    }

    *currentNode = new BinaryNode(_data);
    balanceTree(&root);
}

void RBTree::balanceTree(BinaryNode **node)
{
    if (*node == nullptr)
        return;

    balanceTree(&(*node)->left);
    balanceTree(&(*node)->right);
}
