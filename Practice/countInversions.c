#include <stdio.h>

// Recursive function to count inversion pairs
int countInversions(int arr[], int n) {
    // Base Case: Single element has no inversions
    if (n <= 1)
        return 0;

    // Recursive call to count inversions in n-1 elements
    int invCount = countInversions(arr, n - 1);

    // Count inversions where the last element is smaller than any previous elements
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[n - 1]) {
            invCount++;
            printf("{%d %d} \n",arr[i],arr[n-1]);
        }
    }

    return invCount;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int inversionCount = countInversions(arr, n);

    printf("Total Inversion Pairs: %d\n", inversionCount);
    return 0;
}