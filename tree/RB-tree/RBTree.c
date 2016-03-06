#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"



void leftRotate(ppRBNode root, pRBNode x) {
    pRBNode y = x->right;    // set y
    x->right = y->left;      // turn y's left subtree into x's right tree

    if(x->right != NULL)
        x->right->parent = x;
    
    y->parent = x->parent;   // link x's parent to y

    if(x->parent == NULL)
        (*root) = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;    // put x on y's left
    x->parent = y;
}


void rightRotate(ppRBNode root, pRBNode x) {
    pRBNode y = x->left;    // set y
    x->left = y->right;     // turn y's right subtree into x's left subtree

    if(x->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;  // link x's parent to y

    if(x->parent == NULL)
        (*root) = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->right = x;    // put x on y's right
    x->parent = y;
}




void insertFixup(ppRBNode root, pRBNode z) {
    while(z != *root && z->parent->color == 'R') {
        pRBNode y;

        // Find z's uncle and store it in y
        if(z->parent == z->parent->parent->left)
            y = z->parent->parent->right;
        else
            y = z->parent->parent->left;

        // If uncle is RED, then
        // a) Change color of parent and uncle as BLACK
        // b) Change color of grandparent as RED
        // c) Move z to grandparent
        if(y != NULL && y->color == 'R') {
            y->color = 'B';
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            z = z->parent->parent;
        }

        // Uncle is BLACK, the four case applied (LL, LR, RL, RR)
        else {
            // Left-Left case
            // a) Change color of parent as BLACK
            // b) Change color of grandparent as RED
            // c) RightRotate grandparent
            if(z->parent == z->parent->parent->left && z == z->parent->left) {
                /*
                char ch = z->parent->color;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                */
                z->parent->color = 'B';
                z->parent->parent->color = 'R';    
                rightRotate(root, z->parent->parent);
                continue;
            }

            // Left-Right case
            // a) Change color of z as BLACK
            // b) Change color of grandparent as RED
            // c) LeftRotate parent, and then RightRotate grandparent
            if(z->parent == z->parent->parent->left && z == z->parent->right) {
                /*
                char ch = z->color;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                */
                z->color = 'B';
                z->parent->parent->color = 'R';
                leftRotate(root, z->parent);  // After this operation, z will be the parent of his parent and the left-child of his grandparent.
                rightRotate(root, z->parent);
                continue;
            }

            // Right-Left case
            // a) Change color of z as BLACK
            // b) Change color of grandparent as RED
            // c) RightRotate parent, and then LeftRotate grandparent
            if(z->parent == z->parent->parent->right && z == z->parent->left) {
                /*
                char ch = z->color;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                */
                z->color = 'B';
                z->parent->parent->color = 'R';
                rightRotate(root, z->parent);  // After this operation, z will be the parent of his parent and the right-child of his grandparent.
                leftRotate(root, z->parent);
                continue;
            }

            // Right-Right case
            // a) Change color of parent as BLACK
            // b) Change color of grandparent as RED
            // c) LeftRotate grandparent 
            if(z->parent == z->parent->parent->right && z == z->parent->right) {
                /*
                char ch = z->parent->color;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                */
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                
                leftRotate(root, z->parent->parent);
                continue;
            }
        }
    }
    (*root)->color = 'B';  // Always keep root BLACK
}





void insertRBNode(ppRBNode root, int data) {
    pRBNode z = (pRBNode)malloc(sizeof(RBNode));
    if(z == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    z->val = data;
    z->left = z->right = z->parent = NULL;

    if(*root == NULL) {
        z->color = 'B';
        (*root) = z;
    } else {
        pRBNode y = NULL, x = (*root);
        while(x != NULL) {
            y = x;
            if(z->val < x->val)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;

        if(y == NULL)
            (*root) = z;
        else if(z->val < y->val)
            y->left = z;
        else
            y->right = z;

        z->color = 'R';
        insertFixup(root, z);
    }
}





pRBNode find(pRBNode root, int val) {
    if(root == NULL || root->val == val)
        return root;
    if(val < root->val)
        return find(root->left, val);
    else
        return find(root->right, val);
}


pRBNode findMin(pRBNode root) {
    pRBNode pMin = root;
    if(root == NULL)
        return NULL;
    while(pMin->left != NULL)
        pMin = pMin->left;
    return pMin;
}


/*
 * Note: 
 * a) Case 1 will turn into Case 2, 3, or 4
 * b) Case 3 is sure to turn into Case 4
 */
void deleteFixup(ppRBNode root, pRBNode x) {
    while(x != (*root) && x->color == 'B') {

        /* Situation 1: x is the left-child of its parent */
        if(x == x->parent->left) {
            pRBNode s = x->parent->right;  // s: the sibling of x
            
            // Case 1: s is RED
            if(s->color == 'R') {  
                s->color = 'B';
                x->parent->color = 'R';
                leftRotate(root, x->parent);
                s = x->parent->right;  // update s (s must be BLACK now, because this node is a child of RED node)
            }

            // Case 2: s is BLACK.  s has two BLACK children
            if(s->left->color == 'B' && s->right->color == 'B') {
                s->color = 'R';
                x = x->parent;
            }

            else {
                // Case 3: s is BLACK. its left-child is RED and its right-child is BLACK
                if(s->right->color == 'B') {
                    s->left->color = 'B';
                    s->color = 'R';
                    rightRotate(root, s);
                    s = x->parent->right;
                }

                //  Case 4: s is BLACK. its right-child is RED
                s->color = x->parent->color;
                x->parent->color = 'B';
                s->right->color = 'B';
                leftRotate(root, x->parent);
                x = (*root);
            }
        }

        /* Situation 2: x is the right-child of its parent */
        else {
            pRBNode s = x->parent->left;  // s: the sibling of x
            
            // Case 1: s is RED
            if(s->color == 'R') {
                s->color = 'B';
                x->parent->color = 'R';
                rightRotate(root, x->parent);
                x = x->parent->left;  // new s
            }

            // Case 2: s is BLACK.  s has two BLACK children
            if(s->right->color == 'B' && s->left->color == 'B') {
                s->color = 'R';
                x = x->parent;
            }
            else {
                // Case 3: s is BLACK. its left-child is BLACK and its right-child is RED
                if(x->left->color == 'B') {
                    s->right->color = 'B';
                    s->color = 'R';
                    leftRotate(root, s);
                    s = x->parent->left;
                }

                // Case 4: s is BLACK. its left-child is RED
                s->color = x->parent->color;
                x->parent->color = 'B';
                s->left->color = 'B';
                rightRotate(root, x->parent);
                x = (*root);
            }
        }
    }
    x->color = 'B';
}



pRBNode BSTdelete(pRBNode root, int val, char *col) {
    pRBNode tmp;
    if(root == NULL)
        return root;
    else if(val < root->val)
        root->left = BSTdelete(root->left, val, col);
    else if(val > root->val)
        root->right = BSTdelete(root->right, val, col);
    else if(root->left && root->right) {  // node with two children
        tmp = findMin(root->right);

        *col = tmp->color;  // remember the original color of successor

        root->val = tmp->val;
        root->right = BSTdelete(root->right, root->val, col);
    } else {  // node with 0 or 1 child
        tmp = root;

        *col = tmp->color;  // remember the original color of successor 

        if(root->left == NULL)
            root = root->right;
        else if(root->right == NULL)
            root = root->left;
        free(tmp);
    }
    return root;
}



void deleteRBNode(ppRBNode root, int val) {
    // If z is the node to be deleted, then the original color of z's successor is: original_color
    char original_color;  

    // 1. Perform standard binary-search-tree deletion
    pRBNode x = BSTdelete(*root, val, &original_color);
    if(x == NULL)
        return ;

    // 2. Fix the RB-tree if necessary
    if(original_color == 'B')
        deleteFixup(root, x);
}




void preOrder(pRBNode root) {
    if(root == NULL) return;
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}


void inOrder(pRBNode root) {
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}




int main()
{
    pRBNode root = NULL;
    insertRBNode(&root, 7);
    insertRBNode(&root, 6);
    insertRBNode(&root, 5);
    insertRBNode(&root, 4);
    insertRBNode(&root, 3);
    insertRBNode(&root, 2);
    insertRBNode(&root, 1);

    /* RBTree: (r represents 'RED')
         
                  6
                 / \
               4r   7
              /  \
             2    5
            / \
          1r  3r
     
    */
    printf("InOrder traversal:\n");
    inOrder(root);
    printf("\n");
    printf("PreOrder traversal:\n");
    preOrder(root);
    printf("\n");


    deleteRBNode(&root, 1);
    deleteRBNode(&root, 2);

    /* After Deletion: 
      
              6
             / \
            4r  7
           / \
          3   5
          
    */

    printf("After deletion:\n");
    printf("InOrder traversal:\n");
    inOrder(root);
    printf("\n");

    printf("PreOrder traversal:\n");
    preOrder(root);
    printf("\n");

    return 0;
}
