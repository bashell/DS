#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

struct StackRecord;
typedef struct StackRecord *Stack;

struct StackRecord {
    int capacity;
    int top;
    int *array;
};

void stack_init(Stack S, int stack_size);
void stack_destroy(Stack S);
void stack_push(Stack S, int data);
void stack_pop(Stack S);
int stack_top(const Stack S);
void stack_clear(Stack S);
int stack_size(const Stack S);
int stack_is_full(const Stack S);
int stack_is_empty(const Stack S);

#endif  // ARRAY_STACK_H
