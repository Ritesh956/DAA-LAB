#include <stdio.h>
#define MAXFACTORS 1024

typedef struct {
    int size;
    int factor[MAXFACTORS+1];
    int exp[MAXFACTORS+1];
} Fact;

void factorize(int x, Fact *f) {
    int i, c, k = 0;
    for (i = 2; i <= x; i++) {
        c = 0;
        while (x % i == 0) {
            c++;
            x /= i;
        }
        if (c > 0) {
            f->factor[k] = i;
            f->exp[k] = c;
            k++;
        }
    }
    f->size = k;
}

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }
    return result;
}

int gcd(int a, int b) {
    Fact fact_a, fact_b;
    int i, j, result = 1;

    factorize(a, &fact_a);
    factorize(b, &fact_b);

    for (i = 0; i < fact_a.size; i++) {
        for (j = 0; j < fact_b.size; j++) {
            if (fact_a.factor[i] == fact_b.factor[j]) {
                int exp_min = (fact_a.exp[i] < fact_b.exp[j]) ? fact_a.exp[i] : fact_b.exp[j];
                result *= power(fact_a.factor[i], exp_min);  // Use the power function
            }
        }
    }

    return result;
}

int main() {
    int a, b;
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &a, &b);

    printf("The GCD of %d and %d is: %d\n", a, b, gcd(a, b));

    return 0;
}
