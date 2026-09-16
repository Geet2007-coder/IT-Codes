#include <stdio.h>
#include "Stack.h"

/* Functions to print different data types */

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
    Stack s;
    int choice, type, capacity;

    printf("Choose Data Type:\n");
    printf("1. Integer\n");
    printf("2. Float\n");
    printf("3. Character\n");
    printf("Enter choice: ");
    scanf("%d", &type);

    printf("Enter Stack Capacity: ");
    scanf("%d", &capacity);

    /* Create stack according to datatype */

    if (type == 1)
        create(&s, capacity, sizeof(int));

    else if (type == 2)
        create(&s, capacity, sizeof(float));

    else if (type == 3)
        create(&s, capacity, sizeof(char));

    else
    {
        printf("Invalid data type!\n");
        return 0;
    }

    do
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Is Empty\n");
        printf("6. Is Full\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        /* PUSH */
        if (choice == 1)
        {
            if (type == 1)
            {
                int x;
                printf("Enter integer: ");
                scanf("%d", &x);

                if (push(&s, &x))
                    printf("Element pushed successfully.\n");
                else
                    printf("Stack Overflow!\n");
            }

            else if (type == 2)
            {
                float x;
                printf("Enter float: ");
                scanf("%f", &x);

                if (push(&s, &x))
                    printf("Element pushed successfully.\n");
                else
                    printf("Stack Overflow!\n");
            }

            else
            {
                char x;
                printf("Enter character: ");
                scanf(" %c", &x);

                if (push(&s, &x))
                    printf("Element pushed successfully.\n");
                else
                    printf("Stack Overflow!\n");
            }
        }

        /* POP */
        else if (choice == 2)
        {
            if (type == 1)
            {
                int x;

                if (pop(&s, &x))
                    printf("Popped: %d\n", x);
                else
                    printf("Stack Underflow!\n");
            }

            else if (type == 2)
            {
                float x;

                if (pop(&s, &x))
                    printf("Popped: %.2f\n", x);
                else
                    printf("Stack Underflow!\n");
            }

            else
            {
                char x;

                if (pop(&s, &x))
                    printf("Popped: %c\n", x);
                else
                    printf("Stack Underflow!\n");
            }
        }

        /* PEEK */
        else if (choice == 3)
        {
            if (type == 1)
            {
                int x;

                if (peek(&s, &x))
                    printf("Top element: %d\n", x);
                else
                    printf("Stack is Empty!\n");
            }

            else if (type == 2)
            {
                float x;

                if (peek(&s, &x))
                    printf("Top element: %.2f\n", x);
                else
                    printf("Stack is Empty!\n");
            }

            else
            {
                char x;

                if (peek(&s, &x))
                    printf("Top element: %c\n", x);
                else
                    printf("Stack is Empty!\n");
            }
        }

        /* DISPLAY */
        else if (choice == 4)
        {
            if (type == 1)
                display(&s, printInt);

            else if (type == 2)
                display(&s, printFloat);

            else
                display(&s, printChar);
        }

        /* IS EMPTY */
        else if (choice == 5)
        {
            if (isEmpty(&s))
                printf("Stack is Empty.\n");
            else
                printf("Stack is Not Empty.\n");
        }

        /* IS FULL */
        else if (choice == 6)
        {
            if (isFull(&s))
                printf("Stack is Full.\n");
            else
                printf("Stack is Not Full.\n");
        }

        /* EXIT */
        else if (choice == 7)
        {
            printf("Exiting...\n");
        }

        else
        {
            printf("Invalid choice!\n");
        }

    } while (choice != 7);

    destroy(&s);

    return 0;
}