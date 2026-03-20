//Problem Statement:Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#define MAX 100

int main() {
    int n, i;

    scanf("%d", &n);

    int queue[MAX], stack[MAX];
    int front = 0, rear = -1, top = -1;

    // Input queue elements
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[++rear]);
    }

    // Move elements from queue to stack
    while(front <= rear) {
        stack[++top] = queue[front++];
    }

    // Move elements back to queue
    front = 0;
    rear = -1;
    while(top >= 0) {
        queue[++rear] = stack[top--];
    }

    // Print reversed queue
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}