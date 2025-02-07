// WAP to find gcd using consecutive integer checking method and analyse the time efficiency

#include <stdio.h>

int gcd(int a, int b) {
    int smaller = (a < b) ? a : b;
    for (int i = smaller; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 1;
}

int main() {
    int a, b;
    printf("Enter 1st integers: ");
    scanf("%d", &a);
    printf("Enter 2nd integers: ");
    scanf("%d", &b);
    printf("The GCD is ");
    printf("%d\n", gcd(a, b));
    return 0;
}
