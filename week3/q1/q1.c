#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n, int *op_count, int *swap_count) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*op_count)++;
            if (arr[j] > arr[j + 1]) {
                (*swap_count)++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 1000;
    int arr[n];
    int op_count = 0, swap_count = 0;
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    
    printf("Unsorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, n, &op_count, &swap_count);
    
    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nTotal comparisons (operations): %d\n", op_count);
    printf("Total swaps: %d\n", swap_count);
    
    return 0;
}
