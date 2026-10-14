
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

// Node structure
typedef struct Node {
    void *data;
    int type;
    struct Node *next;
} Node;

// Stack structure
typedef struct {
    Node *top;
} Stack;

// Data types
enum {
    INT = 1,
    FLOAT,
    CHAR,
    STRING
};

// Initialize stack
void initStack(Stack *s) {
    s->top = NULL;
}

// Generic push function
void push(Stack *s, void *value, int type) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    int size;

    switch (type) {
        case INT:
            size = sizeof(int);
            break;

        case FLOAT:
            size = sizeof(float);
            break;

        case CHAR:
            size = sizeof(char);
            break;

        case STRING:
            size = strlen((char *)value) + 1;
            break;

        default:
            printf("Invalid data type!\n");
            free(newNode);
            return;
    }

    newNode->data = malloc(size);

    if (newNode->data == NULL) {
        printf("Memory allocation failed!\n");
        free(newNode);
        return;
    }

    if (type == STRING)
        strcpy((char *)newNode->data, (char *)value);
    else
        memcpy(newNode->data, value, size);

    newNode->type = type;

    newNode->next = s->top;
    s->top = newNode;

    printf("Element pushed successfully!\n");
}

// Pop function
void pop(Stack *s) {
    if (s->top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    Node *temp = s->top;

    printf("Popped element: ");

    switch (temp->type) {
        case INT:
            printf("%d\n", *(int *)temp->data);
            break;

        case FLOAT:
            printf("%.2f\n", *(float *)temp->data);
            break;

        case CHAR:
            printf("%c\n", *(char *)temp->data);
            break;

        case STRING:
            printf("%s\n", (char *)temp->data);
            break;
    }

    s->top = temp->next;

    free(temp->data);
    free(temp);
}

// Display function
void display(Stack *s) {
    if (s->top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    Node *temp = s->top;

    printf("\n--- Stack (Top to Bottom) ---\n");

    while (temp != NULL) {
        switch (temp->type) {
            case INT:
                printf("%d\n", *(int *)temp->data);
                break;

            case FLOAT:
                printf("%.2f\n", *(float *)temp->data);
                break;

            case CHAR:
                printf("%c\n", *(char *)temp->data);
                break;

            case STRING:
                printf("%s\n", (char *)temp->data);
                break;
        }

        temp = temp->next;
    }

    printf("-----------------------------\n");
}

// Free all memory
void freeStack(Stack *s) {
    while (s->top != NULL) {
        Node *temp = s->top;
        s->top = temp->next;

        free(temp->data);
        free(temp);
    }
}

// Main function
int main() {
    Stack s;
    int choice, valueInt;
    float valueFloat;
    char valueChar;
    char valueString[MAX];

    initStack(&s);

    while (1) {
        printf("\n===== GENERIC STACK ADT =====\n");
        printf("1. Push Integer\n");
        printf("2. Push Float\n");
        printf("3. Push Character\n");
        printf("4. Push String\n");
        printf("5. Pop\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (choice) {

            case 1:
                printf("Enter integer: ");
                scanf("%d", &valueInt);
                push(&s, &valueInt, INT);
                break;

            case 2:
                printf("Enter float: ");
                scanf("%f", &valueFloat);
                push(&s, &valueFloat, FLOAT);
                break;

            case 3:
                printf("Enter character: ");
                scanf(" %c", &valueChar);
                push(&s, &valueChar, CHAR);
                break;

            case 4:
                printf("Enter string: ");
                scanf(" %199[^\n]", valueString);
                push(&s, valueString, STRING);
                break;

            case 5:
                pop(&s);
                break;

            case 6:
                display(&s);
                break;

            case 7:
                freeStack(&s);
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    freeStack(&s);
    return 0;
}