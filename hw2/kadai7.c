
#include <stdio.h>
#include <math.h>

int is_prime(int);

int main() {
    int max = 100;
    for (int i = 4; i <= max; i = i + 2) {
        for (int a = 2; a <= i / 2; a++) {
            // Check if a and i-a is prime. If it is, print and break out of the first for loop
            if (is_prime(a) == 1 & is_prime(i-a) == 1) {
                printf("%d = %d + %d\n", i, a, i-a);
                break;
            }
        }
    }
}

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
