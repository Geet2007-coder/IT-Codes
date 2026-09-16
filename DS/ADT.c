#include <stdio.h>
#include <stdlib.h>
#include "ADT.h"

void create(ADT *a, int size, int elementSize)
{
    a->size = size;
    a->elementSize = elementSize;

    a->data = malloc(size * elementSize);
}

void set(ADT *a, int index, void *value)
{
    char *destination;
    char *source;

    destination = (char *)a->data + index * a->elementSize;
    source = (char *)value;

    for(int i = 0; i < a->elementSize; i++)
    {
        destination[i] = source[i];
    }
}

void get(ADT *a, int index, void *value)
{
    char *source;
    char *destination;

    source = (char *)a->data + index * a->elementSize;
    destination = (char *)value;

    for(int i = 0; i < a->elementSize; i++)
    {
        destination[i] = source[i];
    }
}

void display(ADT *a, void (*printFunction)(void *))
{
    for(int i = 0; i < a->size; i++)
    {
        void *element = (char *)a->data + i * a->elementSize;
        printFunction(element);
        printf(" ");
    }

    printf("\n");
}

void destroy(ADT *a)
{
    free(a->data);

    a->data = NULL;
    a->size = 0;
    a->elementSize = 0;
}