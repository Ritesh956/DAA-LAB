#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int pushOrder[MAX_VERTICES];
int popOrder[MAX_VERTICES];
int pushCount = 0, popCount = 0;

void dfs(int vertex, int n) {
    visited[vertex] = 1;
    pushOrder[pushCount++] = vertex;
    printf("Pushed: %d\n", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }

    popOrder[popCount++] = vertex;
    printf("Popped: %d\n", vertex);
}

int main() {
    int n, edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS starting from vertex 0:\n");
    dfs(0, n);

    printf("Push order: ");
    for (int i = 0; i < pushCount; i++) {
        printf("%d ", pushOrder[i]);
    }
    printf("\n");

    printf("Pop order: ");
    for (int i = 0; i < popCount; i++) {
        printf("%d ", popOrder[i]);
    }
    printf("\n");

    return 0;
}
