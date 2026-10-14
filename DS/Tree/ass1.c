
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createTree() {
    int x;
    struct Node *newNode;

    printf("\nEnter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    newNode = malloc(sizeof(struct Node));
    newNode->data = x;

    printf("Left child of %d:\n", x);
    newNode->left = createTree();

    printf("Right child of %d:\n", x);
    newNode->right = createTree();

    return newNode;
}

void preorder(struct Node *root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node *root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node *root;

    root = createTree();

    printf("\nPreorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n");
    return 0;
}
