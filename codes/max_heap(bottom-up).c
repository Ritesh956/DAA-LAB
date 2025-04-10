#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int size;
} MaxHeap;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify down from a given index
void heapifyDown(MaxHeap* h, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->size && h->arr[left] > h->arr[largest])
        largest = left;
    if (right < h->size && h->arr[right] > h->arr[largest])
        largest = right;

    if (largest != index) {
        swap(&h->arr[index], &h->arr[largest]);
        heapifyDown(h, largest);
    }
}

// Build heap from array
void buildHeap(MaxHeap* h) {
    for (int i = (h->size - 1) / 2; i >= 0; i--) {
        heapifyDown(h, i);
    }
}

void displayHeap(MaxHeap* h) {
    printf("Max Heap (array): ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap heap;

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
