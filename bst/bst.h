#ifndef BST_H
#define BST_H

typedef int ElementType;

typedef struct TreeNode {
    ElementType val;
    struct TreeNode *left;
    struct TreeNode *right;
} *searchTree, *position;

searchTree makeEmpty(searchTree T);
position find(ElementType x, searchTree T);
position findMin(searchTree T);
position findMax(searchTree T);
searchTree insertNode(ElementType x, searchTree T);
searchTree deleteNode(ElementType x, searchTree T);
void printTree(searchTree T);

#endif  // BST_H
