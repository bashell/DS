#ifndef _RBTREE_H_
#define _RBTREE_H_

typedef struct RBNode {
  int val;
  char color;
  struct RBNode *left;
  struct RBNode *right;
  struct RBNode *parent;
} RBNode, *pRBNode, **ppRBNode;


/********** Rotation **********/
void leftRotate(ppRBNode root, pRBNode x);
void rightRotate(ppRBNode root, pRBNode x);


/********** Insertion **********/
void insertFixup(ppRBNode root, pRBNode z);
void insertRBNode(ppRBNode root, int data);



/********** Deletion **********/
pRBNode find(pRBNode root, int val);
pRBNode findMin(pRBNode root);
pRBNode BSTdelete(pRBNode root, int val, char *col);
void deleteFixup(ppRBNode root, pRBNode x);
void deleteRBNode(ppRBNode root, int val);


/********** Print **********/
void preOrder(pRBNode root);
void inOrder(pRBNode root);


#endif  /* _RBTREE_H_ */
