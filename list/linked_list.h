#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int val;
    struct Node *next;
} *pNode;

void show_list(pNode pList);
pNode create_head_insert();
pNode create_tail_insert();
pNode create_sort_insert();
void insert_node(pNode *ppList, int val);
void delete_node(pNode *ppList, int val);
void delete_common(pNode *ppList);
void link_reverse(pNode *ppList);
pNode find_mid(pNode pList);
pNode link_merge(pNode *ppList1, pNode *ppList2);
int has_circle(pNode pList);
pNode get_intersection_node(pNode pList1, pNode pList2);

#endif  // LINKED_LIST_H
