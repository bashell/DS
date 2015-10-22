#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char *argv[]) {
    static searchTree T;
    static position tempNode;
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
    printf("The min value in this tree: %d\n", findMin(T) -> val);
    printf("The max value in this tree: %d\n", findMax(T) -> val);
    
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
        printf("%d is in this tree.\n\n", num);
    else
        printf("%d is not in this tree.\n\n", num);
    
    /********** MakeEmpty **********/
    T = makeEmpty(T);
    if(T == NULL)
        printf("The tree has no nodes now.\n");

    return 0;
}
