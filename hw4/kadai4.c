// 学籍番号： J4220368
// 名前：タンクルンホワルド
#include <stdio.h>
void uppercase(char *s);

int main() {
    char s[] = "hello world";
    uppercase(s);
    printf("%s\n", s);
    return 0;
}

void uppercase(char *s) {
    int sizeOfArray = 0;
    // 配列の長さを探す
    while (s[sizeOfArray] != '\0') {
        sizeOfArray++;
    }
    while (sizeOfArray > 0) {
        // check if it is a blankspace or not
        if (s[sizeOfArray - 1] != ' '){
            // because 'a' - 'A' is constant, we can just minus this to make a character capital
            s[sizeOfArray - 1] = s[sizeOfArray-1] - 'a' + 'A';
        }
        sizeOfArray--;
    }
}
