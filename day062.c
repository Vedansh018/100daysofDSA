//Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Array of adjacency lists
    struct Node* adj[n];
    
    // Initialize lists
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    // Read edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add v to u's list
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Add u to v's list (undirected graph)
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // Print adjacency list
    for(int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while(temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}