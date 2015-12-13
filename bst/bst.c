#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

searchTree makeEmpty(searchTree T) {
    if(T != NULL) {
        makeEmpty(T -> left);
        makeEmpty(T -> right);
        free(T);
    }
    return NULL;
}

position find(ElementType x, searchTree T) {
    if(T == NULL)
        return NULL;
    if(x == T -> val)
        return T;
    else if(x < T -> val)
        return find(x, T -> left);
    else
        return find(x, T -> right);
}

position findMin(searchTree T) {
    position pMin = T;
    if(T == NULL)
        return NULL;
    while(pMin -> left != NULL)
        pMin = pMin -> left;
    return pMin;
}

position findMax(searchTree T) {
    position pMax = T;
    if(T == NULL)
        return NULL;
    while(pMax -> right != NULL)
        pMax = pMax -> right;
    return pMax;
}

searchTree insertNode(ElementType x, searchTree T) {
    if(T == NULL) {
        T = (searchTree)malloc(sizeof(struct TreeNode));
        if(T == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        } else {
            T -> val = x;
            T -> left = NULL;
            T -> right = NULL;
        }
    }
    else if(x < T -> val)
        T -> left = insertNode(x, T -> left);
    else if(x > T -> val)
        T -> right = insertNode(x, T -> right);
    return T;
}

searchTree deleteNode(ElementType x, searchTree T) {
    position tempNode;
    if(T == NULL) {
        fprintf(stderr, "Element not found\n");
        exit(EXIT_FAILURE);
    }
    else if(x < T -> val)  // go left
        T -> left = deleteNode(x, T -> left);
    else if(x > T -> val)  // go right
        T -> right = deleteNode(x, T -> right);
    else if(T -> left && T -> right) {  // find the node to delete (two children)
        tempNode = findMin(T -> right);
        T -> val = tempNode -> val;
        T -> right = deleteNode(T -> val, T -> right);
    } else {   // find the node to delete (one or zero children)
        tempNode = T;
        if(T -> left == NULL)
            T = T -> right;
        else if(T -> right == NULL)
            T = T -> left;
        free(tempNode);
    }
    return T;
}

void printTree(searchTree T) {   // print in pre-order
    if(T == NULL)
        return;
    printTree(T -> left);
    printf("%d\n", T -> val);
    printTree(T -> right);
}

int main() {
    searchTree T = NULL;
    position tempNode = NULL;
    int num;
    
    /********** Insertion **********/
    T = insertNode(20, T);
    T = insertNode(10, T);
    T = insertNode(3, T);
    T = insertNode(9, T);
    T = insertNode(23, T);
    T = insertNode(13, T);
    T = insertNode(7, T);

    printf("Original:\n");
    printTree(T);
    
    /********** Find min and max **********/
    printf("\n");
    printf("The min value in bst tree: %d\n", findMin(T) -> val);
    printf("The max value in bst tree: %d\n", findMax(T) -> val);
    
    /********** Deletion **********/
    T = deleteNode(10, T);
    T = deleteNode(13, T);
    printf("\nAfter deletion:\n");
    printTree(T);
    
    /********** Find operation **********/
    printf("\nInput a number you want to find: ");
    scanf("%d", &num);
    tempNode = find(num, T);
    if(tempNode != NULL)
        printf("%d is in bst tree.\n\n", num);
    else
        printf("%d is not in bst tree.\n\n", num);
    
    /********** MakeEmpty **********/
    T = makeEmpty(T);
    if(T == NULL)
        printf("The tree has no nodes now.\n");
    
    return 0;
}
