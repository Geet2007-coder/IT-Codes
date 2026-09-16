#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

struct Queue
{
    void *data;

    int capacity;
    int front;
    int rear;
    int count;

    size_t dataSize;
};

/* Create Queue */
Queue *createQueue(int capacity, size_t dataSize)
{
    Queue *q;

    q = (Queue *)malloc(sizeof(Queue));

    if (q == NULL)
        return NULL;

    q->data = malloc(capacity * dataSize);

    if (q->data == NULL)
    {
        free(q);
        return NULL;
    }

    q->capacity = capacity;
    q->dataSize = dataSize;

    q->front = 0;
    q->rear = -1;
    q->count = 0;

    return q;
}

/* Check Empty */
int isEmpty(Queue *q)
{
    return q->count == 0;
}

/* Check Full */
int isFull(Queue *q)
{
    return q->count == q->capacity;
}

/* Return Size */
int size(Queue *q)
{
    return q->count;
}

/* Enqueue */
int enqueue(Queue *q, void *data)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return 0;
    }

    q->rear = (q->rear + 1) % q->capacity;

    memcpy((char *)q->data + q->rear * q->dataSize,
           data,
           q->dataSize);

    q->count++;

    return 1;
}

/* Dequeue */
int dequeue(Queue *q, void *data)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return 0;
    }

    memcpy(data,
           (char *)q->data + q->front * q->dataSize,
           q->dataSize);

    q->front = (q->front + 1) % q->capacity;

    q->count--;

    return 1;
}

/* Peek */
int peek(Queue *q, void *data)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return 0;
    }

    memcpy(data,
           (char *)q->data + q->front * q->dataSize,
           q->dataSize);

    return 1;
}

/* Display */
void display(Queue *q, PrintFunc print)
{
    int i;
    int index;

    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    for (i = 0; i < q->count; i++)
    {
        index = (q->front + i) % q->capacity;

        print((char *)q->data + index * q->dataSize);
        printf(" ");
    }

    printf("\n");
}

/* Destroy Queue */
void destroyQueue(Queue *q)
{
    if (q != NULL)
    {
        free(q->data);
        free(q);
    }
}