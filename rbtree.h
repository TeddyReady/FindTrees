#ifndef RBTREE_H
#define RBTREE_H
#include "binarytree.h"

class RBTree : public BinaryTree
{
public:
    explicit RBTree(const data_t &_data);

private:
    void insert(const Data &_data) override;
    void balanceTree(BinaryNode **node);
};

#endif // RBTREE_H
