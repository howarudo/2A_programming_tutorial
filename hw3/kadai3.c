// 学籍番号： J4220368
// 名前：タンクルンホワルド
#include <stdio.h>
#include <math.h>

double f(double);
double dfdx(double);
double newton(double);

int main() {
    double x0 = 1.0;
    double solution = newton(x0);
    printf("Solution is %f\n", solution);
    return 0;
}

double f(double x) {
    return exp(x) + x;
}

double dfdx(double x) {
    return exp(x) + 1.0;
}

double newton(double x) {
    // Calculate the next x
    double x_next =  x - f(x) / dfdx(x);
    if (fabs(x_next - x) < 0.0001) {
        // If the next step is close to current x then return x
        return x;
    } else {
        // If it is far, continue the newton alg
        return newton(x_next);
    }
}
