// 学籍番号： J4220368
// 名前：タンクルンホワルド
#include <stdio.h>

int isAlphabet(char a);
int isGregor(char *a);
int isSamsa(char *a);
int isGod(char *a);

int main(int argc, char **argv) {
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");

    // Check if there are exactly 2 files and if they work
    if (argc != 3) {
        printf("Need 2 file names!\n");
        return 1;
    }
    if (fp1 == NULL) {
        printf("Cannot read first file!\n");
        return 1;
    }
    if (fp2 == NULL) {
        printf("Cannot write second file!\n");
        return 1;
    }

    // Didnt know how to code this so i asked classmates!
    int char_num = 0;
    int character;
    char char_array[10000];
    //
    while ((character = getc(fp1)) != EOF) {
        char_array[char_num] = (char) character;
        char_num++;
    }

    // Capitalize logic
    // 1. First letter or followed after a punctuation
    //  ex. start of senetence. is a -> Start .. . Is..
    // 2. After a quotation
    //  ex. "hello, i am" -> "Hello, i am"
    // 3. First person I (i followed by space of ')
    //  ex. soemthing i have -> something I have
    // 4. A person's name
    //  ex. gregor samsa -> Gregor Samsa
    // 5. God

    for (int i = 0; i < char_num; i++) {
        char e = char_array[i];
        if (isAlphabet(e) == 1){
            if ((i >= 2 && char_array[i-1]==' ' && (char_array[i-2]=='.' || char_array[i-2]=='!' || char_array[i-2]=='?'))|| i==0) {
                char_array[i] = e - 32;
            }
            if (i>=1 && char_array[i-1]=='\"'){
                char_array[i] = e - 32;
            }
            if (e == 'i' && (i < char_num - 1 && (char_array[i+1]==' ' || char_array[i+1]=='\''))){
                char_array[i] = 'I';
            }
            if (isGregor(&char_array[i])==1 || isSamsa(&char_array[i])==1 || isGod(&char_array[i])==1){
                char_array[i] = e - 32;
            }
        }
        printf("%c", char_array[i]);
        putc(char_array[i], fp2);
    }
}

int isAlphabet(char a) {
    int res = a >= 'a' && a <= 'z' ? 1 : 0;
    return res;
}

int isGregor(char *a) {
    // check if it is gregor
    char *p = a;
    char *key = "gregor";
    int length = 0;
    while (*p && *key && *p==*key) {
        key++, p++, length++;
    }
    return (length == 6 ? 1 : 0);
}

int isGod(char *a) {
    // check if word is God
    char *p = a;
    char *key = "god";
    int length = 0;
    while (*p && *key && *p==*key) {
        key++, p++, length++;
    }
    return (length == 3 ? 1 : 0);
}

int isSamsa(char *a) {
    // check if word is samsa
    char *p = a;
    char *key = "samsa";
    int length = 0;
    while (*p && *key && *p==*key) {
        key++, p++, length++;
    }
    return (length == 5 ? 1 : 0);
}
