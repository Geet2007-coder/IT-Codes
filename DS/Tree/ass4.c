
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

void postorder(struct Node *root) {
    struct Node *s1[100], *s2[100];
    int top1 = -1, top2 = -1;
    struct Node *p;

    if (root == NULL) return;

    s1[++top1] = root;

    while (top1 != -1) {
        p = s1[top1--];
        s2[++top2] = p;

        if (p->left != NULL)
            s1[++top1] = p->left;

        if (p->right != NULL)
            s1[++top1] = p->right;
    }

    while (top2 != -1)
        printf("%d ", s2[top2--]->data);
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Postorder: ");
    postorder(root);

    return 0;
}
