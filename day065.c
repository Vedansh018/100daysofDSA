//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int n;
int adj[MAX][MAX];
bool visited[MAX];

bool dfs(int v, int parent) {
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v))
                    return true;
            }
            else if (i != parent) {
                return true;   // cycle found
            }
        }
    }
    return false;
}

int main() {
    int edges, u, v;

    scanf("%d", &n);
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}