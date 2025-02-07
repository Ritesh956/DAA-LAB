// dfs.c
#include "dfs.h"

// Define global variables (memory is allocated here)
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int popOrder[MAX_VERTICES];
int popIndex = 0;

// DFS function implementation
void DFS(int vertex, int n) {
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }

    // Store in pop order for topological sorting
    popOrder[popIndex++] = vertex;
}
