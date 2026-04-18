//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize indegree
    for(int i = 0; i < n; i++)
        indegree[i] = 0;

    // Calculate indegree
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Enqueue vertices with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order:\n");

    while(front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for(int i = 0; i < n; i++) {
            if(adj[v][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    return 0;
}