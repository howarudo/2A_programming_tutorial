// 学籍番号： J4220368
// 名前：タンクルンホワルド
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void eig(double[2][2], double*, double*, double*, double*);

int main() {
    double val1;
    double val2;
    double vec1[2];
    double vec2[2];

    double mat[2][2] = {{1, 5}, {6, 2}};
    // BY GIVING VAR NAME OF ARRAY AS INPUT, IT WILL ALREADY USE THE ADDRESS OF FIRST ELEMENT
    eig(mat, &val1, &val2, vec1, vec2);
    printf("[%f, %f]\n", mat[0][0], mat[0][1]);
    printf("[%f, %f]\n", mat[1][0], mat[1][1]);
    printf("egienvalue = %f, eigenvector = (%f, %f)\n", val1, vec1[0], vec1[1]);
    printf("egienvalue = %f, eigenvector = (%f, %f)\n", val2, vec2[0], vec2[1]);
    return 0;
}

void eig(double mat[2][2], double *val1, double *val2, double *vec1, double *vec2) {
    double a = mat[0][0], b = mat[0][1], c = mat[1][0], d = mat[1][1];
    // root(a^2 - 2ad + 4bc + d^2) as root_val
    double root_val = sqrt(a*a - 2*a*d + 4*b*c + d*d);
    *val1 = 0.5 * (a + d - root_val);
    *val2 = 0.5 * (a + d + root_val);
    // for arrays, we can just use array_name[index] to access the values inside memory. no need for *
    vec1[0] = -1 * (root_val - a + d) / (2 * c);
    vec1[1] = 1;
    vec2[0] = -1 * (-1 * root_val - a + d) / (2 * c);
    vec2[1] = 1;
}
