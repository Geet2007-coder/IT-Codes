#include <stdio.h>
#include "ADT.h"

void printInt(void *value)
{
    printf("%d", *(int *)value);
}

void printFloat(void *value)
{
    printf("%.2f", *(float *)value);
}

void printChar(void *value)
{
    printf("%c", *(char *)value);
}

int main()
{
    ADT a;

    // Integer ADT
    create(&a, 3, sizeof(int));

    int x;

    x = 10;
    set(&a, 0, &x);

    x = 20;
    set(&a, 1, &x);

    x = 30;
    set(&a, 2, &x);

    printf("Integer ADT: ");
    display(&a, printInt);

    destroy(&a);


    // Float ADT
    create(&a, 3, sizeof(float));

    float f;

    f = 1.5;
    set(&a, 0, &f);

    f = 2.5;
    set(&a, 1, &f);

    f = 3.5;
    set(&a, 2, &f);

    printf("Float ADT: ");
    display(&a, printFloat);

    destroy(&a);


    // Character ADT
    create(&a, 3, sizeof(char));

    char c;

    c = 'A';
    set(&a, 0, &c);

    c = 'B';
    set(&a, 1, &c);

    c = 'C';
    set(&a, 2, &c);

    printf("Character ADT: ");
    display(&a, printChar);

    destroy(&a);

    return 0;
}