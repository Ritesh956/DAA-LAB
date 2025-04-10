#include <stdio.h>

#define MAX 10
#define INF 99999  // Representing "infinity"

typedef struct {
    int matrix[MAX][MAX];
    int vertices;
} Graph;

// Input graph
void inputGraph(Graph* g) {
    printf("Enter number of vertices: ");
    scanf("%d", &g->vertices);

    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            scanf("%d", &g->matrix[i][j]);
        }
    }
}

// Display matrix
void displayMatrix(int dist[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd's Algorithm
void floyd(Graph* g, int dist[MAX][MAX]) {
    int n = g->vertices;

    // Initialize distance matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = g->matrix[i][j];

    // Floyd’s logic
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
    Graph g;
    int dist[MAX][MAX];

    inputGraph(&g);

    printf("\nInput Graph (Adjacency Matrix):\n");
    displayMatrix(g.matrix, g.vertices);

    floyd(&g, dist);

    printf("\nAll Pairs Shortest Path Matrix (Floyd's Algorithm):\n");
    displayMatrix(dist, g.vertices);

    return 0;
}
