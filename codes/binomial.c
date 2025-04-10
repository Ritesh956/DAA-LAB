#include <stdio.h>

#define MAX 100

typedef unsigned int uint;

uint binomial(uint n, uint k) {
    uint C[MAX][MAX];

    for (uint i = 0; i <= n; i++) {
        for (uint j = 0; j <= (i < k ? i : k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[n][k];
}

int main() {
    uint n = 5, k = 2;
    printf("C(%u, %u) = %u\n", n, k, binomial(n, k));
    return 0;
}
