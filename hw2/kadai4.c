
#include <stdio.h>
#include <math.h>

int is_prime(int);

int main() {
    double product = 6;
    for (int p=2; p<=10000; p++) {
        if (is_prime(p) == 1) {
            // If p is prime, then multiply product by (p^2)/(p^2-1).
            // This is the reciprocal of (1-1/i^2)
            product = product * pow(p, 2) / (pow(p, 2) - 1);
            printf("Until p=%d, pi=%lf\n", p, sqrt(product));
        }
    }
    printf("pi = %lf\n", sqrt(product));
    return 0;
};


int is_prime(int n) {
    // Check for possible divisors until sqrt(n)
    int max = sqrt(n);
    for (int i = 2; i <= max; i++) {
        if (n % i == 0) {
            // If divisible -> not a prime
            return 0;
        }
    }
    // If not divisible from the numbers above, it IS a prime
    return 1;
};
