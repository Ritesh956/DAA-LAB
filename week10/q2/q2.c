#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

// Floyd-Warshall Algorithm to find shortest paths
void shortestPath(int graph[50][50], int v) {
    int sp[50][50];

    // Copy graph to shortest path matrix
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            sp[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                opcount++;
                // Check to prevent integer overflow when using 'infinity' (999)
                if (sp[i][k] != 999 && sp[k][j] != 999 && sp[i][k] + sp[k][j] < sp[i][j]) {
                    sp[i][j] = sp[i][k] + sp[k][j];
                }
            }
        }
    }

    // Print the shortest path matrix
    printf("\nShortest Path Matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (sp[i][j] == 999) {
                printf("INF ");  // Print "INF" for better readability
            } else {
                printf("%d ", sp[i][j]);
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int v, graph[50][50];

    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the distance matrix of the directed graph (999 for infinity):\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    shortestPath(graph, v);
    printf("\nOpcount = %d\n", opcount);

    return 0;
}
