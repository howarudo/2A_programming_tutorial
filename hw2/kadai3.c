// 学籍番号： J4220368
// 名前：タンクルンホワルド
#include <stdio.h>
#include <math.h>

int is_prime(int);

int main() {
    for (int i = 2; i<=1000; i++) {
        if (is_prime(i) == 1) {
            printf("%d is prime\n", i);
        }
    }
    return 0;
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
}
