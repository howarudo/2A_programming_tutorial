// 学籍番号： J4220368
// 名前：タンクルンホワルド
#include <stdio.h>

double legendre(int n, double x);

int main() {
    double v = legendre(16, 0.5);
    printf("%f\n", v);
    v = legendre(32, 0.7);
    printf("%f\n", v);
    return 0;
}

double legendre(int n, double x) {
    // Base cases for legendre recursion is n=0 and n=1
    if (n == 0) {
        return 1.0;
    } else if (n == 1) {
        return x;
    } else {
        // Case a double because we are dividing by n which is an int
        double p_n = (double) ((2*n-1) * x * legendre(n-1, x) - (n-1) * legendre(n-2, x))/n;
        return p_n;
    }
}
