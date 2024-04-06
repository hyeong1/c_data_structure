#ifndef __BST_H__
#define __BST_H__

typedef int BSTData;

typedef struct _bTreeNode
{
    BSTData data;
    struct _bTreeNode * left;
    struct _bTreeNode * right;
} BTreeNode;

void BSTInsert(BTreeNode ** pRoot, BSTData data);
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);
BTreeNode * BSTDelete(BTreeNode * pRoot, BSTData data);
BTreeNode * MakeBTreeNode(BSTData data);             // BST node를 생성하여 그 주소값 반환

#endif