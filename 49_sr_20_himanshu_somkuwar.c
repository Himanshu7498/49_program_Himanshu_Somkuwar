#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];

void topologicalSort(int n) {
    int queue[MAX], front = 0, rear = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    printf("Topological Order: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    if (count != n)
        printf("\nGraph is not a DAG (cycle detected)\n");
    else
        printf("\n");
}

int main() {
    int n, e, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) meaning u->v:\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    topologicalSort(n);

    return 0;
}

