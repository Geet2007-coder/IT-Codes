
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

enum { INT = 1, FLOAT, DOUBLE, CHAR, STRING };

typedef struct Node {
    void *data;
    int type;
    struct Node *next;
} Node;

Node *head = NULL;

// Create a node of any supported type
Node *createNode(void *value, int type) {
    Node *newNode = malloc(sizeof(Node));
    size_t size;

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    switch (type) {
        case INT:    size = sizeof(int); break;
        case FLOAT:  size = sizeof(float); break;
        case DOUBLE: size = sizeof(double); break;
        case CHAR:   size = sizeof(char); break;
        case STRING: size = strlen((char *)value) + 1; break;
        default:
            free(newNode);
            printf("Invalid data type!\n");
            return NULL;
    }

    newNode->data = malloc(size);

    if (newNode->data == NULL) {
        free(newNode);
        printf("Memory allocation failed!\n");
        return NULL;
    }

    if (type == STRING)
        strcpy((char *)newNode->data, (char *)value);
    else
        memcpy(newNode->data, value, size);

    newNode->type = type;
    newNode->next = NULL;

    return newNode;
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

// Insert at beginning
void insertBeginning(void *value, int type) {
    Node *newNode = createNode(value, type);

    if (newNode == NULL) return;

    newNode->next = head;
    head = newNode;

    printf("Inserted successfully!\n");
}

// Insert at end
void insertEnd(void *value, int type) {
    Node *newNode = createNode(value, type);
    Node *temp;

    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Inserted successfully!\n");
}

// Delete from beginning
void deleteBeginning() {
    Node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    printf("Deleted: ");
    printElement(temp);
    printf("\n");

    head = head->next;
    free(temp->data);
    free(temp);
}

// Delete from end
void deleteEnd() {
    Node *temp, *prev = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    if (temp->next == NULL) {
        head = NULL;
    } else {
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
    }

    printf("Deleted: ");
    printElement(temp);
    printf("\n");

    free(temp->data);
    free(temp);
}

// Display list
void display() {
    Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("HEAD -> ");

    while (temp != NULL) {
        printElement(temp);
        printf(" -> ");
        temp = temp->next;
    }

    printf("NULL\n");
}

// Search by value and type
void search(void *value, int type) {
    Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->type == type) {
            int found = 0;

            switch (type) {
                case INT:
                    found = (*(int *)temp->data == *(int *)value);
                    break;
                case FLOAT:
                    found = (*(float *)temp->data == *(float *)value);
                    break;
                case DOUBLE:
                    found = (*(double *)temp->data == *(double *)value);
                    break;
                case CHAR:
                    found = (*(char *)temp->data == *(char *)value);
                    break;
                case STRING:
                    found = (strcmp((char *)temp->data,
                                    (char *)value) == 0);
                    break;
            }

            if (found) {
                printf("Element found at position %d\n", pos);
                return;
            }
        }

        temp = temp->next;
        pos++;
    }

    printf("Element not found!\n");
}

// Free entire list
void freeList() {
    Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;

        free(temp->data);
        free(temp);
    }
}

// Read a value and insert/search using the selected type
void readValue(int type, int operation) {
    int iv;
    float fv;
    double dv;
    char cv, sv[MAX];

    printf("Enter value: ");

    switch (type) {
        case INT:
            if (scanf("%d", &iv) != 1) {
                printf("Invalid input!\n");
                return;
            }
            if (operation == 1) insertBeginning(&iv, type);
            else if (operation == 2) insertEnd(&iv, type);
            else search(&iv, type);
            break;

        case FLOAT:
            if (scanf("%f", &fv) != 1) {
                printf("Invalid input!\n");
                return;
            }
            if (operation == 1) insertBeginning(&fv, type);
            else if (operation == 2) insertEnd(&fv, type);
            else search(&fv, type);
            break;

        case DOUBLE:
            if (scanf("%lf", &dv) != 1) {
                printf("Invalid input!\n");
                return;
            }
            if (operation == 1) insertBeginning(&dv, type);
            else if (operation == 2) insertEnd(&dv, type);
            else search(&dv, type);
            break;

        case CHAR:
            if (scanf(" %c", &cv) != 1) {
                printf("Invalid input!\n");
                return;
            }
            if (operation == 1) insertBeginning(&cv, type);
            else if (operation == 2) insertEnd(&cv, type);
            else search(&cv, type);
            break;

        case STRING:
            if (scanf(" %199[^\n]", sv) != 1) {
                printf("Invalid input!\n");
                return;
            }
            if (operation == 1) insertBeginning(sv, type);
            else if (operation == 2) insertEnd(sv, type);
            else search(sv, type);
            break;
    }
}

int main() {
    int choice, type;

    while (1) {
        printf("\n===== GENERIC LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Search\n");
        printf("7. Exit\n");

        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
            case 2:
            case 6:
                printf("Select type: 1.Int 2.Float 3.Double "
                       "4.Char 5.String\n");
                printf("Enter type: ");

                if (scanf("%d", &type) != 1)
                    goto finish;

                if (type < INT || type > STRING) {
                    printf("Invalid type!\n");
                    break;
                }

                readValue(type, choice);
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 7:
                goto finish;

            default:
                printf("Invalid choice!\n");
        }
    }

finish:
    freeList();
    printf("Memory freed. Exiting...\n");
    return 0;
}
