#include <stdio.h>

#define MAX 100

typedef struct {
    int weight[MAX];
    int value[MAX];
    int n;
    int capacity;
} Knapsack;

// Maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 0/1 Knapsack using Dynamic Programming
int knapsack(Knapsack* k) {
    int dp[MAX][MAX];
    int n = k->n;
    int W = k->capacity;

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (k->weight[i - 1] <= w)
                dp[i][w] = max(k->value[i - 1] + dp[i - 1][w - k->weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W]; // Max profit
}

int main() {
    Knapsack k;

    printf("Enter number of items: ");
    scanf("%d", &k.n);

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < k.n; i++) {
        scanf("%d", &k.weight[i]);
    }

    printf("Enter the values of the items:\n");
    for (int i = 0; i < k.n; i++) {
        scanf("%d", &k.value[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &k.capacity);

    int maxValue = knapsack(&k);
    printf("Maximum value that can be obtained = %d\n", maxValue);

    return 0;
}
