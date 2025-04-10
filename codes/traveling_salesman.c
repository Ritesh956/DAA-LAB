#include <stdio.h>
#include <limits.h>

int a[10][10], v[10], n, minCost = INT_MAX;

void tsp(int i, int count, int cost, int s) {
    if (count == n && a[i][s]) {
        if (cost + a[i][s] < minCost)
            minCost = cost + a[i][s];
        return;
    }

    for (int j = 0; j < n; j++) {
        if (!v[j] && a[i][j]) {
            v[j] = 1;
            tsp(j, count + 1, cost + a[i][j], s);
            v[j] = 0;
        }
    }
}

int main() {
    n = 4;
    int j1, j2;
    int input[4][4] = {{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
    for (j1 = 0; j1 < n; j1++)
        for (j2 = 0; j2 < n; j2++)
            a[j1][j2] = input[j1][j2];

    v[0] = 1;
    tsp(0, 1, 0, 0);
    printf("TSP Min Cost = %d", minCost);
    return 0;
}