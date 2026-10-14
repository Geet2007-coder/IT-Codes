
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) {
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

void inorder(struct Node *root) {
    struct Node *stack[100];
    int top = -1;
    struct Node *p = root;

    while (p != NULL || top != -1) {
        while (p != NULL) {
            stack[++top] = p;
            p = p->left;
        }

        p = stack[top--];
        printf("%d ", p->data);

        p = p->right;
    }
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder: ");
    inorder(root);

    return 0;
}
