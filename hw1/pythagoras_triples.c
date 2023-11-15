#include <stdio.h>

int main() {
    // a^2 = (c-b)*(c+b)の性質を利用
    for (int a=1; a<=20; a++){
        int aSquare = a*a;
        // Find factor of a^2, small*big == a^2
        for (int small=1; small < aSquare/2; small++){
            if ((aSquare)%small == 0) {
                int big = aSquare/small;
                // Check if small and big has same parity
                if ((big%2)==(small%2)) {
                    int c = (small+big)/2;
                    int b = (big-small)/2;
                    // Check inequality to make sure no duplicate triplets
                    if (a < b && b < c) {
                        printf("%d^2 + %d^2 = %d^2\n", a, b, c);
                    }
                }
            }
        }
    }
    return 0;
}
