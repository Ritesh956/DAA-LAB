#include <stdio.h>

#define MAX 10

typedef struct {
    int matrix[MAX][MAX];
    int vertices;
} Graph;

// Function to input the adjacency matrix
void inputGraph(Graph* g) {
    printf("Enter number of vertices: ");
    scanf("%d", &g->vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            scanf("%d", &g->matrix[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Warshall's Algorithm
void warshall(Graph* g, int closure[MAX][MAX]) {
    int n = g->vertices;

    // Initialize closure matrix same as input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            closure[i][j] = g->matrix[i][j];
        }
    }

    // Apply Warshall's Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (closure[i][j] || (closure[i][k] && closure[k][j]))
                    closure[i][j] = 1;
            }
        }
    }
}

int main() {
    Graph g;
    int closure[MAX][MAX];

    inputGraph(&g);

    printf("\nInput Adjacency Matrix:\n");
    displayMatrix(g.matrix, g.vertices);

    warshall(&g, closure);

    printf("\nTransitive Closure (Reachability Matrix):\n");
    displayMatrix(closure, g.vertices);

    return 0;
}
