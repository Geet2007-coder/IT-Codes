#ifndef ADT_H
#define ADT_H

typedef struct
{
    void *data;
    int size;
    int elementSize;
} ADT;

void create(ADT *a, int size, int elementSize);
void set(ADT *a, int index, void *value);
void get(ADT *a, int index, void *value);
void display(ADT *a, void (*printFunction)(void *));
void destroy(ADT *a);

#endif