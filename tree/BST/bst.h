#ifndef _BST_H_
#define _BST_H_

#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

typedef int ElementType;

typedef struct TreeNode {
    ElementType val;
    struct TreeNode *left;
    struct TreeNode *right;
} Node, *pNode;

pNode newNode(ElementType val);
pNode find(pNode root, ElementType val);
pNode findMin(pNode root);
pNode findMax(pNode root);
pNode insertNode(pNode root, ElementType val);
pNode deleteNode(pNode root, ElementType val);
void printTreePreOrder(pNode T);
pNode makeEmpty(pNode T);

#endif  /* _BST_H_ */
