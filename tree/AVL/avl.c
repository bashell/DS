#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


void preOrder(pAvlNode root) {
    if(root == NULL)
        return;
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}


pAvlNode newNode(int val) {
    pAvlNode node = (pAvlNode)malloc(sizeof(AvlNode));
    if(node == NULL)
        ERR_EXIT("malloc");
    node->val = val;
    node->left = node->right = NULL;
    node->height = 1;  // new node is initially added at leaf
}


pAvlNode findMin(pAvlNode root) {
    pAvlNode cur = root;
    while(cur->left != NULL)
        cur = cur->left;
    return cur;
}


int getHeight(pAvlNode node) {
    if(node == NULL)
        return 0;
    return node->height;
}


int max(int a, int b) {
    return a > b ? a : b;
}


int getBalance(pAvlNode node) {
    return node == NULL ? 0 : getHeight(node->left) - getHeight(node->right);
}


/* 
 * T(N) = O(1)
 */
pAvlNode leftRotate(pAvlNode node) {
    pAvlNode tmp;
    tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    tmp->height = max(getHeight(tmp->right), node->height) + 1;
    return tmp;  // new root
}


/*
 * T(N) = O(1)
 */
pAvlNode rightRotate(pAvlNode node) {
    pAvlNode tmp;
    tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    tmp->height = max(getHeight(tmp->left), node->height) + 1;
    return tmp;  // new root
}


/*
 * T(N) = O(logN), N is the number of nodes
 */
pAvlNode insertNode(pAvlNode root, int val) {
    if(root == NULL)
        return newNode(val);
    if(val < root->val) {
        root->left = insertNode(root->left, val);
        int balance = getBalance(root);
        if(balance > 1 && val < root->left->val) {  // "Left-Left" : RightRotate
            return rightRotate(root);
        }
        if(balance > 1 && val > root->left->val) {  // "Left-Right" : LeftRotate + RightRotate
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    } else if(val > root->val) {
        root->right = insertNode(root->right, val);
        int balance = getBalance(root);
        if(balance < -1 && val < root->right->val) {  // "Right-Left" : RightRotate + LeftRotate
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        if(balance < -1 && val > root->right->val) {  // "Right-Right" : LeftRotate
            return leftRotate(root);
        }
    }

    // Update the height
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}


/*
 * T(N) = O(logN), N is the number of nodes
 */
pAvlNode deleteNode(pAvlNode root, int val) {
    // 1. Perform standard BinarySearchTree deletion.
    pAvlNode tmp;
    if(root == NULL)
        return root;
    if(val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if(val > root->val) {
        root->right = deleteNode(root->right, val);
    } else if(root->left && root->right) {  // node with two children
        tmp = findMin(root->right);
        root->val = tmp->val;
        root->right = deleteNode(root->right, root->val);
    } else {  // node with 0 or 1 child
        tmp = root;
        if(root->left == NULL)
            root = root->right;
        else if(root->right == NULL)
            root = root->left;
        free(tmp);
    }
    if(root == NULL)
        return root;
    
    // 2. Get the balance factor of the current node
    int balance = getBalance(root);

    // 3. If not balanced, fix it
    if(balance > 1 && getBalance(root->left) >= 0) {  // "Left-Left"
        return rightRotate(root);
    }
    if(balance > 1 && getBalance(root->left) < 0) {  // "Left-Right"
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && getBalance(root->right) > 0) {  // "Right-Left"
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    if(balance < -1 && getBalance(root->right) <= 0) {  // "Right-Right"
        return leftRotate(root);
    }

    // 4. Update the height
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}




int main()
{
    pAvlNode root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 22);
    root = insertNode(root, 35);
    root = insertNode(root, 44);
    root = insertNode(root, 58);
    root = insertNode(root, 27);
    root = insertNode(root, 8);
    root = insertNode(root, 23);
    root = insertNode(root, 30);

    /* AVL tree should be:

            35
           /  \
          22  44
         /  \   \
        10  27   58
       /   /  \
      8   23  30

    */

    printf("PreOrder traversal of ths AVL:\n");
    preOrder(root);
    printf("\n");

    root = deleteNode(root, 44);
    /* After deletion, AVL tree should be:

            22
           /  \
          10  35
         /   /  \
        8   27   58
           /  \
          23  30

    */
    printf("\nPreOrder traversal after deleting 44:\n");
    preOrder(root);
    printf("\n");
    return 0;
}

