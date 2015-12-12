#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

#define SIZE 5
#define MOD 100

void show_list(pNode pList) {
    while(pList) {
        printf("%d ", pList -> val);
        pList = pList -> next;
    }
    printf("\n");
}

/*
 * 头插法
 */
pNode create_head_insert() {
    int cnt;
    pNode pHead = (pNode)malloc(sizeof(struct Node));
    if(NULL == pHead) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    srand((unsigned)time(NULL));
    for(cnt = 0; cnt != SIZE; ++cnt) {
        if(0 == cnt) {
            pHead -> val = rand() % MOD;
        } else {
            pNode pCur = (pNode)malloc(sizeof(struct Node));
            if(NULL == pCur) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            pCur -> val = rand() % MOD;
            pCur -> next = pHead;
            pHead = pCur;
        }
    }
    return pHead;
}

/*
 * 尾插法
 */
pNode create_tail_insert() {
    int cnt;
    pNode pHead = (pNode)malloc(sizeof(struct Node));
    if(NULL == pHead) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    pNode pTail = pHead;
    srand((unsigned)time(NULL));
    for(cnt = 0; cnt != SIZE; ++cnt) {
        if(0 == cnt) {
            pHead -> val = rand() % MOD;
        } else {
            pNode pCur = (pNode)malloc(sizeof(struct Node));
            if(NULL == pCur) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            pCur -> val = rand() % MOD;
            pTail -> next = pCur;
            pTail = pCur;
        }
    }
    return pHead;
}

/*
 * 有序插入
 */
pNode create_sort_insert() {
    int cnt;
    pNode pHead = (pNode)malloc(sizeof(struct Node));
    if(NULL == pHead) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    srand((unsigned)time(NULL));
    for(cnt = 0; cnt != SIZE; ++cnt) {
        if(0 == cnt) {
            pHead -> val = rand() % MOD;
        } else {
            pNode pCur = (pNode)malloc(sizeof(struct Node));
            pCur -> val = rand() % MOD;
            pNode pPre = NULL;
            pNode pWork = pHead;
            while(pWork) {
                if(pCur -> val > pWork -> val) {
                    pPre = pWork;
                    pWork = pWork -> next;
                } else {
                    break;
                }
            }
            if(NULL == pPre) {
                pCur -> next = pHead;
                pHead = pCur;
            } else {
                pCur -> next = pPre -> next;
                pPre -> next = pCur;
            }
        }
    }
    return pHead;
}

/*
 * 向链表添加结点(假定原链表元素升序, 插入后链表仍升序)
 */
void insert_node(pNode *ppList, int val) {
    pNode pPre = NULL, pWork = *ppList;
    pNode pCur = (pNode)malloc(sizeof(struct Node));
    if(NULL == pCur) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    pCur -> val = val;
    while(pWork) {
        if(pCur -> val > pWork -> val) {
            pPre = pWork;
            pWork = pWork -> next;
        } else {
            break;
        }
    }
    if(NULL == pPre) {
        pCur -> next = *ppList;
        *ppList = pCur;
    } else {
        pCur -> next = pPre -> next;
        pPre -> next = pCur;
    }
}

/*
 * 从链表中删除所有给定值的结点
 */
void delete_node(pNode *ppList, int val) {
    pNode pPre = NULL, pTmp = NULL, pCur = *ppList;
    while(pCur) {
        if(pCur -> val != val) {
            pPre = pCur;
            pCur = pCur -> next;
        } else {
            if(NULL == pPre) {
                pTmp = *ppList;
                *ppList = (*ppList) -> next;
                pCur = pCur -> next;
                free(pTmp);
            } else {
                pTmp = pCur;
                pPre -> next = pCur -> next;
                pCur = pCur -> next;
                free(pTmp);
            }
        }
    }
}

/*
 * 删除链表中所有的重复元素
 */
void delete_common(pNode *ppList) {
    pNode pCur = *ppList;
    while(pCur) {
        delete_node(&(pCur -> next), pCur -> val);  // 删除后面所有与本结点具有相同值的结点
        pCur = pCur -> next;
    }
}

/*
 * 链表翻转
 */
