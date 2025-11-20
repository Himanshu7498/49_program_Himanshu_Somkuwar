#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX], disc[MAX], low[MAX], parent[MAX];
int timeCounter, isBiConnected;

void DFS(int u, int n) {
    int children = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                DFS(v, n);

                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                if (parent[u] == -1 && children > 1)
                    isBiConnected = 0;
                if (parent[u] != -1 && low[v] >= disc[u])
                    isBiConnected = 0;
            }
            else if (v != parent[u]) {
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
            }
        }
    }
}

int main() {
    int n, e, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    timeCounter = 0;
    isBiConnected = 1;

    DFS(0, n);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            isBiConnected = 0;
            break;
        }
    }

    if (isBiConnected)
        printf("Graph is Bi-Connected\n");
    else
        printf("Graph is NOT Bi-Connected\n");

    return 0;
}

