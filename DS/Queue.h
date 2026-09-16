#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

typedef struct Queue Queue;
typedef void (*PrintFunc)(void *);

Queue *createQueue(int capacity, size_t dataSize);
int enqueue(Queue *q, void *data);
int dequeue(Queue *q, void *data);
int peek(Queue *q, void *data);
void display(Queue *q, PrintFunc print);
int isEmpty(Queue *q);
int isFull(Queue *q);
int size(Queue *q);
void destroyQueue(Queue *q);

#endif