#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

pNode newNode(ElementType val) {
    pNode node = (pNode)malloc(sizeof(Node));
    if(NULL == node)
        ERR_EXIT("malloc");
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// T(n) = O(h), h is the height of the tree
pNode find(pNode root, ElementType val) {
    if(root == NULL ||  root->val == val)
        return root;
    if(val < root->val)
        return find(root->left, val);
    else
        return find(root->right, val);
}

// T(n) = O(h), h is the height of the tree
pNode findMin(pNode root) {
    pNode pMin = root;
    if(root == NULL)
        return NULL;
    while(pMin->left != NULL)
        pMin = pMin->left;
    return pMin;
}

// T(n) = O(h), h is the height of the tree
pNode findMax(pNode root) {
    pNode pMax = root;
    if(root == NULL)
        return NULL;
    while(pMax->right != NULL)
        pMax = pMax->right;
    return pMax;
}

// T(n) = O(h), h is the height of the tree
pNode insertNode(pNode root, ElementType val) {
    if(root == NULL)
        return newNode(val);
    if(val < root->val)
        root->left = insertNode(root->left, val);
    else if(val > root->val)
        root->right = insertNode(root->right, val);
    // if "val == root->val", then do nothing
    return root;
}

// T(n) = O(h), h is the height of the tree
pNode deleteNode(pNode root, ElementType val) {
    pNode tmp;
    if(root == NULL)
        return root;
    else if(val < root->val)  // go left
        root->left = deleteNode(root->left, val);
    else if(val > root->val)  // go right
        root->right = deleteNode(root->right, val);
    else if(root->left && root->right) {  // node with two children
        tmp = findMin(root->right);  // Get the inorder successor (smallest in the right subtree)
        root->val = tmp->val;
        root->right = deleteNode(root->right, root->val);
    } else {   // node with one child or no child
        tmp = root;
        if(root->left == NULL)
            root = root->right;
        else if(root->right == NULL)
            root = root->left;
        free(tmp);
    }
    return root;
}

void printTreePreOrder(pNode root) {   // print in pre-order
    if(root == NULL)
        return;
    printf("%d\n", root->val);
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}

pNode makeEmpty(pNode root) {
    if(root != NULL) {
        makeEmpty(root->left);
        makeEmpty(root->right);
        free(root);
    }
    return NULL;
}


int main() {
    pNode root = NULL;
    pNode tempNode = NULL;
    int num;
    
    /********** Insertion **********/
    root = insertNode(root, 12);
    root = insertNode(root, 2);
    root = insertNode(root, 34);
    root = insertNode(root, 18);
    root = insertNode(root, 21);
    root = insertNode(root, 17);
    root = insertNode(root, 15);
    root = insertNode(root, 20);
    root = insertNode(root, 25);
    root = insertNode(root, 19);

    printf("Original:\nPreOrder:\n");
    printTreePreOrder(root);
    /*

            12
           /  \
          2   34
             /  
            18
           /  \
          17  21
          /   / \
         15  20 25
             /
            19
 
    */
    
    /********** Find min and max **********/
    printf("\n");
    printf("Min value in bst: %d\n", findMin(root) -> val);
    printf("Max value in bst: %d\n", findMax(root) -> val);
    
    /********** Deletion **********/
    root = deleteNode(root, 18);
    printf("\nAfter deletion 18:\nPreOrder:\n");
    printTreePreOrder(root);
    /*
           12
          /  \
         2   34
             /
            19
           /  \
          17  21
         /   /  \
        15  20  25
    */
    
    /********** Find operation **********/
    printf("\nInput a number you want to find: ");
    scanf("%d", &num);
    tempNode = find(root, num);
    if(NULL == tempNode)
        printf("%d is not in bst.\n\n", num);
    else
        printf("%d is in bst.\n\n", num);
    
    /********** MakeEmpty **********/
    root = makeEmpty(root);
    if(NULL == root)
        printf("Bst is cleared.\n");
    
    return 0;
}
