#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array_stack.h"

#define STACK_MIN_SIZE 5

void stack_init(Stack S, int stack_size) {
    if(stack_size < STACK_MIN_SIZE) {
        fprintf(stderr, "Stack size is too small.\n");
        exit(EXIT_FAILURE);
    }
    int *tmp = (int *)malloc(sizeof(int) * stack_size);
    if(NULL == tmp) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    S->capacity = stack_size;
    S->top = -1;
    S->array = tmp;
}

void stack_destroy(Stack S) {
    stack_clear(S);
}

void stack_push(Stack S, int data) {
    assert(!stack_is_full(S));
    S->array[++S->top] = data;
}

void stack_pop(Stack S) {
    assert(!stack_is_empty(S));
    --S->top;
}

int stack_top(const Stack S) {
    assert(!stack_is_empty(S));
    return S->array[S->top];
}

void stack_clear(Stack S) {
    if(NULL != S) {
        free(S->array);
        free(S);
    }
}

int stack_size(const Stack S) {
    return S->top + 1;
}

int stack_is_full(const Stack S) {
    return S->top == S->capacity - 1;
}

int stack_is_empty(const Stack S) {
    return S->top == -1;
}


int main()
{
    Stack S = (Stack)malloc(sizeof(Stack));
    stack_init(S, 20);
    stack_push(S, 7);
    stack_push(S, 8);
    stack_push(S, 9);
    printf("stack size: %d\tstack top: %d\n", stack_size(S), stack_top(S));
    stack_pop(S);
    printf("stack size: %d\tstack top: %d\n", stack_size(S), stack_top(S));
    stack_pop(S);
    printf("stack size: %d\tstack top: %d\n", stack_size(S), stack_top(S));
    if(!stack_is_full(S))
        printf("Not full now\n");
    if(!stack_is_empty(S))
        printf("Not empty now\n");
    stack_pop(S);
    if(stack_is_empty(S))
        printf("The stack is empty now\n");
    stack_destroy(S);
    return 0;
}
