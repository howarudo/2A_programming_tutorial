// 学籍番号： J4220368
// 名前：タンクルンホワルド
#include <stdio.h>
#include <stdlib.h>

struct monomial {
    int c;
    int n;
};

struct monomial *construct_monomial(int c, int n) {
    // malloc to hold storage for monomial
    struct monomial *m1 = (struct monomial*) malloc(sizeof(struct monomial));
    m1 -> c = c;
    m1 -> n = n;
    return m1;
}

void diff_monomial(struct monomial *m) {
    // new coefficient will be old * power of x
    // x's power will decrement by 1
    m -> c = (m -> c) * (m -> n);
    m -> n = m -> n -1;
}

void print_monomial(struct monomial *m) {
    printf("%d*x^%d\n", m->c, m->n);
}

int main() {
    struct monomial *m1;
    m1 = construct_monomial(-4, 10);
    print_monomial(m1);
    diff_monomial(m1);
    print_monomial(m1);
    return 0;
}
