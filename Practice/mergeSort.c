#include<stdio.h>
#include<stdlib.h>

void mergesort(int *a, int low, int high) {
    int mid = (low + high) / 2;
    if (low < high) {
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int *a, int low, int mid, int high) {
    int firstindex = low;
    int secondindex = mid + 1;
    int temp[100];
    int k = 0;

    // Merge two subarrays into temp[]
    while (firstindex <= mid && secondindex <= high) {
        if (a[firstindex] < a[secondindex]) {
            temp[k++] = a[firstindex++];
        } else {
            temp[k++] = a[secondindex++];
        }
    }

    // If any elements remain in the left subarray
    while (firstindex <= mid) {
        temp[k++] = a[firstindex++];
    }

    // If any elements remain in the right subarray
    while (secondindex <= high) {
        temp[k++] = a[secondindex++];
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < k; i++) {
        a[low + i] = temp[i];
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    mergesort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}