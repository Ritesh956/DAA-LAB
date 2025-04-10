#include <stdio.h>
#include <limits.h>

int costMatrix[10][10], used[10], n, min = INT_MAX;

void assign(int i, int cost) {
    if (i == n) {
        if (cost < min)
            min = cost;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            used[j] = 1;
            assign(i + 1, cost + costMatrix[i][j]);
            used[j] = 0;
        }
    }
}

int main() {
    n = 4;
    int input[4][4] = {{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            costMatrix[i][j] = input[i][j];

    assign(0, 0);
    printf("Job Assignment Min Cost = %d", min);
    return 0;
}