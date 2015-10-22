#ifndef _TREE_H

struct TreeNode;
typedef struct TreeNode *position;
typedef struct TreeNode *searchTree;
typedef int ElementType;

searchTree makeEmpty(searchTree T);
position find(ElementType x, searchTree T);
position findMin(searchTree T);
position findMax(searchTree T);
searchTree insertNode(ElementType x, searchTree T);
searchTree deleteNode(ElementType x, searchTree T);
void printTree(searchTree T);


#endif  /* _TREE_H */

struct TreeNode {
    ElementType val;
    searchTree left;
    searchTree right;
};

/*************** Implementation ***************/
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
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        else {
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
        printf("Element not found");
        exit(EXIT_FAILURE);
    }
    else if(x < T -> val)   // 向左走
        T -> left = deleteNode(x, T -> left);
    else if(x > T -> val)   // 向右走
        T -> right = deleteNode(x, T -> right);
    else if(T -> left && T -> right) {  // 找到了待删除元素, 且该元素有两个子节点
        tempNode = findMin(T -> right);    // 右子树中最小元素
        T -> val = tempNode -> val;
        T -> right = deleteNode(T -> val, T -> right);
    }
    else {   // 找到了待删除元素, 但该元素有0个或者1个子节点
        tempNode = T;
        if(T -> left == NULL)
            T = T -> right;
        else if(T -> right == NULL)
            T = T -> left;
        free(tempNode);
    }

    return T;
}

void printTree(searchTree T) {   // 按前序打印
    if(T == NULL)
        return;
    printTree(T -> left);
    printf("%d\n", T -> val);
    printTree(T -> right);
}
