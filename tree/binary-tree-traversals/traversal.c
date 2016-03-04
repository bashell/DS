#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

pNode newNode(int val) {
    pNode node = (pNode)malloc(sizeof(Node));
    if(node == NULL)
        ERR_EXIT("malloc");
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// T(n) = O(n)
void printPreOrder(pNode root) {
    if(root == NULL)
        return;
    printf("%d ", root->val);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// T(n) = O(n)
void printInOrder(pNode root) {
    if(root == NULL)
        return;
    printInOrder(root->left);
    printf("%d ", root->val);
    printInOrder(root->right);
}

// T(n) = O(n)
void printPostOrder(pNode root) {
    if(root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->val);
}



int height(pNode node) {  // suppose root's height is 1; an empty tree' height is 0
    if(node == NULL)
        return 0;
    int lheight = height(node->left);
    int rheight = height(node->right);
    return lheight > rheight ? lheight + 1 : rheight + 1;
}

void printGivenLevel(pNode root, int level) {
    if(root == NULL)
        return ;
    if(level == 1)
        printf("%d ", root->val);
    else if(level > 1) {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

// T(n) = O(n^2)
// worst case: skewed tree, T(n) = O(1) + O(2) + ... + O(n) = O(n^2)
void printLevelOrder1(pNode root) {
    if(root == NULL)
        return;
    int i = 1, h = height(root);
    while(i <= h) {
        printGivenLevel(root, i);
        ++i;
    }
}




pNode *createQueue(int *front, int *rear) {
    pNode *queue = (pNode *)malloc(sizeof(pNode) * 4096);
    if(queue == NULL)
        ERR_EXIT("malloc");
    *front = *rear = 0;
    return queue;
}

void enQueue(pNode *queue, int *rear, pNode new_node) {
    queue[*rear] = new_node;
    ++(*rear);
}

pNode deQueue(pNode *queue, int *front) {
    ++(*front);
    return queue[*front - 1];
}

void printLevelOrder2(pNode root) {
    int front, rear;
    pNode *queue = createQueue(&front, &rear);
    pNode tmp = root;
    while(tmp) {
        printf("%d ", tmp->val);
        if(tmp->left)
            enQueue(queue, &rear, tmp->left);
        if(tmp->right)
            enQueue(queue, &rear, tmp->right);
        tmp = deQueue(queue, &front);
    }
}



int main()
{
    pNode root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    printf("\nPreOrder:\n");
    printPreOrder(root);
    printf("\nInOrder:\n");
    printInOrder(root);
    printf("\nPostOrder:\n");
    printPostOrder(root);

    printf("\nLevelOrder1:\n");
    printLevelOrder1(root);
    printf("\nLevelOrder2:\n");
    printLevelOrder2(root);
    printf("\n");
    return 0;
}
