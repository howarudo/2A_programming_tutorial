#include <stdio.h>

int main() {
    int n = 158340421;
    for(int i=1; i<=n; i++) {
       if (i*i*i == n) {
            printf("The cube root of %d is %d\n", n, i);
            return 0;
       }
    }
    printf("Cube root was not found\n");
    return 0;
}

// こちらbinary search で解いてみたんですが、long long int にしても mid*mid*mid で negativeの値が出てきた
// （pythonには慣れていますが、C初心者です）
// int main() {
//     int n = 512;
//     int l = 0;
//     int r = n;
//     while (l < r) {
//         int mid = (l + r) / 2;
//         long long int mid_cubed = mid*mid*mid;
//         if (mid_cubed == n) {
//             printf("The cube root of %d is %d\n", n, mid);
//             return 0;
//         }
//         if (mid_cubed < n) {
//             printf("%lld and %d \n", mid_cubed, n);
//             l = mid + 1;
//         } else {
//             r = mid;
//         }
//     }
//     printf("Cube root was not found\n");
//     return 0;
// }
