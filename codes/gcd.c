#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int middleSchoolGCD(int a, int b) {
    int gcd = 1;
    for (int i = 2; i <= min(a, b); i++) {
        while (a % i == 0 && b % i == 0) {
            gcd *= i;
            a /= i;
            b /= i;
        }
    }
    return gcd;
}

int main() {
    int a = 18, b = 24;
    printf("GCD: %d\n", middleSchoolGCD(a, b));
    return 0;
}