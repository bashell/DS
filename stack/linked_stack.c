#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_stack.h"

void stack_init(Stack *S) {
    S->head = NULL;
    S->size = 0;
}

void stack_destroy(Stack *S) {
    stack_clear(S);
}

void stack_push(Stack *S, int data) {
    pNode p = (pNode)malloc(sizeof(pNode));
    if(NULL == p) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    p->data = data;
    p->next = NULL;
    if(stack_is_empty(S)) {
        S->head = p;
    } else {
        S->head->next = p;
        S->head = p;
    }
    ++S->size;
}

void stack_pop(Stack *S) {
    assert(!stack_is_empty(S));
    pNode p = S->head;
    S->head = S->head->next;
    free(p);
    --S->size;
}

int stack_top(const Stack *S) {
    assert(!stack_is_empty(S));
    return S->head->data;
}

void stack_clear(Stack *S) {
    while(!stack_is_empty(S))
        stack_pop(S);
}

int stack_size(const Stack *S) {
    return S->size;
}

int stack_is_empty(const Stack *S) {
    return NULL == S->head;
}


int main()
{
    Stack *s = (Stack*)malloc(sizeof(Stack*));
    if(NULL == s) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    stack_init(s);
    stack_push(s, 10);
    printf("top element: %d\tsize: %d\n", stack_top(s), stack_size(s));
    stack_push(s, 20);
    printf("top element: %d\tsize: %d\n", stack_top(s), stack_size(s));
    stack_destroy(s);
    if(stack_is_empty(s))
        printf("The stack is empty now!\n");
    return 0;

}
