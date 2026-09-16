#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

/* Print functions */

void printInt(void *data)
{
    printf("%d", *(int *)data);
}

void printFloat(void *data)
{
    printf("%.2f", *(float *)data);
}

void printDouble(void *data)
{
    printf("%.2lf", *(double *)data);
}

void printChar(void *data)
{
    printf("%c", *(char *)data);
}

void printString(void *data)
{
    printf("%s", *(char **)data);
}

int main()
{
    int type;
    int capacity;
    int choice;

    printf("===== GENERIC QUEUE ADT =====\n");

    printf("\nSelect Data Type:\n");
    printf("1. Integer\n");
    printf("2. Float\n");
    printf("3. Double\n");
    printf("4. Character\n");
    printf("5. String\n");

    printf("Enter choice: ");
    scanf("%d", &type);

    printf("Enter queue capacity: ");
    scanf("%d", &capacity);

    Queue *q;

    /* Integer */
    if (type == 1)
    {
        int value, result;
        q = createQueue(capacity, sizeof(int));

        while (1)
        {
            printf("\n--- Queue Menu ---\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Peek\n");
            printf("4. Display\n");
            printf("5. Size\n");
            printf("6. Is Empty\n");
            printf("7. Is Full\n");
            printf("8. Exit\n");

            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", &value);
                    enqueue(q, &value);
                    break;

                case 2:
                    if (dequeue(q, &result))
                        printf("Deleted: %d\n", result);
                    break;

                case 3:
                    if (peek(q, &result))
                        printf("Front: %d\n", result);
                    break;

                case 4:
                    display(q, printInt);
                    break;

                case 5:
                    printf("Size: %d\n", size(q));
                    break;

                case 6:
                    printf(isEmpty(q) ? "Queue is empty\n" :
                                         "Queue is not empty\n");
                    break;

                case 7:
                    printf(isFull(q) ? "Queue is full\n" :
                                       "Queue is not full\n");
                    break;

                case 8:
                    destroyQueue(q);
                    return 0;

                default:
                    printf("Invalid choice\n");
            }
        }
    }

    /* Float */
    else if (type == 2)
    {
        float value, result;

        q = createQueue(capacity, sizeof(float));

        while (1)
        {
            printf("\n--- Float Queue ---\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Peek\n");
            printf("4. Display\n");
            printf("5. Size\n");
            printf("6. Exit\n");

            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("Enter value: ");
                    scanf("%f", &value);
                    enqueue(q, &value);
                    break;

                case 2:
                    if (dequeue(q, &result))
                        printf("Deleted: %.2f\n", result);
                    break;

                case 3:
                    if (peek(q, &result))
                        printf("Front: %.2f\n", result);
                    break;

                case 4:
                    display(q, printFloat);
                    break;

                case 5:
                    printf("Size: %d\n", size(q));
                    break;

                case 6:
                    destroyQueue(q);
                    return 0;

                default:
                    printf("Invalid choice\n");
            }
        }
    }

    /* Double */
    else if (type == 3)
    {
        double value, result;

        q = createQueue(capacity, sizeof(double));

        while (1)
        {
            printf("\n--- Double Queue ---\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Peek\n");
            printf("4. Display\n");
            printf("5. Size\n");
            printf("6. Exit\n");

            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("Enter value: ");
                    scanf("%lf", &value);
                    enqueue(q, &value);
                    break;

                case 2:
                    if (dequeue(q, &result))
                        printf("Deleted: %.2lf\n", result);
                    break;

                case 3:
                    if (peek(q, &result))
                        printf("Front: %.2lf\n", result);
                    break;

                case 4:
                    display(q, printDouble);
                    break;

                case 5:
                    printf("Size: %d\n", size(q));
                    break;

                case 6:
                    destroyQueue(q);
                    return 0;

                default:
                    printf("Invalid choice\n");
            }
        }
    }

    /* Character */
    else if (type == 4)
    {
        char value, result;

        q = createQueue(capacity, sizeof(char));

        while (1)
        {
            printf("\n--- Character Queue ---\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Peek\n");
            printf("4. Display\n");
            printf("5. Size\n");
            printf("6. Exit\n");

            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("Enter character: ");
                    scanf(" %c", &value);
                    enqueue(q, &value);
                    break;

                case 2:
                    if (dequeue(q, &result))
                        printf("Deleted: %c\n", result);
                    break;

                case 3:
                    if (peek(q, &result))
                        printf("Front: %c\n", result);
                    break;

                case 4:
                    display(q, printChar);
                    break;

                case 5:
                    printf("Size: %d\n", size(q));
                    break;

                case 6:
                    destroyQueue(q);
                    return 0;

                default:
                    printf("Invalid choice\n");
            }
        }
    }

    /* String */
    else if (type == 5)
    {
        char value[100];
        char *result;

        /*
         * Queue stores pointers to strings.
         * Each string gets its own dynamically allocated memory.
         */
        q = createQueue(capacity, sizeof(char *));

        while (1)
        {
            printf("\n--- String Queue ---\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Peek\n");
            printf("4. Display\n");
            printf("5. Size\n");
            printf("6. Exit\n");

            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("Enter string: ");
                    scanf("%99s", value);

                    result = (char *)malloc(strlen(value) + 1);
                    strcpy(result, value);

                    enqueue(q, &result);
                    break;

                case 2:
                    if (dequeue(q, &result))
                    {
                        printf("Deleted: %s\n", result);
                        free(result);
                    }
                    break;

                case 3:
                    if (peek(q, &result))
                        printf("Front: %s\n", result);
                    break;

                case 4:
                    display(q, printString);
                    break;

                case 5:
                    printf("Size: %d\n", size(q));
                    break;

                case 6:
                    destroyQueue(q);
                    return 0;

                default:
                    printf("Invalid choice\n");
            }
        }
    }

    else
    {
        printf("Invalid data type\n");
    }

    return 0;
}