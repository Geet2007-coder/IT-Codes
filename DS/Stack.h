#ifndef STACK_H
#define STACK_H

typedef struct
{
    void *data;
    int top;
    int capacity;
    int elementSize;
} Stack;

void create(Stack *s, int capacity, int elementSize);

int push(Stack *s, void *value);
int pop(Stack *s, void *value);
int peek(Stack *s, void *value);

int isEmpty(Stack *s);
int isFull(Stack *s);

void display(Stack *s, void (*printFunction)(void *));
void destroy(Stack *s);

#endif