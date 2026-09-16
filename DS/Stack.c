#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void create(Stack *s, int capacity, int elementSize)
{
    s->capacity = capacity;
    s->elementSize = elementSize;
    s->top = -1;

    s->data = malloc(capacity * elementSize);

    if(s->data == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

int push(Stack *s, void *value)
{
    if(isFull(s))
        return 0;

    char *destination;
    char *source;

    destination = (char *)s->data
                  + (s->top + 1) * s->elementSize;

    source = (char *)value;

    for(int i = 0; i < s->elementSize; i++)
    {
        destination[i] = source[i];
    }

    s->top++;

    return 1;
}

int pop(Stack *s, void *value)
{
    if(isEmpty(s))
        return 0;

    char *source;
    char *destination;

    source = (char *)s->data
             + s->top * s->elementSize;

    destination = (char *)value;

    for(int i = 0; i < s->elementSize; i++)
    {
        destination[i] = source[i];
    }

    s->top--;

    return 1;
}

int peek(Stack *s, void *value)
{
    if(isEmpty(s))
        return 0;

    char *source;
    char *destination;

    source = (char *)s->data
             + s->top * s->elementSize;

    destination = (char *)value;

    for(int i = 0; i < s->elementSize; i++)
    {
        destination[i] = source[i];
    }

    return 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == s->capacity - 1;
}

void display(Stack *s, void (*printFunction)(void *))
{
    if(isEmpty(s))
    {
        printf("Stack is Empty!\n");
        return;
    }

    printf("Stack: ");

    for(int i = s->top; i >= 0; i--)
    {
        void *element = (char *)s->data
                        + i * s->elementSize;

        printFunction(element);
        printf(" ");
    }

    printf("\n");
}

void destroy(Stack *s)
{
    free(s->data);

    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
    s->elementSize = 0;
}