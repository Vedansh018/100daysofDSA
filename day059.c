//Construct a binary tree from given inorder and postorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

int postIndex;

// create node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// search in inorder
int search(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

// build tree
struct node* buildTree(int inorder[], int postorder[], int start, int end) {
    if(start > end)
        return NULL;

    int rootValue = postorder[postIndex--];
    struct node* root = newNode(rootValue);

    if(start == end)
        return root;

    int index = search(inorder, start, end, rootValue);

    // build right first
    root->right = buildTree(inorder, postorder, index + 1, end);
    root->left = buildTree(inorder, postorder, start, index - 1);

    return root;
}

// preorder traversal
void preorder(struct node* root) {
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    postIndex = n - 1;

    struct node* root = buildTree(inorder, postorder, 0, n-1);

    preorder(root);

    return 0;
}