#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char *argv[])
{
    searchTree T;
    position tempNode;
    int num;

    T = insertNode(20, T);
    T = insertNode(10, T);
    T = insertNode(3, T);
    T = insertNode(9, T);
    T = insertNode(23, T);
    T = insertNode(13, T);
    T = insertNode(7, T);

    
    printf("Original:\n");
    printTree(T);
    
    printf("The min value in this tree: %d\n", retrieve(findMin(T)));
    printf("The max value in this tree: %d\n", retrieve(findMax(T)));
    
    T = deleteNode(10, T);
    T = deleteNode(13, T);
    printf("After deletion:\n");
    printTree(T);

    tempNode = find(3, T);
    printf("%d\n", tempNode -> val);

    exit(EXIT_SUCCESS);
}
