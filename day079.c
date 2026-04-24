//Problem Statement:Find shortest distances from source vertex in a weighted graph with non-negative weights.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 99999

// Structure for adjacency list
struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Node* adj[MAX];

// Min heap structure
struct HeapNode {
    int vertex, dist;
};

struct HeapNode heap[MAX];
int size = 0;

// Swap function
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while(i && heap[i].dist < heap[(i-1)/2].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1, right = 2*i + 2;

    if(left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if(right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void push(int v, int d) {
    heap[size].vertex = v;
    heap[size].dist = d;
    heapifyUp(size);
    size++;
}

// Extract min
struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
        adj[i] = NULL;

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // undirected
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    for(int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[source] = 0;
    push(source, 0);

    while(size > 0) {
        struct HeapNode curr = pop();
        int u = curr.vertex;

        struct Node* temp = adj[u];
        while(temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Output distances
    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}