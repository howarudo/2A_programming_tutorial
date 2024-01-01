
#include <stdio.h>

int gcd(int, int);

int main() {
    int max = 200;
    for (int i=1; i<max; i++) {
        for (int j=i; j<max; j++) {
            // At this stage if i and j are not coprime, there is no need to run the next for loop
            if (gcd(i, j) == 1) {
                for (int k=j; k<max; k++) {
                    if (i*i + j*j == k*k) {
                        printf("%d^2 + %d^2 = %d^2\n", i, j, k);
                    }
                }
            }
        }
    }
};

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
