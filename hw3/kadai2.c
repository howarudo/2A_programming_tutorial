#include <stdio.h>

double sqrt_cf(double);
double K(double, int);

int main() {
    double z = 2;
    double s = sqrt_cf(z);
    printf("%f\n", s);
    return 0;
}

double sqrt_cf(double z) {
    return 1.0 + K(z, 0);
}

double K(double z, int depth) {
    // Once we reach the depth we want, stop.
    if (depth == 10) {
        return z;
    } else {
        // If not at the depth we want, recurse
        return (z - 1.0) / (2.0 + K(z, depth+1));
    }
}
