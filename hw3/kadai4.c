// 学籍番号： J4220368
// 名前：タンクルンホワルド
#include <stdio.h>

long mod_apm(long, int, long);

int main() {
    long a = 541;
    int p = 1234;
    long m = 1299709;
    printf("Remainder is %ld\n", mod_apm(a, p, m));
    return 0;
}

long mod_apm(long a, int p, long m) {
    if (p == 0) {
        // Base case is when p = 0 and the remainder is 1
        return 1;
    } else {
        long mod_apm_next = mod_apm(a, p-1, m);
        long ans = a * mod_apm_next % m;
        return ans;
    }
}
