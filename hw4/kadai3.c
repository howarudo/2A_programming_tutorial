// 学籍番号： J4220368
// 名前：タンクルンホワルド
#include <stdio.h>

void reverse(char *s);

int main() {
    char s[] = "hello";
    reverse(s);
    printf("%s\n", s);
    return 0;
}

void reverse(char *s) {
    int sizeOfArray = 0;
    // 配列の長さを探す
    while (s[sizeOfArray] != '\0') {
        sizeOfArray++;
    }
    int l = 0, r = sizeOfArray-1;
    //　swap from beginnning to end in order
    while (l < r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
}