void link_reverse(pNode *ppList) {
    if(NULL == *ppList || NULL == (*ppList) -> next)
        return ;
    pNode pPre = NULL, pCur = *ppList, pNext = (*ppList) -> next;
    while(pNext) {
        pCur -> next = pPre;
        pPre = pCur;
        pCur = pNext;
        pNext = pNext -> next;
    }
    pCur -> next = pPre;
    *ppList = pCur;
}

/*
 * 查找中间元素(返回指向中间结点的指针)
 */
pNode find_mid(pNode pList) {
    if(NULL == pList || NULL == pList -> next)
        return pList;
    pNode pSlow = pList, pFast = pList -> next;
    while(pFast -> next) {
        pSlow = pSlow -> next;
        pFast = pFast -> next;
        if(NULL == pFast -> next)
            break;
        pFast = pFast -> next;
    }
    return pSlow;
}

/*
 * 链表合并(假定两个链表不相交, 且分别升序)
 */
pNode link_merge(pNode *ppList1, pNode *ppList2) {
    if(NULL == *ppList1)
        return *ppList2;
    if(NULL == *ppList2)
        return *ppList1;
    pNode pHead = NULL, pCur = NULL;
    if((*ppList1) -> val <= (*ppList2) -> val) {
        pHead = *ppList1;
        *ppList1 = (*ppList1) -> next;
    } else {
        pHead = *ppList2;
        *ppList2 = (*ppList2) -> next;
    }

    pCur = pHead;
    while(*ppList1 && *ppList2) {
        if((*ppList1) -> val <= (*ppList2) -> val) {
            pCur -> next = *ppList1;
            *ppList1 = (*ppList1) -> next;
        } else {
            pCur -> next = *ppList2;
            *ppList2 = (*ppList2) -> next;
        }
        pCur = pCur -> next;
    }
    pCur -> next = (*ppList1 ? *ppList1 : *ppList2);
    return pHead;
}

/*
 * 判断是否有环 (return value: 0->no, 1->yes)
 */
int has_circle(pNode pList) {
    if(NULL == pList || NULL == pList -> next)
        return 0;
    pNode pSlow = pList, pFast = pList -> next;
    while(pFast != pSlow) {
        if(NULL == pFast || NULL == pFast -> next)
            return 0;
        pFast = pFast -> next -> next;
        pSlow = pSlow -> next;
    }
    return 1;
}

/*
 * 返回指向相交链表的相交起始结点的指针
 */
pNode get_intersection_node(pNode pList1, pNode pList2) {
    pNode pHead1 = pList1, pHead2 = pList2;
    int len1 = 0, len2 = 0;
    while(pHead1) {
        ++len1;
        pHead1 = pHead1 -> next;
    }
    while(pHead2) {
        ++len2;
        pHead2 = pHead2 -> next;
    }
    while(len1 > len2) {
        --len1;
        pList1 = pList1 -> next;
    }
    while(len2 > len1) {
        --len2;
        pList2 = pList2 -> next;
    }
    while(pList1 != pList2) {
        pList1 = pList1 -> next;
        pList2 = pList2 -> next;
    }
    return pList1;
}

int main()
{
    /*
    pNode list1 = create_head_insert();
    show_list(list1);
    pNode list2 = create_tail_insert();
    show_list(list2);
    pNode list3 = create_sort_insert();
    show_list(list3);
    */

    /*
    pNode list = create_sort_insert();
    insert_node(&list, 20);
    show_list(list);
    delete_node(&list, 20);
    show_list(list);
    */

    /*
    pNode list = create_sort_insert();
    insert_node(&list, 20);
    insert_node(&list, 20);
    insert_node(&list, 30);
    insert_node(&list, 30);
    show_list(list);
    delete_common(&list);
    show_list(list);
    */

    /*
    pNode list = create_sort_insert();
    show_list(list);
    link_reverse(&list);
    show_list(list);
    */
    
    /*
    pNode list = create_sort_insert();
    show_list(list);
    printf("%d\n", find_mid(list3) -> val);
    */

    /*
    pNode list1 = create_sort_insert();
    sleep(1);
    pNode list2 = create_sort_insert();
    show_list(list1);
    show_list(list2);
    show_list(link_merge(&list1, &list2));
    */
    
    pNode list = create_sort_insert();
    if(has_circle(list))
        printf("Linked list has a circle!\n");
    else
        printf("Linked list has no circle!\n");
    
    return 0;
}
