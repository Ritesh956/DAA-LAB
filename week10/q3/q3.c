#include <stdio.h>

#define MAX_N 100  // Maximum number of items
#define MAX_W 100  // Maximum weight capacity

#define max(a, b) ((a) > (b) ? (a) : (b))

void knapsack(int n, int W, int w[], int val[]) {
    int a[MAX_N + 1][MAX_W + 1] = {0};  // DP table
    int kn[MAX_N], m = 0;  // Array to store selected items

    // Bottom-up DP approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < w[i])  // If the weight is more than capacity
                a[i][j] = a[i - 1][j];
            else
                a[i][j] = max(a[i - 1][j], val[i] + a[i - 1][j - w[i]]);
        }
    }

    // Printing the DP table (optional)
    printf("\nDP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Find which items are included in the knapsack
    int i = n, j = W;
    while (i > 0 && j > 0) {
        if (a[i][j] != a[i - 1][j]) {  // If item `i` was included
            kn[m++] = i;
            j -= w[i];  // Reduce weight
        }
        i--;
    }

    // Print selected items
    printf("\nSelected items (1-based index): ");
    for (i = m - 1; i >= 0; i--)
        printf("%d ", kn[i]);
    printf("\n");

    printf("\nMaximum Value: %d\n", a[n][W]);
}

int main() {
    int n, W;
    int w[MAX_N], val[MAX_N];

    // Taking input from user
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter maximum weight capacity of knapsack: ");
    scanf("%d", &W);

    printf("Enter weights of items:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter values of items:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);

    knapsack(n, W, w, val);
    return 0;
}
