#ifndef _AVL_H_
#define _AVL_H_

#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

typedef struct AvlNode {
    int val;
    struct AvlNode *left;
    struct AvlNode *right;
    int height;
} AvlNode, *pAvlNode;

void preOrder(pAvlNode root);
pAvlNode newNode(int val);
pAvlNode findMin(pAvlNode node);
int getHeight(pAvlNode node);
int max(int a, int b);
int getBalance(pAvlNode node);
pAvlNode leftRotate(pAvlNode node);
pAvlNode rightRotate(pAvlNode node);
pAvlNode insertNode(pAvlNode node, int val);
pAvlNode deleteNode(pAvlNode node, int val);


#endif  /* _AVL_H_ */
