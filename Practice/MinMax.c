#include <stdio.h>
#include <stdlib.h>



int largest(int *a, int n) {
    if (n == 1)
        return a[0]; 

    int max_el = largest(a, n - 1);
    return (a[n - 1] > max_el) ? a[n - 1] : max_el;

}

int smallest(int *a,int n){
    if(n==1){
        return a[0];
    }
    int min_el=smallest(a,n-1);
    return (a[n-1]<min_el)?a[n-1]:min_el;
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



    // Finding the largest element
    printf("\nLargest element: %d\n", largest(a, n));

    printf("\nSmallest element: %d\n", smallest(a, n));
    return 0;
}