#include <stdio.h>
#include "bst.h"

void printResult(BTreeNode * target);
void inorder(BTreeNode * root);

int main()
{
    BTreeNode * bstRoot = NULL;
    BTreeNode * target;

    // BST insert
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 4);
    BSTInsert(&bstRoot, 5);
    BSTInsert(&bstRoot, 6);
    inorder(bstRoot);
    printf("\n");

    // BST search
    target = BSTSearch(bstRoot, 1);
    printResult(target);
    target = BSTSearch(bstRoot, 4);
    printResult(target);

    // BST delete
    BSTDelete(bstRoot, 4);
    target = BSTSearch(bstRoot, 4);
    printResult(target);
    inorder(bstRoot);
    printf("\n");

    return 0;
}

void printResult(BTreeNode * target)
{
    if (target != NULL)
        printf("search success : %d\n", target->data);
    else
        printf("target is null\n");
}

void inorder(BTreeNode * root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}