#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

// 이진 검색 트리
void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode * cur = *pRoot; 
    BTreeNode * parent = NULL;
    // 비교하는 노드보다 작으면 왼쪽으로, 크면 오른쪽으로 이동
    // 비교하는 노드가 NULL일 때까지 반복
    while (cur != NULL)
    {
        parent = cur;
        if (cur->data == data)
        {
            printf("same key error\n");
            return;
        }
        else if (cur->data < data)
            cur = cur->right;
        else 
            cur = cur->left;
    }
    
    BTreeNode * newNode = MakeBTreeNode(data);
    if (parent != NULL)
    {
        if (parent->data < newNode->data)
            parent->right = newNode;
        else 
            parent->left = newNode;
    }
    else
        *pRoot = newNode;
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * cur = bst;
    while (cur != NULL)
    {
        if (cur->data == target)
            return cur;
        else if (cur->data < target)
            cur = cur->right;
        else
            cur = cur->left;
    }
    return NULL;
}

BTreeNode * BSTDelete(BTreeNode * pRoot, BSTData data)
{
    if (pRoot == NULL)
        return pRoot;
        
    BTreeNode * cur = pRoot;
    BTreeNode * parent = NULL;

    while ((cur != NULL) && (cur->data != data))
    {
        parent = cur;
        if (cur->data > data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (cur == NULL)
    {
        printf("존재하지 않는 노드\n");
        return pRoot; // 삭제 후 새로운 루트 노드의 주소 전달
    }

    // 차수가 0인 노드 삭제 -리프노드 삭제
    if (cur->left == NULL && cur->right == NULL)
    {
        if (parent == NULL) // 노드가 1개인 트리
            pRoot = NULL;
        else if (parent->data > cur->data) // parent->left == cur
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    // 차수가 1인 노드 삭제 
    else if (cur->left == NULL || cur->right == NULL)
    {
        BTreeNode * child = (cur->left != NULL) ? cur->left : cur->right;

        if (parent == NULL) // 루트노드를 삭제
            pRoot = child;
        else if (parent->data > cur->data)
            parent->left = child;
        else
            parent->right = child;
    }
    // 차수가 2인 노드 삭제 
    else
    {
        BTreeNode * delpos = pRoot->right;
        // 오른쪽 서브트리에서 후계자를 찾는다면 오른쪽 서브트리에서 가장 작은 수를 찾아야함
        // 오른쪽 서브트리에서의 가장 작은 값은 항상 왼쪽 노드가 NULL임
        while (delpos->left != NULL)
            delpos = delpos->left;

        pRoot->data = delpos->data;
        pRoot->right = delpos->right;
        cur = delpos;
    }
    
    free(cur); // 해당 노드 삭제
}

BTreeNode * MakeBTreeNode(BSTData data)
{
    BTreeNode * newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

