//Problem Statement:Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.
#include <stdio.h>
#define MAX 100
#define INF 99999

int main() {
    int n, m;
    int graph[MAX][MAX];

    scanf("%d %d", &n, &m);

    // Initialize graph with INF
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int visited[MAX] = {0};
    int totalWeight = 0;

    // Start from node 1
    visited[1] = 1;

    for(int count = 1; count < n; count++) {
        int min = INF, u = -1, v = -1;

        // Find minimum edge
        for(int i = 1; i <= n; i++) {
            if(visited[i]) {
                for(int j = 1; j <= n; j++) {
                    if(!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Add edge to MST
        if(u != -1 && v != -1) {
            visited[v] = 1;
            totalWeight += min;
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}