//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
};

struct Pair {
    struct Node* node;
    int hd;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct Pair queue[MAX];
    int front = 0, rear = 0;

    int map[200][200];   // store values
    int count[200] = {0}; // count per hd

    queue[rear++] = (struct Pair){root, 100}; // offset to avoid negative index

    while (front < rear) {
        struct Pair temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd;

        map[hd][count[hd]++] = node->data;

        if (node->left)
            queue[rear++] = (struct Pair){node->left, hd - 1};

        if (node->right)
            queue[rear++] = (struct Pair){node->right, hd + 1};
    }

    for (int i = 0; i < 200; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", map[i][j]);
            printf("\n");
        }
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    verticalOrder(root);

    return 0;
}