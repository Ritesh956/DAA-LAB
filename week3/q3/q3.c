#include <stdio.h>
#include <stdlib.h>

int isSubsetSum(int set[], int n, int sum) {
    if (sum == 0) return 1;
    if (n == 0 && sum != 0) return 0;
    if (set[n-1] > sum) return isSubsetSum(set, n-1, sum);
    return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum - set[n-1]);
}

int partition(int set[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += set[i];
    if (sum % 2 != 0) return 0;
    return isSubsetSum(set, n, sum / 2);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int set[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &set[i]);
    
    if (partition(set, n)) printf("The set can be partitioned into two subsets with equal sum.\n");
    else printf("The set cannot be partitioned into two subsets with equal sum.\n");
    
    return 0;
}
