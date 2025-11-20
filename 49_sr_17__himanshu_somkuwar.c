#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void BFS(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    front = rear = -1;

    visited[start] = 1;
    enqueue(start);

    printf("BFS starting from %d: ", start);
    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

void DFSUtil(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            DFSUtil(i, n);
        }
    }
}

void DFS(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS starting from %d: ", start);
    DFSUtil(start, n);
    printf("\n");
}

int main() {
    int n, e, u, v, start;

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
        adj[v][u] = 1; // for undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start, n);
    DFS(start, n);

    return 0;
}

