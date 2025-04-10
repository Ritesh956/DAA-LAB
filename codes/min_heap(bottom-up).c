#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int size;
} MinHeap;

// Swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify-down (for building the heap)
void heapifyDown(MinHeap* h, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->size && h->arr[left] < h->arr[smallest])
        smallest = left;
    if (right < h->size && h->arr[right] < h->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&h->arr[index], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

// Build heap from array (bottom-up)
void buildHeap(MinHeap* h) {
    for (int i = (h->size - 1) / 2; i >= 0; i--) {
        heapifyDown(h, i);
    }
}

// Display heap
void displayHeap(MinHeap* h) {
    printf("Min Heap (array): ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main() {
    MinHeap heap;
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &heap.size);
    printf("Enter %d values:\n", heap.size);
    for (int i = 0; i < heap.size; i++) {
        scanf("%d", &heap.arr[i]);
    }

    buildHeap(&heap);
    displayHeap(&heap);
    return 0;
}
