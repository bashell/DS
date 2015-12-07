#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    int data;
    struct Node *next;
} *pNode;

typedef struct {
    pNode head;
    pNode tail;
    int size;
} Queue;

void queue_init(Queue *Q);
void queue_destroy(Queue *Q);
void queue_push(Queue *Q, int data);
void queue_pop(Queue *Q);
int queue_top(const Queue *Q);
void queue_clear(Queue *Q);
int queue_size(const Queue *Q);
int queue_is_empty(const Queue *Q);

#endif  // QUEUE_H
