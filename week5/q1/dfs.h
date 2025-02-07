#ifndef DFS_H
#define DFS_H

#include <stdio.h>

#define MAX_VERTICES 100

// Declare global variables (do NOT define them here)
extern int graph[MAX_VERTICES][MAX_VERTICES];
extern int visited[MAX_VERTICES];
extern int popOrder[MAX_VERTICES];
extern int popIndex;

// Function declarations
void DFS(int vertex, int n);

#endif // DFS_H
