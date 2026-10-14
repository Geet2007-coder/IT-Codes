
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

// Supported data types
enum { INT = 1, FLOAT, DOUBLE, CHAR, STRING };

// Queue node
typedef struct Node {
    void *data;
    int type;
    struct Node *next;
} Node;

// Queue structure
typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Initialize queue
void initialize(Queue *q) {
    q->front = q->rear = NULL;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == NULL;
}

// Insert element
int enqueue(Queue *q, void *value, int type) {
    Node *newNode;
    size_t size;

    switch (type) {
        case INT:    size = sizeof(int); break;
        case FLOAT:  size = sizeof(float); break;
        case DOUBLE: size = sizeof(double); break;
        case CHAR:   size = sizeof(char); break;
        case STRING: size = strlen((char *)value) + 1; break;
        default:
            printf("Invalid data type!\n");
            return 0;
    }

    newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    newNode->data = malloc(size);
    if (newNode->data == NULL) {
        free(newNode);
        printf("Memory allocation failed!\n");
        return 0;
    }

    if (type == STRING)
        strcpy((char *)newNode->data, (char *)value);
    else
        memcpy(newNode->data, value, size);

    newNode->type = type;
    newNode->next = NULL;

    if (q->rear == NULL)
        q->front = q->rear = newNode;
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Element inserted successfully!\n");
    return 1;
}

// Display one element
void printElement(Node *p) {
    switch (p->type) {
        case INT:
            printf("%d", *(int *)p->data);
            break;
        case FLOAT:
            printf("%g", (double)*(float *)p->data);
            break;
        case DOUBLE:
            printf("%g", *(double *)p->data);
            break;
        case CHAR:
            printf("%c", *(char *)p->data);
            break;
        case STRING:
            printf("%s", (char *)p->data);
            break;
    }
}

// Delete front element
void dequeue(Queue *q) {
    Node *temp;

    if (isEmpty(q)) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    temp = q->front;
    printf("Deleted element: ");
    printElement(temp);
    printf("\n");

    q->front = temp->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp->data);
    free(temp);
}

// Display all elements
void display(Queue *q) {
    Node *temp = q->front;

    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nFRONT -> ");

    while (temp != NULL) {
        printElement(temp);
        printf(" -> ");
        temp = temp->next;
    }

    printf("REAR\n");
}

// Display front element
void peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element: ");
    printElement(q->front);
    printf("\n");
}

// Free all memory
void destroyQueue(Queue *q) {
    while (q->front != NULL) {
        Node *temp = q->front;
        q->front = temp->next;
        free(temp->data);
        free(temp);
    }

    q->rear = NULL;
}

// Main function
int main() {
    Queue q;
    int choice, i;
    int iv;
    float fv;
    double dv;
    char cv, sv[MAX];

    initialize(&q);

    while (1) {
        printf("\n===== GENERIC QUEUE ADT =====\n");
        printf("1. Enqueue Integer\n");
        printf("2. Enqueue Float\n");
        printf("3. Enqueue Double\n");
        printf("4. Enqueue Character\n");
        printf("5. Enqueue String\n");
        printf("6. Dequeue\n");
        printf("7. Peek (Front Element)\n");
        printf("8. Display\n");
        printf("9. Check Empty\n");
        printf("10. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter integer: ");
                if (scanf("%d", &iv) == 1)
                    enqueue(&q, &iv, INT);
                else
                    printf("Invalid input!\n");
                break;

            case 2:
                printf("Enter float: ");
                if (scanf("%f", &fv) == 1)
                    enqueue(&q, &fv, FLOAT);
                else
                    printf("Invalid input!\n");
                break;

            case 3:
                printf("Enter double: ");
                if (scanf("%lf", &dv) == 1)
                    enqueue(&q, &dv, DOUBLE);
                else
                    printf("Invalid input!\n");
                break;

            case 4:
                printf("Enter character: ");
                if (scanf(" %c", &cv) == 1)
                    enqueue(&q, &cv, CHAR);
                else
                    printf("Invalid input!\n");
                break;

            case 5:
                printf("Enter string: ");
                if (scanf(" %199[^\n]", sv) == 1)
                    enqueue(&q, sv, STRING);
                else
                    printf("Invalid input!\n");
                break;

            case 6:
                dequeue(&q);
                break;

            case 7:
                peek(&q);
                break;

            case 8:
                display(&q);
                break;

            case 9:
                if (isEmpty(&q))
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;

            case 10:
                destroyQueue(&q);
                printf("Memory freed. Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    destroyQueue(&q);
    return 0;
}
