#include <stdio.h>

int floorSqrt(int n) {
    int low = 0, high = n, mid, sqrt;

    while (low <= high) {
        mid = (low + high) / 2;
        if (mid * mid == n) {
            return mid;
        } else if (mid * mid < n) {
            low = mid + 1;
            sqrt = mid;
        } else {
            high = mid - 1;
        }
    }

    return sqrt;
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Floor of the square root of %d is %d\n", n, floorSqrt(n));

    return 0;
}
