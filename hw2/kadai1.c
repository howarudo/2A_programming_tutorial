// 学籍番号： J4220368
// 名前：タンクルンホワルド
#include <stdio.h>
#include <math.h>

int main () {
    double sum = 6 * pow(log(2), 2);
    for (int i=1; i<16; i++) {
        sum = sum + 6/(pow(i, 2) * pow(2, i-1));
        printf("For i=%d, estimate of pi=%lf\n", i, sqrt(sum));
    }
    return 0;
}
