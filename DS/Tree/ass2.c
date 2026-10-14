
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* addNode(struct Node *root, int x) {
    if (root == NULL) {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (x < root->data)
        root->left = addNode(root->left, x);
    else if (x > root->data)
        root->right = addNode(root->right, x);

    return root;
}

struct Node* search(struct Node *root, int target) {
    if (root == NULL || root->data == target)
        return root;

    if (target < root->data)
        return search(root->left, target);

    return search(root->right, target);
}

int findMin(struct Node *root) {
    while (root->left != NULL)
        root = root->left;

    return root->data;
}

int findMax(struct Node *root) {
    while (root->right != NULL)
        root = root->right;

    return root->data;
}

void inorder(struct Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node *root = NULL;
    struct Node *result;
    int n, x, target, i;

    printf("How many nodes? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        root = addNode(root, x);
    }

    printf("BST in sorted order: ");
    inorder(root);

    if (root != NULL) {
        printf("\nMinimum = %d", findMin(root));
        printf("\nMaximum = %d\n", findMax(root));

        printf("Enter target to search: ");
        scanf("%d", &target);

        result = search(root, target);

        if (result != NULL)
            printf("Element found\n");
        else
            printf("Element not found\n");
    } else {
        printf("Tree is empty\n");
    }

    return 0;
}
