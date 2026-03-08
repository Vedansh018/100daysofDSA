#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, k, i, x;
    struct Node *head = NULL, *temp = NULL, *newNode, *prev = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = createNode(x);

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    if(head == NULL || k == 0) {
        temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    int length = 1;
    temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    temp->next = head; 

    k = k % length;
    int steps = length - k;

    temp = head;
    for(i = 1; i < steps; i++) {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}