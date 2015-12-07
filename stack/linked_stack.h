#ifndef LINKED_STACK_H
#define LINKED_STACK_H

typedef struct Node {
    int data;
    struct Node *next;
} *pNode;

typedef struct {
    pNode head;
    int size;
} Stack;

void stack_init(Stack *S);
void stack_destroy(Stack *S);
void stack_push(Stack *S, int data);
void stack_pop(Stack *S);
int stack_top(const Stack *S);
void stack_clear(Stack *S);
int stack_size(const Stack *S);
int stack_is_empty(const Stack *S);

#endif  // LINKED_STACK_H
