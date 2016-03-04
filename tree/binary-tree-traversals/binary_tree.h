#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} Node, *pNode;

pNode newNode(int val);
void printPreOrder(pNode root);
void printInOrder(pNode root);
void printPostOrder(pNode root);

int height(pNode node);
void printGivenLevel(pNode root, int level);
void printLevelOrder1(pNode root);

pNode *createQueue(int *front, int *rear);
void enQueue(pNode *queue, int *rear, pNode new_node);
pNode deQueue(pNode *queue, int *front);
void printLevelOrder2(pNode root);

#endif  /* BINARY_TREE_H */
